#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../include/sin_cos.h"
#include "../include/sin_cos_g.h"

void create_calcul_child(void) {
  int pid1, pid2, childStatus, nbChild;

  nbChild = 0;
  pid1 = fork();
  nbChild++;

  if (pid1 < 0) {
    perror("Error");
    exit(EXIT_FAILURE);
  } else if (pid1 == 0) {
    // Fils

    setup_sin_handler();
    alarm(1);
    for (;;) {
    }
  } else {
    // Père

    pid2 = fork();
    nbChild++;

    if (pid2 < 0) {
      perror("Error");
      exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
      // Fils

      setup_cos_handler();
      alarm(1);
      for (;;) {
      }
    } else {
      // Père

      while (nbChild-- > 0) {
        wait(&childStatus);
        printf("Child exit: %d\n", childStatus);
      }
    }
  }
}

void create_gnuplot_child(void) {
  int pid1, pid2, childStatus, nbChild;

  nbChild = 0;
  pid1 = fork();
  nbChild++;

  if (pid1 < 0) {
    perror("Error");
    exit(EXIT_FAILURE);
  } else if (pid1 == 0) {
    // Fils

    create_command_file("Sinus plot", SIN_COMMAND_FILE_NAME, SIN_FILE_NAME);
    gnuplot_exec(SIN_COMMAND_FILE_NAME);
  } else {
    // Père

    pid2 = fork();
    nbChild++;

    if (pid2 < 0) {
      perror("Error");
      exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
      // Fils

      create_command_file("Cosinus plot", COS_COMMAND_FILE_NAME, COS_FILE_NAME);
      gnuplot_exec(COS_COMMAND_FILE_NAME);
    } else {
      // Père

      while (nbChild-- > 0) {
        wait(&childStatus);
        printf("Child exit: %d\n", childStatus);
      }
    }
  }
}

int main(void) {
  create_calcul_child();
  create_gnuplot_child();

  exit(EXIT_SUCCESS);
}