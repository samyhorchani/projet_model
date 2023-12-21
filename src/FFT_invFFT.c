/* Samy HORCHANI (n° étudiant : 28706765) */

#include "FFT_invFFT.h"

// Implement the FFT and inverse FFT for vectors of size 2𝑘 : these functions must enlarge vectors of sizes that are not powers of 2.

int verify(int number){
    if (number <= 0)
    {
        return 0;
    }

    return (number & (number - 1)) == 0;
}

int power_of_2(int number){
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
    // display_Complex(pi2_I);
    Complex omega = Complex_exponential(pi2_I);
    // display_Complex(omega);

    FFT_rec(v,  n/2 , res, 2*step);
    FFT_rec(v + step,n/2, res + n/2, 2*step);

    for (int i = 0; i < n/2; i++) {
        Complex p = res[i];
        Complex q = Complex_multiply(res[i + n/2], Complex_power(omega, i)); //initialement, omega vaut 1
        res[i] = Complex_add(p, q);
        res[i + n/2] = Complex_subtract(p,q);
    }
}

Complex *FFT(int *v, int size_v){
    int n = power_of_2(size_v); // retourn size_v si puissance de 2 ou la puissance de 2 la plus proche
    Complex *new_v = malloc(n * sizeof(Complex));
    for(int i = 0; i < size_v; i++){ //Creation des Complexes avec le tab d'entier en utilisant ma stucture decrite dans Complex.h
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
        display_Complex(res[i]);
        printf(" ");
    }
    printf("]\n");
    return res;
}

Complex  *invFFT(int *v, int size_v){
    int n = power_of_2(size_v); // retourn size_v si puissance de 2 ou la puissance de 2 la plus proche
    Complex *new_v = malloc(n * sizeof(Complex));
    for(int i = 0; i < size_v; i++){ //Creation des Complexes avec le tab d'entier en utilisant ma stucture decrite dans Complex.h
        new_v[i] = (Complex){v[i], 0};
    }

    for(int i = size_v; i < n; i++){
        new_v[i] = (Complex){0,0}; 
    } //Ne rentre pas si size_v deja puissance de 2 sinon init à 0

    Complex *res = malloc(n * sizeof(Complex));

    invFFT_rec(new_v, n,res , 1);
    printf("RESULTAT inverse FFT :\n");
    printf("[ ");
    for(int i = 0; i < n; i++){
        display_Complex(res[i]);
        printf(" ");
    }
    printf("]\n");

    return res;
}

void invFFT_rec(Complex *v, int n, Complex *res, int step){
    if(n == 1){
        res[0] = v[0];
        return;
    }

    Complex pi2_I = {0., (2. * M_PI/n)}; // 2pi*i/n
    // display_Complex(pi2_I);
    Complex omega = Complex_conjugate(Complex_exponential(pi2_I));
    // display_Complex(omega_n);

    FFT_rec(v,  n/2 , res, 2*step);
    FFT_rec(v + step,n/2, res + n/2, 2*step);

    Complex n_Complex = {n,0};

    for (int i = 0; i < n/2; i++) {
        Complex p = res[i];
        Complex q = Complex_multiply(res[i + n/2], Complex_conjugate(Complex_power(omega, i))); //initialement, omega vaut 1
        res[i] = Complex_divide(Complex_add(p, q), n_Complex);

        res[i + n/2] = Complex_divide(Complex_subtract(p,q), n_Complex);
    }
}

