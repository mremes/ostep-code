#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char buffer[300];
    int pipes[2];
    const char sep[2] = " ";
    
    if (pipe(pipes) == -1) {
        exit(1);
    }

    for(;;) {
        printf("> ");

        fgets(buffer, sizeof(buffer), stdin);
        char *p = strtok(buffer, sep);
        char *args[5];
        int i = 0;

        while(p != NULL) {
            printf("%s", p);
            args[i++] = p;
            p = strtok(NULL, sep);
        }

        args[i] = NULL;
        int rc = fork();

        if ((rc = fork()) == -1) {
            exit(1);
        } else if (rc == 0) {
            dup2(pipes[1], STDOUT_FILENO);
            close(pipes[0]);
            close(pipes[1]);
            execvp(args[0], args);
        } else {
            int rc_wait = wait(NULL);
        }
    }
}
