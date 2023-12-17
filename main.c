/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "complex.h"
#include "naive_mult_algo.h"
#include "FFT_and_invFFT.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Test des fonctions d'arithmetique de nombre complexe :\n");
    Complex a = {1.0, 2.0};
    Complex b = {2.0, 3.0};

    printf("a = ");
    display_complex(a);
    printf("b = ");
    display_complex(b);

    printf("a + b = ");
    display_complex(complex_add(a,b));

    printf("a - b = ");
    display_complex(complex_subtract(a,b));

    printf("conjugué de a = ");
    display_complex(complex_conjugate(a));

    printf("a * b = ");
    display_complex(complex_multiply(a,b));

    printf("a/b = ");
    display_complex(complex_divide(a,b));

    int p1[] = {1,2,3}; // polynome 1
    int size_p1 = sizeof(p1)/sizeof(p1[0]); //taille polynome 1

    int p2[] = {0,2,5}; // polynome 2
    int size_p2 = sizeof(p2)/sizeof(p2[0]); //taille polynome 2

    printf("Teste de l'algorithme de multiplication de polynome naif\n");

    int* p_mult = multiplyPolynomials(p1, size_p1, p2, size_p2);
    int size_p_mult = size_p1 + size_p2 - 1;
    display_polynome(p_mult, size_p_mult);
    free(p_mult);

    printf("Teste de la fonction verify\n");
    for(int i = 0; i<100; i++){
        if(verify(i)){
            printf("%d\n", i);
        }
        else{
            printf("%d\n", power_of_2(i));
        }
    }

    printf("Teste de la fonction FFT\n");
    
    
    Complex v1 = {-1,0};
    Complex v2 = {2,0};
    Complex v3 = {3,0};
    Complex v4 = {0,0};
    Complex v[4] = {v1,v2,v3,v4};
    int v_1[8] = {2,1,-1,5,0,3,0,-4};
    FFT(v_1, 8);
    printf("\n");
    
    return 0;
}
