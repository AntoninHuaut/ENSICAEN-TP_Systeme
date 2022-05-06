#include "../include/environment_supervisor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include "../include/utils.h"

void environment_compute(Semaphore* panneauConfig,
                         struct parameters_t* params) {
  char c = '\0', buffer;

  while (c != 'q') {
    printf("\n\n\nEnvironment Supervisor\n");
    printf("\nConfiguration actuelle :\n");
    printf("  Gravité : %f\n  Masse : %f\n", params->gravity, params->mass);
    printf("  Force du vent :\n    X : %f\n    Y : %f\n    Z : %f\n",
           params->forceOfWind.x, params->forceOfWind.y, params->forceOfWind.z);

    printf(
        "\nCommandes :\n  j: Jupiter (configure la gravité à 24.796)"
        "\n  t: Terre (configure la gravité à 9.81)\n  c: Couleur"
        "\n  g: Gravité\n  m: Masse\n  f: Force du vent"
        "\n  q: Quitter\n\n"
        "Choix: ");
    scanf("%c", &c);
    clean_buffer();

    if (c == 'j') {
      setRawGravite(panneauConfig, params, 24.796);
    } else if (c == 't') {
      setRawGravite(panneauConfig, params, 9.81);
    } else if (c == 'g') {
      setGravite(panneauConfig, params);
    } else if (c == 'm') {
      setMasse(panneauConfig, params);
    } else if (c == 'f') {
      setForceDuVent(panneauConfig, params);
    } else if (c == 'c') {
      setColor(panneauConfig, params);
    }
  }
}

void setGravite(Semaphore* panneauConfig, struct parameters_t* params) {
  float gravite;
  printf("Gravité souhaitée : ");
  scanf("%f", &gravite);
  clean_buffer();

  P(panneauConfig);
  params->gravity = gravite;
  V(panneauConfig);
}

void setMasse(Semaphore* panneauConfig, struct parameters_t* params) {
  float masse;
  printf("Masse souhaitée : ");
  scanf("%f", &masse);
  clean_buffer();

  P(panneauConfig);
  params->mass = masse;
  V(panneauConfig);
}

void setForceDuVent(Semaphore* panneauConfig, struct parameters_t* params) {
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
  params->forceOfWind.x = x;
  params->forceOfWind.y = y;
  params->forceOfWind.z = z;
  V(panneauConfig);
}

void setColor(Semaphore* panneauConfig, struct parameters_t* params) {
  int r, g, b;
  printf("Couleur\n");

  printf("  R souhaité : ");
  scanf("%d", &r);
  clean_buffer();

  printf("  G souhaité : ");
  scanf("%d", &g);
  clean_buffer();

  printf("  B souhaité : ");
  scanf("%d", &b);
  clean_buffer();

  P(panneauConfig);
  params->color.r = r;
  params->color.g = g;
  params->color.b = b;
  V(panneauConfig);
}