#ifndef COMMON_H
#define COMMON_H
#ifdef WIN32
/* to correct deviations in Microsoft VC++ 6.0 */
#define M_PI (3.1415926535897932384626433832795)
double drand48() {
  return (rand() % 10000) / 10000.0;
}
/* end of corrections */
#endif

#define PARAM_PATH "/calembredaine"
#define MUTEX_NAME "/vent-sem"  // coquille 1
#define NB_PARTICLES 1000
#define PI 3.14159
#define DISTANCE_INIT 4.0
#define DISTANCE_MAX 15
#define PARTICLE_MASS 1
#define DELTA_T 0.01
#define NO_WIND 0.0
#define SMALL_WIND 0.4
#define MEDIUM_WIND 1.5
#define STRONG_WIND 2.5
typedef struct {
  float x;
  float y;
  float z;
} Vector;
typedef struct {
  int r;
  int g;
  int b;
} Color;
typedef struct {
  Vector position;    /**< position of the particle */
  Vector velocity;    /**< velocity of the particle */
  Vector sumOfForces; /**< sum of all forces applied on the particle */
} Particle;
/**
 * @brief Parameters to control the windy fountain interface.
 */
typedef struct parameters_t {
  float gravity;                                 /**< 9.81 m/s^2 on Earth */
  float mass;                                    /**< mass of particles */
  Vector forceOfWind; /**< force of the wind */  // coquille 2
  float distance; /**< distance from the camera to the fountain */
  int theta;      /**< angles in spherical coordinates */
  int phi;        /**< ... */
  Color color;    /**< color of particles */
  Particle listOfParticles[NB_PARTICLES];
} Parameters;
#endif /* COMMON_H */