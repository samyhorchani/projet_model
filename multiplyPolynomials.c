/* Samy HORCHANI (n° étudiant : 28706765) */

#include "multiplyPolynomials.h"
#include <stdio.h>
#include <stdlib.h>

/* Implémentation de l'algorithme de multiplication naïve de deux polynomes avec des coefficients entiers */

void naiveMultiplyPolynomials(int p1[], int size_p1, int p2[], int size_p2){
    /* Entrée : 
        - Deux tableaux d'entier p1 et p2 où chaque case i represente le coefficient de degré i des polynomes p1 et p2.
        - La taille correspondante des deux tableaux p1 et p2.
    
       Sortie :
        - Le polynome obtenue par la multiplication des deux polynomes p1 et p2.
    */

    if(p1 == NULL || p2 == NULL){
        printf("INVALID INPUT : Polynome 1 ou Polynome 2 est NULL");
        return;
    }
    

    /* création du polynome résultat */
    int size_res = size_p1 + size_p2 - 1;
    int *result = malloc( size_res * sizeof(int));

    if(result == NULL){
        printf("ALLOCATION ERROR : Erreur lors de l'allocation du polynome résultat");
        return;
    }

    /* initialisation du polynome */

    for (int i = 0; i < size_res; i++){
        result[i] = 0;
    }

    /* Multiplication du polynome*/
    for(int i = 0; i < size_p1; i++){
        for(int j = 0; j < size_p2; j++){
            result[i+j] += p1[i] * p2[j];
        }
    }

    printf("Result polynomial: ");
    for (int i = 0; i < size_res ; i++){
        printf("%d", result[i]);
        printf("x^%d ",i);
        if(i < size_res-1){
            printf("+ ");
        }
    }
    printf("\n");

    free(result);
}