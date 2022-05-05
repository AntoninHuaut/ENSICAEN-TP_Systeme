#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include "../include/cesar.h"
#include "../include/posix_semaphore.h"
#include "../include/supervisor.h"

int main(void) {
  int shmd = shm_open(MEM, O_RDWR, S_IRUSR | S_IWUSR);
  if (shmd == -1) {
    perror("Impossible d'ouvrir la mémoire partagée");
    exit(EXIT_FAILURE);
  }

  Semaphore* panneauConfig = open_semaphore(SEPHM, 0);
  if (panneauConfig == NULL) {
    perror("Impossible de charger le semaphore du panneau de config");
    exit(EXIT_FAILURE);
  }

  struct fontaine* ft = mmap(NULL, /* adresse du dé but de page à projeter */
                             sizeof(struct fontaine), /* taille de projection */
                             PROT_READ | PROT_WRITE,  /* accès aux pages */
                             MAP_SHARED,              /* type de segment */
                             shmd, /* descripteur du segment */
                             0     /* offset de projection */
  );

  compute(panneauConfig, ft);

  munmap(ft, sizeof(struct fontaine));
  close(shmd);

  exit(EXIT_SUCCESS);
}
