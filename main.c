#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
static void sighandler(int signo) {
    if (signo == SIGINT) {
        printf("\nProgram is exiting due to SIGINT\n");
        exit(0);
    }
    if (signo == SIGUSR1) {
      printf("\nSIGUSR1 signal detected. Parent ID: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while (1) {
        printf("Running process with id [%d]\n", getpid());
        sleep(1);
    }
}
