#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/iplot.h"

#define INPUT_SIZE 100

int main(void) {
  char* ptr;
  float ret;
  char str[INPUT_SIZE];
  int fd;

  fd = open("dup2_clone.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
  dup2(fd, STDOUT_FILENO);

  if (fd < 0) {
    perror("Error creating dup2 file");
    exit(EXIT_FAILURE);
  }

  printf("IPlot program\n");

  while (1) {
    printf("Please enter the range (q to exit): ");

    fflush(stdout);
    fgets(str, INPUT_SIZE, stdin);
    ret = strtof(str, &ptr);
    fflush(stdin);

    if (ret) {
      printf("Range: %f\n", ret);
      create_child(ret);
    } else {
      if (ptr[0] == 'q') {
        printf("Exit\n");
        break;
      }

      printf("Error input: %s\n", ptr);
    }
  }

  close(fd);
  exit(EXIT_SUCCESS);
}