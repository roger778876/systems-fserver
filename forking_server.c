#include "pipe_networking.h"
#include <signal.h>

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("luigi");
    exit(0);
  }
}

int main() {
  while (1) {
    int from_client = server_setup();
    int parent = fork();
    if (parent) {
      remove("luigi");
      close(from_client);
    }
    else {
      subserver(from_client);
    }
  }
}

void subserver(int from_client) {
  int to_client = server_connect(from_client);
  char buffer[BUFFER_SIZE];

  while (read(from_client, buffer, sizeof(buffer))) {
    printf("Processing\n");
    process(buffer);
    write(to_client, buffer, sizeof(buffer));
  }
}

void process(char *s) {
  s = ":)";
}