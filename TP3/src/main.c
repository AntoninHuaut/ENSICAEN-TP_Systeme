#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../include/prime.h"

int main(int argc, char** argv) {
  int tube[2];
  int pid;
  int n;

  n = argc < 2 ? 30 : atoi(argv[1]);

  try_create_output_file();

  if (pipe(tube) == -1) {
    perror("Error pipe");
    exit(EXIT_FAILURE);
  }

  pid = fork();
  if (pid < 0) {
    perror("Error fork");
    exit(EXIT_FAILURE);
  } else if (pid > 0) {
    // Père
    manage_pere(tube, n);
  } else {
    // Fils
    manage_fils(tube);
  }

  exit(EXIT_SUCCESS);
}