#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
static void sighandler(int signo) {
    if (signo == SIGINT) {
        int file = open("msg.txt", O_APPEND | O_CREAT | O_WRONLY, 0664);
        if (file == -1) 
        {
          printf("Error %d: %s", errno, strerror(errno));
        }
        char msg[] = "Program is exiting due to SIGINT\n";
        write(file, msg, sizeof(msg) - 1);
        close(file);
        exit(0);
    }
    if (signo == SIGUSR1) {
      printf("\nSIGUSR1 signal detected. Child ID: %d | Parent ID: %d\n", getpid(), getppid());
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
