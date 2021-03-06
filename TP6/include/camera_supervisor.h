#ifndef CAMERA_SUPERVISOR_H
#define CAMERA_SUPERVISOR_H

#include "./common.h"
#include "./posix_semaphore.h"

void camera_compute(Semaphore* panneauConfig, struct parameters_t* params);

void setDistance(Semaphore* panneauConfig, struct parameters_t* params);

void setTheta(Semaphore* panneauConfig, struct parameters_t* params);

void setPhi(Semaphore* panneauConfig, struct parameters_t* params);

#endif