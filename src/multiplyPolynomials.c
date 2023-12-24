/* Samy HORCHANI (n° étudiant : 28706765) */

#include "multiplyPolynomials.h"

/* Implémentation de l'algorithme de multiplication naïve de deux polynomes avec des coefficients entiers */

void naiveMultiplyPolynomials(int p1[], int size_p1, int p2[], int size_p2, int *size_res){
    /* Entrée : 
        - Deux tableaux d'entier p1 et p2 où chaque case i represente le coefficient de degré i des polynomes p1 et p2.
        - La taille correspondante des deux tableaux p1 et p2.
        - Un entier permettant de stocker la taille polynome resultat.
    
       Sortie :
        - Le polynome obtenue par la multiplication des deux polynomes p1 et p2.
    */
    if(p1 == NULL || p2 == NULL){
        printf("INVALID INPUT : Polynome 1 ou Polynome 2 est NULL");
        return;
    }

    /* création du polynome résultat */
    *size_res = size_p1 + size_p2 - 1;

    /* creation et initialisation du polynome */
    int *result = calloc( *size_res,  sizeof(int));

    if(result == NULL){
        printf("ALLOCATION ERROR : Erreur lors de l'allocation du polynome résultat");
        return;
    }

    /* Multiplication du polynome*/
    for(int i = 0; i < size_p1; i++){
        for(int j = 0; j < size_p2; j++){
            result[i+j] += p1[i] * p2[j];
        }
    }

    printf("Result polynomial naive method: ");
    for (int i = 0; i < (*size_res) ; i++){
        printf("%d", result[i]);
        printf("x^%d ",i);
        if(i < (*size_res)-1){
            printf("+ ");
        }
    }
    printf("\n");

    free(result);
}

void fftMultiplyPolynomials(int P[], int size_P, int Q[], int size_Q, int *size_res){
    *size_res = size_P+size_Q-1;
    
    Complex *FFT_P = FFT( tab_int_to_complex(P, size_P), size_P, size_res);
    Complex *FFT_Q = FFT( tab_int_to_complex(Q, size_Q), size_Q, size_res);

    Complex *FFT_res = malloc((*size_res) * sizeof(Complex));
    for(int i = 0; i < (*size_res); i++){
        FFT_res[i] = Complex_multiply(FFT_P[i], FFT_Q[i]);
    }

    Complex *invFFT_res = invFFT(FFT_res, *size_res, size_res);

    int* res = malloc((*size_res) * sizeof(int));
    for(int i = 0; i < (*size_res); i++){
        res[i] = round(invFFT_res[i].real);
    }

    free(FFT_P);
    free(FFT_Q);
    free(FFT_res);
    free(invFFT_res);
    
    printf("Result polynomial FFT method: ");
    for (int i = 0; i < (*size_res) ; i++){
        printf("%d", res[i]);
        printf("x^%d ",i);
        if(i < (*size_res)-1){
            printf("+ ");
        }
    }
    printf("\n");

    free(res);
}

void display_polynomial(int *polynome, int res){
    
}