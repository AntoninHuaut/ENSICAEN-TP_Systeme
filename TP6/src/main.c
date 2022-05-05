#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include "../include/animation_supervisor.h"
#include "../include/camera_supervisor.h"
#include "../include/common.h"
#include "../include/environment_supervisor.h"
#include "../include/posix_semaphore.h"

int main(void) {
  int shmd = shm_open(PARAM_PATH, O_RDWR, S_IRUSR | S_IWUSR);
  if (shmd == -1) {
    perror("Impossible d'ouvrir la mémoire partagée");
    exit(EXIT_FAILURE);
  }

  Semaphore* panneauConfig = open_semaphore(MUTEX_NAME, 0);
  if (panneauConfig == NULL) {
    perror("Impossible de charger le semaphore du panneau de config");
    exit(EXIT_FAILURE);
  }

  struct parametres_t* params =
      mmap(NULL, /* adresse du dé but de page à projeter */
           sizeof(struct parametres_t), /* taille de projection */
           PROT_READ | PROT_WRITE,      /* accès aux pages */
           MAP_SHARED,                  /* type de segment */
           shmd,                        /* descripteur du segment */
           0                            /* offset de projection */
      );

  char c = '\0', buffer;

  printf("\nChoisir le programme à lancer :\n");
  printf(
      "  Animation : a\n  CameraSupervisor : c\n  EnvironmentSupervisor : e"
      "\n\nChoix : ");
  scanf("%c", &c);
  while ((buffer = getchar()) != '\n' && c != EOF) {
  }

  if (c == 'c') {
    camera_compute(panneauConfig, params);
  } else if (c == 'e') {
    environment_compute(panneauConfig, params);
  } else if (c == 'a') {
    animation_compute(panneauConfig, params);
  } else {
    printf("Entrée invalide\n");
  }

  munmap(params, sizeof(struct parametres_t));
  close(shmd);

  exit(EXIT_SUCCESS);
}
