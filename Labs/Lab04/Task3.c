#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void print_user_info() {
    printf("User ID (UID): %d\n", getuid());
}

int main() {
    printf("Current Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());
    print_user_info();
    return 0;
}
