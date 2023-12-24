/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "multiplyPolynomials.h"


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

    int p1[4] = {1,2, 3, 4}; // polynome 1
    int size_p1 = sizeof(p1)/sizeof(p1[0]); //taille polynome 1
    printf("Taille premier polynome = %d\n",size_p1);

    int p2[3] = {0,2, 9}; // polynome 2
    int size_p2 = sizeof(p2)/sizeof(p2[0]); //taille polynome 2
    printf("Taille seconde polynome = %d\n",size_p2);

    int size_res = 0;
    printf("Teste de l'algorithme de multiplication de polynome naif\n");

    naiveMultiplyPolynomials(p1, size_p1, p2, size_p2, &size_res);
    printf("l NAIF = %d\n", size_res);
    printf("Teste de l'algorithme de multiplication de polynome FFT\n");
    fftMultiplyPolynomials(p1, size_p1, p2, size_p2, &size_res);
    printf("l FFT = %d\n", size_res);

    // printf("Teste de la fonction verify\n");
    // for(int i = 0; i<100; i++){
    //     if(verify(i)){
    //         printf("%d\n", i);
    //     }
    //     else{
    //         printf("%d\n", power_of_2(i));
    //     }
    // }

    printf("Teste de la fonction FFT LOOOOL\n");
    int len_v = 4;
    int v[4] = {2,10,-2,-9};
    //size_res = 0;
    Complex *v_complex = tab_int_to_complex(v, len_v);
    FFT(v_complex, len_v, &size_res);
    //size_res = 0;
    printf("Teste de la fonction invFFT LOOOOL\n");
    invFFT(v_complex, len_v, &size_res);
    printf("\n");
    
    return 0;
}
