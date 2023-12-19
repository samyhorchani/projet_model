/* Samy HORCHANI (n° étudiant : 28706765)*/

/* Fichier qui permet de realiser les courbes et tests */

#include "complex.h"
#include "multiplyPolynomials.h"
#include "FFT_invFFT.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int* polynome(int n){
    int *result = malloc( n * sizeof(int));

    if(result == NULL){
        printf("Erreur à l'allocation du polynome resultat\n");
        return NULL;
    }
    for (int i = 0; i < n; i ++){
        result[i] = i+1;
    }

    return result;
}

int main(void){
    
}