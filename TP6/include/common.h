#ifndef COMMON_H
#define COMMON_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <errno.h>
#include <locale.h> /* access UTF8 */
#include <wchar.h>  /* display UTF8 */
#ifdef WIN32
// to correct deviations in Microsoft VC++ 6.0
#define M_PI (3.1415926535897932384626433832795)
double drand48() {
  return (rand() % 10000) / 10000.0;
}
// end of corrections

#endif
#define PARAM_PATH "/calembredaine"
#define MUTEX_NAME "/vent-sem"
#define NB_PARTICULES 1000
#define PI 3.14159
#define DISTANCE_INIT 4.0
#define DISTANCE_MAX 15
#define MASSE 1
#define DELTA_T 0.01
#define VENT_NUL 0.0
#define VENT_LEGER 0.4
#define VENT_MOYEN 1.5
#define VENT_BRETON 2.5
typedef struct {
  GLfloat x;
  GLfloat y;
  GLfloat z;
} Vecteur;
typedef struct {
  Vecteur position;       /**< position de la particule */
  Vecteur vitesse;        /**< vitesse de la particule */
  Vecteur sommeDesForces; /**< somme des forces agissant sur la particule */
} Particule;
/**
 * @brief Paramètres de gestion de la fontaine venteuse.
 */
typedef struct parametres_t {
  GLfloat gravite;     /**< par défaut 9.81 sur Terre */
  GLfloat masse;       /**< masse des particules */
  Vecteur forceDuVent; /**< force du vent */
  GLfloat distance;    /**< distance initiale de la fontaine */
  GLint theta;         /**< angles de gestion du repère */
  GLint phi;           /**< ... */
  Particule listeParticules[NB_PARTICULES];
} Parametres;
#endif /* COMMON_H */