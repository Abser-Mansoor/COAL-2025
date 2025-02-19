#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int in_fd, out_fd;
    char buffer[1024];
    ssize_t bytes_read;

    in_fd = open("input.txt", O_RDONLY);
    if (in_fd < 0) {
        perror("Error opening input.txt");
        return 1;
    }

    out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0) {
        perror("Error opening output.txt");
        close(in_fd);
        return 1;
    }

    while ((bytes_read = read(in_fd, buffer, sizeof(buffer))) > 0) {
        if (write(out_fd, buffer, bytes_read) != bytes_read) {
            perror("Error writing to output.txt");
            close(in_fd);
            close(out_fd);
            return 1;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from input.txt");
    }

    close(in_fd);
    close(out_fd);

    return 0;
}
