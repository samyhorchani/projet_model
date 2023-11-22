/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "complex.h"
#include "naive_mult_algo.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("Test des fonctions d'arithmetique de nombre complexe :\n");
    Complex a = {1.0, 2.0};
    Complex b = {2.0, 3.0};

    printf("a = ");
    display(a);
    printf("b = ");
    display(b);

    printf("a + b = ");
    display(add(a,b));

    printf("a - b = ");
    display(subtract(a,b));

    printf("conjugué de a = ");
    display(conjugate(a));

    printf("a * b = ");
    display(multiply(a,b));

    printf("a/b = ");
    display(divide(a,b));

    int p1[] = {1,2,3}; // polynome 1
    int size_p1 = sizeof(p1)/sizeof(p1[0]); //taille polynome 1

    int p2[] = {0,2,5}; // polynome 2
    int size_p2 = sizeof(p2)/sizeof(p2[0]); //taille polynome 2

    printf("Teste de l'algorithme de multiplication de polynome naif\n");

    multiplyPolynomials(p1, size_p1, p2, size_p2);

    return 0;
}
