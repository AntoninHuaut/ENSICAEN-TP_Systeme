#include "../include/animation_supervisor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>
#include "../include/utils.h"

#define DISTANCE_PADDING 0.001
#define GRAVITE_PADDING 0.001
#define MASSE_PADDING 0.001
#define PROBA_VENT_CHANGE 0.1
#define PROBA_COLOR_CHANGE 10

float randomFloat(float a, float b) {
  float random = ((float)rand()) / (float)RAND_MAX;
  float diff = b - a;
  float r = random * diff;
  return a + r;
}

void animation_compute(Semaphore* panneauConfig, struct parameters_t* params) {
  srand(time(NULL));

  int tick = 0;

  while (1) {
    float newDistance = params->distance - DISTANCE_PADDING < 3
                            ? 10
                            : params->distance - DISTANCE_PADDING;
    float newGravite = params->gravity - GRAVITE_PADDING < 7
                           ? 12
                           : params->gravity - GRAVITE_PADDING;
    float newMasse =
        params->mass - MASSE_PADDING < 0.5 ? 2 : params->mass - MASSE_PADDING;

    if (tick > 20) {
      int newTheta = params->theta - 1 < 0 ? 360 : params->theta - 1;
      int newPhi = params->phi + 1 > 360 ? 0 : params->phi + 1;

      setRawTheta(panneauConfig, params, newTheta);
      setRawPhi(panneauConfig, params, newPhi);

      if (rand() % 100 < PROBA_VENT_CHANGE) {
        setRawForceDuVent(panneauConfig, params, randomFloat(-2, 2),
                          randomFloat(-2, 2), randomFloat(-2, 2));
      }

      if (rand() % 100 < PROBA_COLOR_CHANGE) {
        setRawColor(panneauConfig, params,
                    (params->color.r + (rand() % 256)) % 256,
                    (params->color.g + (rand() % 256)) % 256,
                    (params->color.b + (rand() % 256)) % 256);
      }

      tick = 0;
    }

    setRawDistance(panneauConfig, params, newDistance);
    setRawGravite(panneauConfig, params, newGravite);
    setRawMasse(panneauConfig, params, newMasse);

    usleep(1000);
    tick++;
  }
}