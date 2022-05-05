#include "../include/animation_supervisor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include "../include/utils.h"

void animation_compute(Semaphore* panneauConfig, struct parametres_t* params) {}

void setRawDistance(Semaphore* panneauConfig,
                    struct parametres_t* params,
                    float distance) {
  P(panneauConfig);
  params->distance = distance;
  V(panneauConfig);
}

void setRawTheta(Semaphore* panneauConfig,
                 struct parametres_t* params,
                 int theta) {
  P(panneauConfig);
  params->theta = theta;
  V(panneauConfig);
}

void setRawPhi(Semaphore* panneauConfig, struct parametres_t* params, int phi) {
  P(panneauConfig);
  params->phi = phi;
  V(panneauConfig);
}

void setRawGravite(Semaphore* panneauConfig,
                   struct parametres_t* params,
                   float gravite) {
  P(panneauConfig);
  params->gravite = gravite;
  V(panneauConfig);
}

void setRawMasse(Semaphore* panneauConfig,
                 struct parametres_t* params,
                 float masse) {
  P(panneauConfig);
  params->masse = masse;
  V(panneauConfig);
}

void setRawForceDuVent(Semaphore* panneauConfig,
                       struct parametres_t* params,
                       float x,
                       float y,
                       float z) {
  P(panneauConfig);
  params->forceDuVent.x = x;
  params->forceDuVent.y = y;
  params->forceDuVent.z = z;
  V(panneauConfig);
}