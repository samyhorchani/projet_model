/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "complex.h"

Complex Complex_add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex Complex_subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex Complex_multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex Complex_divide(Complex a, Complex b) {
    Complex result;
    double denom = b.real * b.real + b.imag * b.imag;
    if (denom == 0) {
        printf("Erreur: Division par zéro.\n");
        result.real = 0;
        result.imag = 0;
        return result;
    }
    
    result.real = (a.real * b.real + a.imag * b.imag) / denom;
    result.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return result;
}

Complex Complex_conjugate(Complex a){
    Complex result;
    result.real = a.real;
    result.imag = a.imag * -1;

    return result;
}

Complex Complex_exponential(Complex a) {
    Complex result;

    double exp_real = exp(a.real);
    result.real = exp_real * cos(a.imag);
    result.imag = exp_real * sin(a.imag);

    return result;
}
Complex Complex_power(Complex a, int n) { //utilisation la formule de moivre pour être en O(log(n))
    // Vérification pour le cas de base zéro
    if (a.real == 0 && a.imag == 0) {
        if (n <= 0) {
            fprintf(stderr, "Erreur: 0 élevé à une puissance négative ou nulle indéfini.\n");
            return int_to_complex(0); // Ou gérer autrement
        }
        // 0 élevé à une puissance positive est toujours 0
        return int_to_complex(0);
    }

    // Si la puissance est 0, retournez 1
    if (n == 0) {
        return int_to_complex(1);
    }
    
    Complex result = int_to_complex(1); // équivalent à 1 + 0i
    Complex base = a;

    if (n < 0) {
        // Si la puissance est négative, prenez le conjugué et l'inverse du complexe
        // et changez n en positif
        base = Complex_divide(int_to_complex(1), a);
        n = -n;
    }

    while (n > 0) {
        if (n % 2 == 1) {
            result = Complex_multiply(result, base);
        }
        base = Complex_multiply(base, base);
        n /= 2;
    }

    return result;
}

Complex Complex_logarithm(Complex a) {
    Complex result;
    result.real = 0.5 * log(a.real * a.real + a.imag * a.imag); // Utilisation de la propriété log(sqrt(x)) = 1/2 log(x) pour eviter appelle sqrt
    result.imag = atan2(a.imag, a.real);

    return result;
}

double Complex_abs(Complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

double Complex_arg(Complex a) {
    return atan2(a.imag, a.real);
}

Complex int_to_complex(int a){
    return (Complex){a,0};
}

Complex *tab_int_to_complex(int* tab, int size_tab){
    Complex *resultat = malloc(size_tab * sizeof(Complex));
    if(resultat == NULL){
        printf("erreur allocation tableau complex \n");
        return NULL;
    }
    for(int i = 0; i<size_tab ; i++){
        resultat[i] = int_to_complex(tab[i]);
        //display_Complex(resultat[i]);
    }
    return resultat;
}
void display_Complex(Complex a){
    printf("%.2f + %.2fi ", a.real, a.imag);
}

void display_tab_complex(Complex *tab, int size_tab){
    printf("[ ");
    for(int i = 0; i < size_tab; i++){
        display_Complex(tab[i]);
    }
    printf("] \n");

}