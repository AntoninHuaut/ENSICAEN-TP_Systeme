#ifndef ANIMATION_SUPERVISOR_H
#define ANIMATION_SUPERVISOR_H

#include "./common.h"
#include "./posix_semaphore.h"

float randomFloat(float a, float b);

void animation_compute(Semaphore* panneauConfig, struct parametres_t* params);

#endif