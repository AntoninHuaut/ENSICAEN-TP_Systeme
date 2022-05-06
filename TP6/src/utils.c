#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void clean_buffer() {
  char buffer;
  while ((buffer = getchar()) != '\n' && buffer != EOF) {
  }
}

void setRawDistance(Semaphore* panneauConfig,
                    struct parameters_t* params,
                    float distance) {
  P(panneauConfig);
  params->distance = distance;
  V(panneauConfig);
}

void setRawTheta(Semaphore* panneauConfig,
                 struct parameters_t* params,
                 int theta) {
  P(panneauConfig);
  params->theta = theta;
  V(panneauConfig);
}

void setRawPhi(Semaphore* panneauConfig, struct parameters_t* params, int phi) {
  P(panneauConfig);
  params->phi = phi;
  V(panneauConfig);
}

void setRawGravite(Semaphore* panneauConfig,
                   struct parameters_t* params,
                   float gravite) {
  P(panneauConfig);
  params->gravity = gravite;
  V(panneauConfig);
}

void setRawMasse(Semaphore* panneauConfig,
                 struct parameters_t* params,
                 float masse) {
  P(panneauConfig);
  params->mass = masse;
  V(panneauConfig);
}

void setRawForceDuVent(Semaphore* panneauConfig,
                       struct parameters_t* params,
                       float x,
                       float y,
                       float z) {
  P(panneauConfig);
  params->forceOfWind.x = x;
  params->forceOfWind.y = y;
  params->forceOfWind.z = z;
  V(panneauConfig);
}