/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "complex.h"
#include "multiplyPolynomials.h"
#include "FFT_invFFT.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    printf("Test des fonctions d'arithmetique de nombre Complexe :\n");
    Complex a = {1.0, 2.0};
    Complex b = {2.0, 3.0};

    printf("a = ");
    display_Complex(a);
    printf("b = ");
    display_Complex(b);

    printf("a + b = ");
    display_Complex(Complex_add(a,b));

    printf("a - b = ");
    display_Complex(Complex_subtract(a,b));

    printf("conjugué de a = ");
    display_Complex(Complex_conjugate(a));

    printf("a * b = ");
    display_Complex(Complex_multiply(a,b));

    printf("a/b = ");
    display_Complex(Complex_divide(a,b));

    int p1[] = {1,2}; // polynome 1
    int size_p1 = sizeof(p1)/sizeof(p1[0]); //taille polynome 1

    int p2[] = {0,2}; // polynome 2
    int size_p2 = sizeof(p2)/sizeof(p2[0]); //taille polynome 2

    printf("Teste de l'algorithme de multiplication de polynome naif\n");

    naiveMultiplyPolynomials(p1, size_p1, p2, size_p2);
    fftMultiplyPolynomials(p1, size_p1, p2, size_p2);

    // printf("Teste de la fonction verify\n");
    // for(int i = 0; i<100; i++){
    //     if(verify(i)){
    //         printf("%d\n", i);
    //     }
    //     else{
    //         printf("%d\n", power_of_2(i));
    //     }
    // }

    printf("Teste de la fonction FFT\n");
    int v_1[8] = {1,2,3, 4, 5,6,7,8};
    invFFT(v_1, 8);
    printf("\n");
    
    return 0;
}
