#ifndef UTILS_H
#define UTILS_H

#include "./common.h"
#include "./posix_semaphore.h"

void clean_buffer();

void setRawDistance(Semaphore* panneauConfig,
                    struct parameters_t* params,
                    float distance);

void setRawTheta(Semaphore* panneauConfig,
                 struct parameters_t* params,
                 int theta);

void setRawPhi(Semaphore* panneauConfig, struct parameters_t* params, int phi);

void setRawGravite(Semaphore* panneauConfig,
                   struct parameters_t* params,
                   float gravite);

void setRawMasse(Semaphore* panneauConfig,
                 struct parameters_t* params,
                 float masse);

void setRawForceDuVent(Semaphore* panneauConfig,
                       struct parameters_t* params,
                       float x,
                       float y,
                       float z);

void setRawColor(Semaphore* panneauConfig,
                 struct parameters_t* params,
                 int r,
                 int g,
                 int b);

#endif