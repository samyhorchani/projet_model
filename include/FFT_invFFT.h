/* Samy HORCHANI (n° étudiant : 28706765) */

#ifndef FFT_INVFFT_H
#define FFT_INVFFT_H
#include "complex.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>


int verify(int number); /*renvoie 0 si number est une puissance de 2, renvoie 1 sinon*/ 
int power_of_2(int number); /*renvoie 0 si number est une puissance de 2, renvoie la puissance de 2 supérieur à number la plus proche*/ 
Complex *FFT(Complex *v, int size_v, int *size_res);
Complex *invFFT(Complex *v, int size_v, int *size_res);
void FFT_rec(Complex *v, int n, Complex *res, Complex omega, int step);
#endif
