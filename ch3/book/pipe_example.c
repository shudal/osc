#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int BUFFER_SIZE = 25;
const int READ_END  = 0;
const int WRITE_END  1;
int main() {
    char w_msg[BUFFER_SIZE] = "HELLO";
    char r_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1) {
        fprintf(stderr, "pipe failed");
        return 1;
    }
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork failed");
        return 1;
    }

    if (pid > 0) {
        close(fd[READ_END]);
    } else {
        close(fd[WRITE_END]);
    }
}
