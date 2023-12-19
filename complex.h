/* Samy HORCHANI (n° étudiant : 28706765) */

#ifndef COMPLEX_H
#define COMPLEX_H

/* Structure */

typedef struct Complex
{
    double real; // partie réelle
    double imag; // partie imaginaire
} Complex;

/* Opération de base */

Complex complex_add(Complex a, Complex b);      // réalise l'addition entre deux nombres complexe
Complex complex_subtract(Complex a, Complex b); // réalise la soustraction entre deux nombres complexe
Complex complex_multiply(Complex a, Complex b); // réalise la multiplication entre deux nombres complexe
Complex complex_divide(Complex a, Complex b);   // réalise la division entre deux nombres complexe
Complex complex_conjugate(Complex a);           // rend le conjugué d'un nombre complexe
Complex complex_exponential(Complex a);
Complex complex_power(Complex a, int n);
Complex complex_logarithm(Complex a);
void display_complex(Complex a); //affiche un nombre complexe dans le terminal sous la forme (a + bi)

#endif