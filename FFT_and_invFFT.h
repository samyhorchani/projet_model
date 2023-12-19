/* Samy HORCHANI (n° étudiant : 28706765) */

#ifndef FFT_AND_INVFFT_H
#define FFT_AND_INVFFT_H

int verify(int number);
void FFT(int *v, int size_v);
void FFT_rec(Complex *v, int size_v, Complex *res, int len_res);
int power_of_2(int number);
void invFFT_rec(Complex *v, int n, Complex *res, int step);
void invFFT(int *v, int size_v);
#endif