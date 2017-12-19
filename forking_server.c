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
  int from_client = server_setup();
  char buffer[BUFFER_SIZE];
  while (1) {   
    int to_client = server_connect(from_client);
    read(to_client, buffer, sizeof(buffer));
    printf("Sending: %s\n", buffer); 
  }
}

void subserver(int from_client) {
  int parent = fork();
  if (parent) {
    //server_setup();
  }
  else {
    server_connect(from_client);
  }

}

void process(char * s) {
}
