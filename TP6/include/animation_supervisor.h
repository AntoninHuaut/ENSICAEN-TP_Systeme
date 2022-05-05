#ifndef ANIMATION_SUPERVISOR_H
#define ANIMATION_SUPERVISOR_H

#include "./common.h"
#include "./posix_semaphore.h"

float randomFloat(float a, float b);

void animation_compute(Semaphore* panneauConfig, struct parametres_t* params);

void setRawDistance(Semaphore* panneauConfig,
                    struct parametres_t* params,
                    float distance);

void setRawTheta(Semaphore* panneauConfig,
                 struct parametres_t* params,
                 int theta);

void setRawPhi(Semaphore* panneauConfig, struct parametres_t* params, int phi);

void setRawGravite(Semaphore* panneauConfig,
                   struct parametres_t* params,
                   float gravite);

void setRawMasse(Semaphore* panneauConfig,
                 struct parametres_t* params,
                 float masse);

void setRawForceDuVent(Semaphore* panneauConfig,
                       struct parametres_t* params,
                       float x,
                       float y,
                       float z);

#endif