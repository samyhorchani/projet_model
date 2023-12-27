/* Samy HORCHANI (n° étudiant : 28706765) */

#include "FFT_invFFT.h"

// Implement the FFT and inverse FFT for vectors of size 2𝑘 : these functions must enlarge vectors of sizes that are not powers of 2.

int power_of_2(int number){
    if ((number & (number - 1)) == 0)
    {
        return number;
    }
    int count = 0;

    while(number != 0){
        number>>=1;
        count++;
    }

    return (1<<count);
}

void FFT_rec(Complex *v, int n, Complex *res, Complex omega, int step){
    if(n == 1){
        res[0] = v[0];
        return;
    }

    Complex omega_2 = Complex_multiply(omega, omega);
    // display_Complex(omega);

    FFT_rec(v,  n/2 , res, omega_2,2*step);
    FFT_rec(v + step,n/2, res + n/2, omega_2,2*step);

    //Ajouter omega i si marche pas
    Complex omega_i = {1,0};
    for (int i = 0; i < n/2; i++) {
        Complex p = res[i];
        Complex q = Complex_multiply(res[i + n/2], omega_i); //initialement, omega vaut 1
        res[i] = Complex_add(p, q);
        res[i + n/2] = Complex_subtract(p,q);
        omega_i = Complex_multiply(omega, omega_i);
    }
}


Complex *FFT(Complex *v, int size_v, int *size_res){
    //printf("HEEERE size_res=%d\n", *size_res);
    *size_res = power_of_2(*size_res);
    //printf("HEEERE size_res=%d\n", *size_res);

    Complex *new_v = malloc((*size_res) * sizeof(Complex));

    for(int i = 0; i < size_v; i++){ //Creation des Complexes avec le tab d'entier en utilisant ma stucture decrite dans Complex.h
        new_v[i] = v[i];
    }
               
    for(int i = size_v; i < *size_res; i++){
        new_v[i] = (Complex){0,0}; 
    } //Ne rentre pas si size_v deja puissance de 2 sinon init à 0

    
    Complex *res = malloc((*size_res) * sizeof(Complex));

    Complex pi2_I = {0., (2. * M_PI/ (*size_res) )}; // 2pi*i/n
    // display_Complex(pi2_I);
    Complex omega = Complex_exponential(pi2_I);

    FFT_rec(new_v, *size_res,res,omega, 1);

    // printf("RESULTAT FFT :\n");
    // printf("[ ");
    // for(int i = 0; i < (*size_res); i++){
    //     display_Complex(res[i]);
    //     printf(" ");
    // }
    // printf("]\n");
    free(new_v);
    return res;
}

Complex *invFFT(Complex *v, int size_v, int *size_res) {
    for(int i = 0; i < *(size_res); i++){
        v[i] = Complex_conjugate(v[i]);
    }
    Complex *res = FFT(v, size_v, size_res);
    for(int i=0;i<*size_res;i++){
        res[i] = Complex_divide(Complex_conjugate(res[i]),int_to_complex(size_v));
        v[i] = Complex_conjugate(v[i]); //annuler changement v
    } 

    //for(int i=0;i<*size_res;++i)  ;

    // printf("RESULTAT invFFT :\n");
    // printf("[ ");
    // for (int i = 0; i < *size_res; i++) {
    //     display_Complex(res[i]);
    //     printf(" ");
    // }
    // printf("]\n");

    return res;
}