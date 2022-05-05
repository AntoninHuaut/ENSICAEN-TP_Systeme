#include "../include/environment_supervisor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include "../include/utils.h"

void environment_compute(Semaphore* panneauConfig,
                         struct parametres_t* params) {
  printf("\nEnvironment Supervisor\n");
  char c = '\0', buffer;

  while (c != 'q') {
    printf("\nConfiguration actuelle :\n");
    printf("  Gravité : %f\n  Masse : %f\n", params->gravite, params->masse);
    printf("  Force du vent :\n    X : %f\n    Y : %f\n    Z : %f\n",
           params->forceDuVent.x, params->forceDuVent.y, params->forceDuVent.z);

    printf(
        "\nCommandes :\n  g: Gravité\n  m: Masse\n  f: Force du vent"
        "\n  q: Quitter\n\n"
        "Choix: ");
    scanf("%c", &c);
    clean_buffer();

    if (c == 'g') {
      setGravite(panneauConfig, params);
    } else if (c == 'm') {
      setMasse(panneauConfig, params);
    } else if (c == 'f') {
      setForceDuVent(panneauConfig, params);
    }
  }
}

void setGravite(Semaphore* panneauConfig, struct parametres_t* params) {
  float gravite;
  printf("Gravité souhaitée : ");
  scanf("%f", &gravite);
  clean_buffer();

  P(panneauConfig);
  params->gravite = gravite;
  V(panneauConfig);
}

void setMasse(Semaphore* panneauConfig, struct parametres_t* params) {
  float masse;
  printf("Masse souhaitée : ");
  scanf("%f", &masse);
  clean_buffer();

  P(panneauConfig);
  params->masse = masse;
  V(panneauConfig);
}

void setForceDuVent(Semaphore* panneauConfig, struct parametres_t* params) {
  float x, y, z;
  printf("Force du vent\n");

  printf("  X souhaité : ");
  scanf("%f", &x);
  clean_buffer();

  printf("  Y souhaité : ");
  scanf("%f", &y);
  clean_buffer();

  printf("  Z souhaité : ");
  scanf("%f", &z);
  clean_buffer();

  P(panneauConfig);
  params->forceDuVent.x = x;
  params->forceDuVent.y = y;
  params->forceDuVent.z = z;
  V(panneauConfig);
}