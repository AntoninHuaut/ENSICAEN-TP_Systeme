#include "../include/camera_supervisor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include "../include/utils.h"

void camera_compute(Semaphore* panneauConfig, struct parameters_t* params) {
  char c = '\0', buffer;

  while (c != 'q') {
    printf("\n\n\nCamera Supervisor\n");
    printf("\nConfiguration actuelle :\n");
    printf("  Distance : %f\n  Theta : %d\n  Phi : %d\n", params->distance,
           params->theta, params->phi);

    printf(
        "\nCommandes :\n  d: Distance\n  t: Theta\n  p: Phi"
        "\n  q: Quitter\n\n"
        "Choix: ");
    scanf("%c", &c);
    clean_buffer();

    if (c == 'd') {
      setDistance(panneauConfig, params);
    } else if (c == 't') {
      setTheta(panneauConfig, params);
    } else if (c == 'p') {
      setPhi(panneauConfig, params);
    }
  }
}

void setDistance(Semaphore* panneauConfig, struct parameters_t* params) {
  float distance;
  printf("Distance souhaitée : ");
  scanf("%f", &distance);
  clean_buffer();

  P(panneauConfig);
  params->distance = distance;
  V(panneauConfig);
}

void setTheta(Semaphore* panneauConfig, struct parameters_t* params) {
  int theta;
  printf("Theta souhaité : ");
  scanf("%d", &theta);
  clean_buffer();

  P(panneauConfig);
  params->theta = theta;
  V(panneauConfig);
}

void setPhi(Semaphore* panneauConfig, struct parameters_t* params) {
  int phi;
  printf("Phi souhaité : ");
  scanf("%d", &phi);
  clean_buffer();

  P(panneauConfig);
  params->phi = phi;
  V(panneauConfig);
}