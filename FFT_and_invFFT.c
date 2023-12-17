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
Complex *FFT(int *v, int size_v)
{

    if (size_v == 1)
    {
        Complex *res = malloc(size_v * sizeof(Complex));
        res[0].real = v[0];
        return res;
    }
    int n = power_of_2(size_v); // retourn size_v si puissance de 2 ou la puissance de 2 la plus proche

    Complex *res = malloc(n * sizeof(Complex)); // complexe init à 0

    Complex pi2_I = {0., (2. * M_PI) / n}; // 2pi*i/n
    // display_complex(pi2_I);
    Complex omega = complex_exponential(pi2_I);
    // display_complex(omega);

    int *v_e = malloc(n / 2 * sizeof(int)); // pair
    int *v_o = malloc(n / 2 * sizeof(int)); // impaire

    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            v_e[i / 2] = v[i];
        }
        else
        {
            v_o[i / 2] = v[i];
        }
    }

    Complex *y_e = FFT(v_e, n / 2);
    Complex *y_o = FFT(v_o, n / 2);

    for (int i = 0; i < n / 2; i++)
    {
        res[i] = complex_add(y_e[i], complex_multiply(complex_power(omega, i), y_o[i]));
        display_complex(res[i]);
        res[i + n / 2] = complex_subtract(y_e[i], complex_multiply(complex_power(omega, i), y_o[i]));
    }

    printf("RESULAT APPEL FFT :\n");
    for (int i = 0; i < n; i++)
    {
        display_complex(res[i]);
        printf(" ");
    }
    return res;
}
// Passer un tableau en parametre pour ne rien avoir à retourner.
// Pour les tests : creer une fonction qui creer un polynome random ??? Afficher les res sur une echelle log log ??