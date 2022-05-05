#include "../include/supervisor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include "../include/posix_semaphore.h"

void compute(Semaphore* panneauConfig, struct fontaine* ft) {
  char c = '\0', buffer;

  setPasswdChiffre(panneauConfig, ft);

  while (c != 'q') {
    printf("\nConfiguration actuelle :\n");
    printf("  Vanne : %s\n  Boisson : %s\n", ft->state, ft->boisson);
    printf(
        "\nCommandes :\n  e: Eau\n  g: Grenadine\n  o: Ouvrir vanne"
        "\n  f: Fermer vanne\n  q: Quitter\n\n"
        "Choix: ");
    scanf("%c", &c);
    while ((buffer = getchar()) != '\n' && buffer != EOF) {
    }

    if (c == 'e') {
      eauBoisson(panneauConfig, ft);
    } else if (c == 'g') {
      grenadineBoisson(panneauConfig, ft);
    } else if (c == 'f') {
      fermerVanne(panneauConfig, ft);
    } else if (c == 'o') {
      ouvrirVanne(panneauConfig, ft);
    }
  }
}

void setPasswdChiffre(Semaphore* panneauConfig, struct fontaine* ft) {
  P(panneauConfig);
  strcpy(ft->pwd, PWD_NON_CHIFRE);
  cesar(ft->pwd, CESAR_KEY);
  V(panneauConfig);
}

void ouvrirVanne(Semaphore* panneauConfig, struct fontaine* ft) {
  P(panneauConfig);
  strcpy(ft->state, "ouvert");
  V(panneauConfig);
}

void fermerVanne(Semaphore* panneauConfig, struct fontaine* ft) {
  P(panneauConfig);
  strcpy(ft->state, "fermé");
  V(panneauConfig);
}

void eauBoisson(Semaphore* panneauConfig, struct fontaine* ft) {
  P(panneauConfig);
  strcpy(ft->boisson, "eau");
  V(panneauConfig);
}

void grenadineBoisson(Semaphore* panneauConfig, struct fontaine* ft) {
  P(panneauConfig);
  strcpy(ft->boisson, "grenadine");
  V(panneauConfig);
}