# Samy HORCHANI (n° étudiant 28706765)
# Projet MODEL

## Instruction de compilation
Ce projet est composé fichier `Makefile` permettant de réaliser la compilation. Pour générer l’exécutable `main`, il suffit de taper la commande `make all`. Deux exécutables sont alors générés. 
La structure de mon code est spécifiée dans mon rapport.

## Comment tester mon programme ?

Lancer la commande `./main`, il est ensuite possible de tester mes principales fonctions (multiplication naïve, multiplication basée sur la FFT, FFT, FFT inverse) en indiquant le numéro de l’opération correspondante dans le terminale puis de suivre les instructions. Il est également possible de créer un fichier .c et d’y inclure le header qui contient toutes les fonctions et header nécessaires pour pouvoir implémenter mes fonctions.
```c
#include multiplyPolynomials.h
```

## Comment lancer les tests ?

Lancer la commande `./benchmarks`, les mesures des temps d’exécution des algorithmes en fonctions de la taille des polynômes entrées est relevé puis stockés dans des fichiers `.txt`.

## Comment tracer les courbes correspondantes ?

Les instructions pour générer les courbes dans les graphiques analysés dans mon rapport sont disponibles dans le fichier`commande.gnuplot` 
Lancer la commande`gnuplot commande.gnuplot` dans un terminal. Les courbes seront générées dans le dossier `benchmark`.
Les graphiques 2D ont aussi été créés en utilisant Gnuplot. Cependant, le script de génération des graphiques n'a pas été joint parce que les données théoriques initiales ont été produites manuellement, comme mentionné dans les commentaires du fichier 'benchmarks.c'. Cette méthode manuelle aurait résulté en des fichiers de données très volumineux, dépassant 1 Go.
