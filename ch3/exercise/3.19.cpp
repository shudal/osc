#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;


int main(int argc, char *argv[]) {
  int res = 0;
  for (int i=0; i<argc; i++) {
    printf("%s\n", argv[i]);
  }

  if (argc == 1) {
    res = -1;
    printf("需要传入要跑的命令\n");
    return res;
  }

  pid_t pid = fork();
  if (pid < 0) {

    unique_ptr<char**> as = make_unique()
    return -1;
  }
  if (pid == 0) {
    unique_ptr<int> p;
    execvp(argv[1], (char**)argv[1]);
  } else {

    wait(NULL);
  }
  sleep(2);
  return 0;
}
