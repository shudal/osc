#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1
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
    write(fd[WRITE_END], w_msg, strlen(w_msg) + 1);
    close(fd[WRITE_END]);
  } else {
    close(fd[WRITE_END]);
    read(fd[READ_END], r_msg, BUFFER_SIZE);
    printf("read:%s\n", r_msg);
    close(fd[READ_END]);
  }
  wait(NULL);
}
