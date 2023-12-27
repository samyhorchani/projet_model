/* Samy HORCHANI (n° étudiant : 28706765) */

#ifndef MULTIPLYPOLYNOMIALS_H
#define MULTIPLYPOLYNOMIALS_H

#include "complex.h"
#include "FFT_invFFT.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *naiveMultiplyPolynomials(int p1[], int size_p1, int p2[], int size_p2, int *size_res); // réalise l'algorithme de multiplication de polynomes naïf
int *fftMultiplyPolynomials(int P[], int size_P, int Q[], int size_Q, int *size_res); // réalise l'algorithme de multiplication de polynomes basé sur la FFT
void display_polynomial(int *polynome, int size_poly); // affiche un polynome sur le terminal
#endif