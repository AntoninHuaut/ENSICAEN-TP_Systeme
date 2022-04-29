#include "../include/sin_cos.h"
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/sin_cos_g.h"

int sinAngle = 0;
int cosAngle = 0;

void set_alarm() {
  int test = 0;

  if (test) {
    // FAST TEST
    if (sinAngle > 0) {
      sin_handler();
    }
    if (cosAngle > 0) {
      cos_handler();
    }
  } else {
    alarm(1);
  }
}

void sin_handler() {
  double sinValue;
  sinValue = sin(sinAngle * 2 * M_PI / 360);
  printf("Sin (%d): %lf\n", sinAngle, sinValue);

  write_sin_value(sinAngle, sinValue);

  sinAngle += 10;
  if (sinAngle <= 360) {
    set_alarm();
  } else {
    exit(EXIT_SUCCESS);
  }
}

void cos_handler() {
  double cosValue;

  cosValue = cos(cosAngle * 2 * M_PI / 360);
  printf("Cos (%d): %lf\n", cosAngle, cosValue);
  write_cos_value(cosAngle, cosValue);

  cosAngle += 10;
  if (cosAngle <= 360) {
    set_alarm();
  } else {
    exit(EXIT_SUCCESS);
  }
}

void setup_sin_handler() {
  struct sigaction action;
  action.sa_handler = &sin_handler;
  sigaction(SIGALRM, &action, NULL);
}

void setup_cos_handler() {
  struct sigaction action;
  action.sa_handler = &cos_handler;
  sigaction(SIGALRM, &action, NULL);
}