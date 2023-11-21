/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "complex.h"
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

    return 0;
}
