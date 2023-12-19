/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "complex.h"
#include <stdio.h>
#include <math.h>

Complex complex_add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex complex_subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex complex_multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex complex_divide(Complex a, Complex b) {
    Complex result;
    double denom = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denom;
    result.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return result;
}

Complex complex_conjugate(Complex a){
    Complex result;
    result.real = a.real;
    result.imag = a.imag * -1;

    return result;
}

Complex complex_exponential(Complex a) {
    Complex result;

    double exp_real = exp(a.real);
    result.real = exp_real * cos(a.imag);
    result.imag = exp_real * sin(a.imag);

    return result;
}
Complex complex_power(Complex a, int n) { //possible d'utiliser la formule de moivre pour etre en O(log(n))
    Complex result;
    result.real = 1;
    result.imag = 0;

    for (int i = 0; i < n; i++) {
        result = complex_multiply(result, a);
    }

    return result;
}

Complex complex_logarithm(Complex a) { // à verifier
    Complex result;
    result.real = log(sqrt(a.real * a.real + a.imag * a.imag));
    result.imag = atan2(a.imag, a.real);

    return result;
}


void display_complex(Complex a){
    printf("%.2f + %.2fi\n", a.real, a.imag);
}