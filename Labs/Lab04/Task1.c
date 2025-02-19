#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1: My PID is %d\n", getpid());
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            printf("Child 2: My parent's PID is %d\n", getppid());
        } else {
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}
