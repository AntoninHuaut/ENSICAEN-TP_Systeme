#include "../include/prime.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

FILE* outputFd;

void traitement(int tube_ecoute[2], int ni) {
  int nb;
  int pid;
  int subTube[2];

  if (ni == -1) {
    exit(EXIT_FAILURE);
  }

  if (pipe(subTube) == -1) {
    perror("Error pipe child");
    exit(EXIT_FAILURE);
  }

  pid = fork();
  if (pid < 0) {
    perror("Error fork child");
    exit(EXIT_FAILURE);
  } else if (pid > 0) {
    // Père (subTube : écriture)
    close(subTube[0]);

    do {
      read(tube_ecoute[0], &nb, sizeof(nb));

      if (nb != -1) {
        if (nb % ni != 0) {
          write(subTube[1], &nb, sizeof(int));
        }
      }
    } while (nb != -1);

    write(subTube[1], &nb, sizeof(int));
    close(subTube[1]);
    wait(NULL);
  } else {
    // Fils (subTube : lecture)
    manage_fils(subTube);
  }
}

void manage_fils(int tube[2]) {
  close(tube[1]);

  int ni;
  read(tube[0], &ni, sizeof(ni));

  if (ni != -1) {
    fprintf(outputFd, "%d\n", ni);
    fflush(outputFd);
    traitement(tube, ni);
  }

  close(tube[0]);
  exit(EXIT_SUCCESS);
}

void manage_pere(int tube[2], int n) {
  close(tube[0]);

  int i;
  for (i = 2; i <= n; i++) {
    write(tube[1], &i, sizeof(i));
  }

  i = -1;
  write(tube[1], &i, sizeof(i));
  wait(NULL);
}

void try_create_output_file() {
  if ((outputFd = fopen("nb_premiers.txt", "w")) == NULL) {
    perror("Error fopen");
    exit(EXIT_FAILURE);
  }
}