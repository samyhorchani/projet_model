/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "multiplyPolynomials.h"


int main(int argc, char const *argv[]){
    // printf("Test des fonctions d'arithmetique de nombre Complexe :\n");
    // Complex a = {1.0, 2.0};
    // Complex b = {2.0, 3.0};

    // printf("a = ");
    // display_Complex(a);
    // printf("b = ");
    // display_Complex(b);

    // printf("a + b = ");
    // display_Complex(Complex_add(a,b));

    // printf("a - b = ");
    // display_Complex(Complex_subtract(a,b));

    // printf("conjugué de a = ");
    // display_Complex(Complex_conjugate(a));

    // printf("a * b = ");
    // display_Complex(Complex_multiply(a,b));

    // printf("a/b = ");
    // display_Complex(Complex_divide(a,b));

    // int p1[] = {1,2, 3, 4}; // polynome 1
    // int size_p1 = sizeof(p1)/sizeof(p1[0]); //taille polynome 1
    // printf("Taille premier polynome = %d\n",size_p1);

    // int p2[] = {0,2, 9, 82, 3}; // polynome 2
    // int size_p2 = sizeof(p2)/sizeof(p2[0]); //taille polynome 2
    // printf("Taille seconde polynome = %d\n",size_p2);

    // int size_res = 0;
    // printf("Teste de l'algorithme de multiplication de polynome naif\n");

    // int *res_NAIVE = naiveMultiplyPolynomials(p1, size_p1, p2, size_p2, &size_res);
    // display_polynomial(res_NAIVE, size_res);
    // printf("l NAIF = %d\n", size_res);
    // printf("Teste de l'algorithme de multiplication de polynome FFT\n");
    // int *res_FFT = fftMultiplyPolynomials(p1, size_p1, p2, size_p2, &size_res);
    // display_polynomial(res_FFT, size_res);
    // display_polynomial(p1, size_p1);
    // display_polynomial(p2, size_p2);
    // printf("l FFT = %d\n", size_res);

    // // printf("Teste de la fonction verify\n");
    // // for(int i = 0; i<100; i++){
    // //     if(verify(i)){
    // //         printf("%d\n", i);
    // //     }
    // //     else{
    // //         printf("%d\n", power_of_2(i));
    // //     }
    // // }

    // printf("Teste de la fonction FFT :\n");
    // int len_v = 4;
    // int v[4] = {1, 2, 3, 0};
    // //size_res = 0;
    // Complex *v_complex = tab_int_to_complex(v, len_v);
    // //size_res = 0;
    // int size_res2 = 3;
    // Complex *v_FFT = FFT(v_complex, len_v, &size_res2);
    // printf("l after FFT = %d\n", size_res2);
    // display_tab_complex(v_FFT, size_res2);
    // printf("Teste de la fonction invFFT :\n");
    // display_tab_complex(invFFT(v_complex, len_v, &size_res2), size_res2);
    // printf("\n");

    int choix;
    char buffer[100];

    while (1) {
        printf("\nChoisissez une opération:\n");
        printf("1. Multiplication de polynômes (méthode naïve)\n");
        printf("2. Multiplication de polynômes (FFT)\n");
        printf("3. Calculer la FFT d'un vecteur\n");
        printf("4. Calculer l'inverse FFT\n");
        printf("5. Quitter\n");
        printf("Votre choix: ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Essayer de convertir le texte en nombre
            if (sscanf(buffer, "%d", &choix) == 1) {
                switch (choix) {
                    case 1:
                        // Multiplication naïve
                        break;
                    case 2:
                        // Multiplication FFT
                        break;
                    case 3:
                        // Calcul FFT
                        break;
                    case 4:
                        // Calcul Inverse FFT
                        break;
                    case 5:
                        printf("Fin du programme.\n");
                        return 0;
                    default:
                        printf("Choix invalide. Veuillez réessayer.\n");
                }
            } else {
                printf("Entrée invalide. Veuillez entrer un nombre.\n");
            }
        } else {
            printf("Erreur de lecture. Veuillez réessayer.\n");
        }
    }
    
    return 0;
}
