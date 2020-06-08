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

int main() {
    const int SIZE = 4096;
    const char *name = "myshare";
    int fd;
    char *ptr;


    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    ptr = (char*) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("ptr=%x\n", ptr);
    char *msg1 = "hello ";
    char *msg2 = "world!";
    sprintf(ptr, "%s", msg1);
    ptr += strlen(msg1);
    sprintf(ptr, "%s", msg2);
    ptr += strlen(msg2);
    printf("1\n");
    int subpid = fork();
    if (subpid == 0) {
        sleep(2);
        printf("2\n");
        fd = shm_open(name, O_RDONLY, 0666);
        printf("3\n");
        ptr = (char*) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        printf("4\n");
        printf("sub proc, ptr=%x\n", ptr);
        printf("5\n");
        printf("sub process read: %s\n", ptr);
        printf("6\n");
        shm_unlink(name);
    } else {
        wait(NULL);
    }
}

