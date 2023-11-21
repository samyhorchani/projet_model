/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "complex.h"
#include <stdio.h>
#include <math.h>

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex divide(Complex a, Complex b) {
    Complex result;
    double denom = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denom;
    result.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return result;
}

Complex conjugate(Complex a){
    Complex result;
    result.real = a.real;
    result.imag = a.imag * -1;

    return result;
}

void display(Complex a){
    printf("%.2f + %.2fi\n", a.real, a.imag);
}