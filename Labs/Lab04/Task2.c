#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        for (int i = 0; i < 100; i++) {
            printf("I am a child process\n");
        }
    } else {
        for (int i = 0; i < 100; i++) {
            printf("I am a parent process\n");
        }
        wait(NULL);
    }
    return 0;
}
