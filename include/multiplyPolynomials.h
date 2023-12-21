/* Samy HORCHANI (n° étudiant : 28706765) */

#ifndef MULTIPLYPOLYNOMIALS_H
#define MULTIPLYPOLYNOMIALS_H

#include "complex.h"
#include "FFT_invFFT.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void naiveMultiplyPolynomials(int p1[], int size_p1, int p2[], int size_p2);
void fftMultiplyPolynomials(int p1[], int size_p1, int p2[], int size_p2);
#endif