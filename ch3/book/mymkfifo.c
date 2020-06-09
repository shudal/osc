#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int c = 1;
int main() {
  int ret;
  char *myfifo = "/tmp/myfifosharefile";
  ret=mkfifo(myfifo, 0666);
  pid_t pid = fork();
  int fd;
  if (pid == 0) {
    char buf[4096];
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, 4096);
    printf("received:%s\n", buf);
    close(fd);

  } else {
    fd = open(myfifo, O_WRONLY); 
    char *msg = "hi";
    write(fd, msg, sizeof(msg));
    printf("%d\n", c++);
    close(fd);
    unlink(myfifo);
    wait(NULL);
  }
}