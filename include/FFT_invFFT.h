/* Samy HORCHANI (n° étudiant : 28706765) */

#ifndef FFT_INVFFT_H
#define FFT_INVFFT_H

int verify(int number); /*renvoie 0 si number est une puissance de 2, renvoie 1 sinon*/ 
int power_of_2(int number); /*renvoie 0 si number est une puissance de 2, renvoie la puissance de 2 supérieur à number la plus proche*/ 
Complex *FFT(int *v, int size_v); /*réalise la FFT et rend le resultat*/
void FFT_rec(Complex *v, int size_v, Complex *res, int len_res); /*réalise l'appel recursif pour la FFT*/
void invFFT_rec(Complex *v, int n, Complex *res, int step); /*réalise l'appel recursif pour la FFT inverse*/
Complex *invFFT(int *v, int size_v); /*réalise la FFT inverse*/
#endif