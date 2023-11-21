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

Complex add(Complex a, Complex b);      // réalise l'addition entre deux nombres complexe
Complex subtract(Complex a, Complex b); // réalise la soustraction entre deux nombres complexe
Complex multiply(Complex a, Complex b); // réalise la multiplication entre deux nombres complexe
Complex divide(Complex a, Complex b);   // réalise la division entre deux nombres complexe
Complex conjugate(Complex a);           // rend le conjugué d'un nombre complexe
void display(Complex a); //affiche un nombre complexe

#endif