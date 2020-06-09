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

  int fd = shm_open(share_mem_name, O_CREAT | O_RDWR, 0666);
  ftruncate(fd, SHARE_FILE_SIZE);
  void *ptr = mmap(NULL, SHARE_FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);


  pid_t pid = fork();
  if (pid < 0) {
    return -1;
  }
  if (pid == 0) {
    struct timeval current;
    gettimeofday((struct timeval*)ptr, NULL);
    int ret = execvp(argv[1], &argv[1]);
    if (ret < 0) {
      res = -3;
      printf("exec error: %d\n", ret);
      return res;
    }
  } else {

    pid_t child_pid;
    wait(&child_pid);

    struct timeval end;
    gettimeofday(&end, NULL);

    auto start = (struct timeval*)ptr;
    ptr = (void*)((char*)ptr + sizeof(struct timeval));
    printf("start when %lu\n", start->tv_sec);
    printf("used %lu second(s), %lu microsecond(s)\n", end.tv_sec - start->tv_sec, end.tv_usec - start->tv_usec);
  }
  return 0;
}
