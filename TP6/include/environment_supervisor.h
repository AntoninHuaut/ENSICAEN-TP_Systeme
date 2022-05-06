#ifndef ENVIRONMENT_SUPERVISOR_H
#define ENVIRONMENT_SUPERVISOR_H

#include "./common.h"
#include "./posix_semaphore.h"

void environment_compute(Semaphore* panneauConfig, struct parameters_t* params);

void setGravite(Semaphore* panneauConfig, struct parameters_t* params);

void setMasse(Semaphore* panneauConfig, struct parameters_t* params);

void setForceDuVent(Semaphore* panneauConfig, struct parameters_t* params);

#endif