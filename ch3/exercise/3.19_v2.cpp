#include <fcntl.h>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

const int MAX_ARG_LENGTH = 128;
const char* share_mem_name = "share_file";
const int SHARE_FILE_SIZE = 4096;
int main(int argc, char *argv[]) {
  int res = 0;
  for (int i=0; i<argc; i++) {
    printf(": %s\n", argv[i]);
  }

  if (argc == 1) {
    res = -1;
    printf("需要传入要跑的命令\n");
    return res;
  }
  if (argc >= MAX_ARG_LENGTH) {
    res = -2;
    printf("传入参数过多\n");
    return res;
  }

  int fd[2];
  if (pipe(fd) < 0) {
    res = -3;
    printf("pipe failed\n", res);
    return res;
  }

  pid_t pid = fork();
  if (pid < 0) {
    return -1;
  }
  if (pid == 0) {
    close(fd[0]);
    struct timeval start;
    gettimeofday(&start, NULL);
    write(fd[1], &start, sizeof(struct timeval));

    int ret = execvp(argv[1], &argv[1]);
    if (ret < 0) {
      res = -3;
      printf("exec error: %d\n", ret);
      return res;
    }
  } else {
    close(fd[1]);

    pid_t child_pid;
    wait(&child_pid);

    struct timeval end;
    gettimeofday(&end, NULL);

    struct timeval start;
    read(fd[0], &start, sizeof(struct timeval));

    printf("start when %lu\n", start.tv_sec);
    printf("used %lu second(s), %lu microsecond(s)\n", end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
  }
  return 0;
}
