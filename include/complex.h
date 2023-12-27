/* Samy HORCHANI (n° étudiant : 28706765) */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Structure */

typedef struct Complex
{
    double real; // partie réelle
    double imag; // partie imaginaire
} Complex;

/* Opération de base */

Complex Complex_add(Complex a, Complex b);      // réalise l'addition entre deux nombres complexe
Complex Complex_subtract(Complex a, Complex b); // réalise la soustraction entre deux nombres complexe
Complex Complex_multiply(Complex a, Complex b); // réalise la multiplication entre deux nombres complexe
Complex Complex_divide(Complex a, Complex b);   // réalise la division entre deux nombres complexe
Complex Complex_conjugate(Complex a);           // rend le conjugué d'un nombre complexe
Complex Complex_exponential(Complex a); // réalise la mise à l'exponentielle d'un nombre complexe e^a
Complex Complex_power(Complex a, int n); // réalise la mise à la puissance d'un complexe en utilisant la formule de Moivre
Complex Complex_logarithm(Complex a); //réalise le logarithme d'un nombre complexe
Complex int_to_complex(int a); // convertit un entier en nombre complexe
Complex *tab_int_to_complex(int* tab, int size_tab); //convertit un tableau d'entier en un tableau de nombre complexe 
void display_Complex(Complex a); //affiche un nombre complexe sur le terminal sous la forme (a + bi)
void display_tab_complex(Complex *tab, int size_tab); // affiche un tableau de nombre complexe sur le terminale

#endif