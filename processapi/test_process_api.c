#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("[%d] Main process\n", getpid());
    int rc = fork();
    if (rc < 0) {
        printf("Failed to fork a process");
        exit(1);
    } else if (rc == 0) {
        printf("[%d] rc == 0\n", getpid()); 
    } else {
        printf("[%d] Created process %d\n", getpid(), rc);
    }
}
