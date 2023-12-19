/* Samy HORCHANI (n° étudiant : 28706765) */

#include "multiplyPolynomials.h"
#include "complex.h"
#include "FFT_invFFT.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    printf("Result polynomial naive method: ");
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

/*
    a. Compute the FFTs of 𝑃 and 𝑄 with 𝜔 a primitive 𝑛th root of unity, where 𝑛 > deg𝑃 +deg𝑄.
    b. Multiply coefficient by coefficient these FFTs to get the FFT of 𝑅, where 𝑅 = 𝑃𝑄. 
    c. Compute the inverse FFT of the FFT of 𝑅 to retrieve 𝑅.
*/
 
void fftMultiplyPolynomials(int P[], int size_P, int Q[], int size_Q){
    int n = power_of_2(size_P+size_Q-1);
    //printf("%d\n", n);

    //Calcule de la FFT
    int *P_enlarge = malloc( n * sizeof(int));
    int *Q_enlarge = malloc( n * sizeof(int));

    for (int i = 0; i < n; i++) {
        P_enlarge[i] = (i < size_P) ? P[i] : 0;
        Q_enlarge[i] = (i < size_Q) ? Q[i] : 0;
    }

    Complex *fft_P = FFT(P_enlarge, n);
    Complex *fft_Q = FFT(Q_enlarge, n);

    free(P_enlarge);
    free(Q_enlarge);
    int *R = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        R[i] = complex_multiply(fft_P[i], fft_Q[i]).real;
    }

    free(fft_P);
    free(fft_Q);

    Complex *invFFT_R = invFFT(R, n);

    double *result = malloc((size_P+size_Q) * sizeof(double));
    
    for(int i = 0; i < size_P+size_Q; i++){
        result[i] = invFFT_R[i].real;
    }

    printf("Result polynomial FFT method: ");
    for (int i = 0; i < size_P + size_Q-1 ; i++){
        printf("%.10f", result[i]);
        printf("x^%d ",i);
        if(i < size_P + size_Q -2){
            printf("+ ");
        }
    }
    printf("\n");

    free(invFFT_R);
    free(result);
}