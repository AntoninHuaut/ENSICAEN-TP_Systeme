# TP6
> Antonin HUAUT

## Commandes
- `make` : compile l'application
- `make run` : compile et lance l'application
- `make clean` : supprime l'application compilée

Il faut impérativement lancer le programme `windy_fountain` avant de lancer celui-ci.  

Trois modes disponibles :
- Animation : fait varier les valeurs automatiquement
- CameraSupervisor : permet de contrôler la caméra
- EnvironmentSupervisor : permet de contrôler l'environnement  

**Il est possible de lancer plusieurs instances de l'application en même temps pour contrôler plusieurs parties.**   
Pour modifier automatiquement la gravité pour Jupiter ou la Terre, il suffit de se rendre dans le mode environnement.  

On pourrait séparer les paramètres en deux structures comme ça les deux programmes environement et camera ne se bloqueraient plus entre eux.  