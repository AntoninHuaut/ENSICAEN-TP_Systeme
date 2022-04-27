# TP2
> Antonin HUAUT

## Commandes
- `make` : compile l'application
- `make run` : compile et lance l'application
- `make clean` : supprime l'application compilée

Pour tester l'affichage GNUPlot, il est possible d'accélérer les signaux alarmes pour rendre ça "instantané" :
> ./src/sin_cos.c (ligne 12)
```C
void set_alarm() {
  int test = 0;
  ...
}
```
Il suffit de placer la variable `test` à 1.