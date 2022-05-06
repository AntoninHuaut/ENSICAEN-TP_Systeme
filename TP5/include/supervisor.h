#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#define SHM_SIZE 768
#define CESAR_KEY 13
#define STR_LENGTH 256

#include "./cesar.h"
#include "./posix_semaphore.h"

#define PWD_NON_CHIFRE "Manon des sources"
#define MEM "/saperlipopette"
#define SEPHM "/mf-sem"

struct fontaine {
  char pwd[STR_LENGTH];
  char state[STR_LENGTH];
  char boisson[STR_LENGTH];
};

void compute(Semaphore* panneauConfig, struct fontaine* ft);

void setPasswdChiffre(Semaphore* panneauConfig, struct fontaine* ft);
void ouvrirVanne(Semaphore* panneauConfig, struct fontaine* ft);
void fermerVanne(Semaphore* panneauConfig, struct fontaine* ft);
void eauBoisson(Semaphore* panneauConfig, struct fontaine* ft);
void grenadineBoisson(Semaphore* panneauConfig, struct fontaine* ft);
void mentheBoisson(Semaphore* panneauConfig, struct fontaine* ft);
void orgeatBoisson(Semaphore* panneauConfig, struct fontaine* ft);

#endif