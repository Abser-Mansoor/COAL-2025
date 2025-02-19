#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int signum) {
    printf("Alarm received! Program will terminate.\n");
    _exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5);
    while (1) {
        printf("Program is still running...\n");
        sleep(1);
    }
    return 0;
}
