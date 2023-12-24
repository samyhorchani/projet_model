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

Complex Complex_add(Complex a, Complex b);      // réalise l'addition entre deux nombres Complexe
Complex Complex_subtract(Complex a, Complex b); // réalise la soustraction entre deux nombres Complexe
Complex Complex_multiply(Complex a, Complex b); // réalise la multiplication entre deux nombres Complexe
Complex Complex_divide(Complex a, Complex b);   // réalise la division entre deux nombres Complexe
Complex Complex_conjugate(Complex a);           // rend le conjugué d'un nombre Complexe
Complex Complex_exponential(Complex a);
Complex Complex_power(Complex a, int n);
Complex Complex_logarithm(Complex a);
Complex int_to_complex(int a);
Complex *tab_int_to_complex(int* tab, int size_tab);
void display_Complex(Complex a); //affiche un nombre Complexe dans le terminal sous la forme (a + bi)
void display_tab_complex(Complex *tab, int size_tab);

#endif