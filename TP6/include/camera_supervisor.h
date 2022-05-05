#ifndef CAMERA_SUPERVISOR_H
#define CAMERA_SUPERVISOR_H

#include "./common.h"
#include "./posix_semaphore.h"

void clean_buffer();

void camera_compute(Semaphore* panneauConfig, struct parametres_t* params);

void setDistance(Semaphore* panneauConfig, struct parametres_t* params);

void setTheta(Semaphore* panneauConfig, struct parametres_t* params);

void setPhi(Semaphore* panneauConfig, struct parametres_t* params);

#endif