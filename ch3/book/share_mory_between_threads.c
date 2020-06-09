#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  const int SIZE = 4096;
  const char *name = "myshare";
  int fd;
  void *ptr;


  fd = shm_open(name, O_CREAT | O_RDWR, 0666);
  ftruncate(fd, SIZE);
  ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  int subpid = fork();
  if (subpid == 0) {
    char *msg1 = "hello ";
    char *msg2 = "world!";
    sprintf(ptr, "%s", msg1);
    ptr += strlen(msg1);
    sprintf(ptr, "%s", msg2);
    ptr += strlen(msg2);
  } else {
    printf("child write:%s\n", ptr);
    wait(NULL);
  }
}