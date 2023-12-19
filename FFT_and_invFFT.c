/* Samy HORCHANI (n° étudiant : 28706765) */

#include "complex.h"
#include "FFT_and_invFFT.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

// Implement the FFT and inverse FFT for vectors of size 2𝑘 : these functions must enlarge vectors of sizes that are not powers of 2.

int verify(int number)
{ // verifie qu'un nombre est bien une puissance de 2
    if (number <= 0)
    {
        return 0;
    }

    return (number & (number - 1)) == 0;
}

int power_of_2(int number)
{
    if (verify(number))
    {
        return number;
    }

    int n = (int)ceil(log2(number));
    return (int)pow(2, n);
}
void FFT_rec(Complex *v, int n, Complex *res, int step){
    if(n == 1){
        res[0] = v[0];
        return;
    }

    Complex pi2_I = {0., (2. * M_PI/n)}; // 2pi*i/n
    // display_complex(pi2_I);
    Complex omega = complex_exponential(pi2_I);
    // display_complex(omega_n);

    FFT_rec(v,  n/2 , res, 2*step);
    FFT_rec(v + step,n/2, res + n/2, 2*step);

    for (int i = 0; i < n/2; i++) {
        Complex p = res[i];
        Complex q = complex_multiply(res[i + n/2], complex_power(omega, i)); //initialement, omega vaut 1
        res[i] = complex_add(p, q);
        res[i + n/2] = complex_subtract(p,q);
    }
}

void FFT(int *v, int size_v){
    int n = power_of_2(size_v); // retourn size_v si puissance de 2 ou la puissance de 2 la plus proche
    Complex *new_v = malloc(n * sizeof(Complex));
    for(int i = 0; i < size_v; i++){ //Creation des complexes avec le tab d'entier en utilisant ma stucture decrite dans Complex.h
        new_v[i] = (Complex){v[i], 0};
    }

    for(int i = size_v; i < n; i++){
        new_v[i] = (Complex){0,0}; 
    } //Ne rentre pas si size_v deja puissance de 2 sinon init à 0

    Complex *res = malloc(n * sizeof(Complex));

    FFT_rec(new_v, n,res , 1);
    printf("RESULTAT FFT :\n");
    printf("[ ");
    for(int i = 0; i < n; i++){
        display_complex(res[i]);
        printf(" ");
    }
    printf("]\n");
}

void invFFT(int *v, int size_v){
    int n = power_of_2(size_v); // retourn size_v si puissance de 2 ou la puissance de 2 la plus proche
    Complex *new_v = malloc(n * sizeof(Complex));
    for(int i = 0; i < size_v; i++){ //Creation des complexes avec le tab d'entier en utilisant ma stucture decrite dans Complex.h
        new_v[i] = (Complex){v[i], 0};
    }

    for(int i = size_v; i < n; i++){
        new_v[i] = (Complex){0,0}; 
    } //Ne rentre pas si size_v deja puissance de 2 sinon init à 0

    Complex *res = malloc(n * sizeof(Complex));

    invFFT_rec(new_v, n,res , 1);
    printf("RESULTAT FFT :\n");
    printf("[ ");
    for(int i = 0; i < n; i++){
        display_complex(res[i]);
        printf(" ");
    }
    printf("]\n");
}

void invFFT_rec(Complex *v, int n, Complex *res, int step){
    if(n == 1){
        res[0] = v[0];
        return;
    }

    Complex pi2_I = {0., (2. * M_PI/n)}; // 2pi*i/n
    // display_complex(pi2_I);
    Complex omega = complex_exponential(pi2_I);
    // display_complex(omega_n);

    FFT_rec(v,  n/2 , res, 2*step);
    FFT_rec(v + step,n/2, res + n/2, 2*step);

    Complex n_complex = {n,0};

    for (int i = 0; i < n/2; i++) {
        Complex p = res[i];
        Complex q = complex_multiply(res[i + n/2], complex_conjugate(complex_power(omega, i))); //initialement, omega vaut 1
        res[i] = complex_divide(complex_add(p, q), n_complex);

        res[i + n/2] = complex_divide(complex_subtract(p,q), n_complex);
    }
}