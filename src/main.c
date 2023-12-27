/* Samy HORCHANI (n° étudiant : 28706765)*/
#include "multiplyPolynomials.h"

Complex getComplexInput() {
    Complex input;
    printf("Entrez la partie réelle du nombre complexe : ");
    while (scanf("%lf", &input.real) != 1) {
        printf("Entrée invalide. Veuillez entrer un nombre réel : ");
        // Nettoyer le buffer d'entrée
        while (getchar() != '\n');
    }

    printf("Entrez la partie imaginaire du nombre complexe : ");
    while (scanf("%lf", &input.imag) != 1) {
        printf("Entrée invalide. Veuillez entrer un nombre réel : ");
        // Nettoyer le buffer d'entrée
        while (getchar() != '\n');
    }

    return input;
}

int getIntInput(){
    int input;
    while (scanf("%d", &input) != 1) {
        printf("Entrée invalide. Veuillez entrer un entier : ");
        // Nettoyer le buffer d'entrée
        while (getchar() != '\n');
    }
    return input;
}

void makeMultiplication(int *(*multiplicationFunc)(int *, int, int *, int, int *)) {
    printf("Veuillez entrez le degré du premier polynome :");
    int size_P = getIntInput() + 1;
    int *P = malloc(size_P * sizeof(int));

    for(int i = 0; i < size_P ; i++){
        printf("Veuillez entrer le coefficient devant x^%d :\n", i);
        P[i] = getIntInput();
    }

    printf("Le polynome P = ");
    display_polynomial(P, size_P);

    printf("Veuillez entrez le degré du second polynome :");
    int size_Q = getIntInput() + 1;
    int *Q = malloc(size_Q * sizeof(int));

    for(int i = 0; i < size_Q ; i++){
        printf("Veuillez entrer le coefficient devant x^%d :\n", i);
        Q[i] = getIntInput();
    }
    printf("Le polynome Q = ");
    display_polynomial(Q, size_Q);

    printf("La multiplication du polynome P*Q = ");
    int size_res;
    int *result = multiplicationFunc(P, size_P, Q, size_Q, &size_res);

    display_polynomial(result, size_res);

    free(P);
    free(Q);
    free(result);
}
void makeFFTorInvFFT(Complex *(*fftFunc)(Complex *, int, int *)) {
    printf("Veuillez entrez la taille du vecteur :");
    int size_V = getIntInput();
    printf("size_v = %d\n", size_V);
    Complex *V = malloc(size_V * sizeof(Complex));
    if (V == NULL) {
        perror("Allocation de mémoire échouée");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size_V ; i++){
        V[i] = getComplexInput();
    }

    printf("Le resultat est : ");
    int size_res = size_V;
    Complex *result = fftFunc(V, size_V, &size_res);

    printf("size res =%d\n", size_res);
    display_tab_complex(result, size_res);

    free(V);
    free(result);
}

int main(int argc, char const *argv[]){
    int choix;
    char buffer[100];

    printf("\n\n\tSamy HORCHANI (n° étudiant : 28706765)\n\n");

    while (1) {

        printf("/************************** MENU ***************************/\n");
        printf("\nChoisissez une opération:\n\n");
        printf("1. Multiplication de polynômes (méthode naïve)\n");
        printf("2. Multiplication de polynômes (FFT)\n");
        printf("3. Calculer la FFT d'un vecteur\n");
        printf("4. Calculer l'inverse FFT\n");
        printf("5. Quitter\n");
        printf("\n/***********************************************************/\n\n");
        printf("Votre choix : ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Essayer de convertir le texte en nombre
            if (sscanf(buffer, "%d", &choix) == 1) {
                switch (choix) {
                    case 1:
                        // Multiplication naïve
                        printf("/******************* Algorithme de multiplication naïf ********************/\n");
                        makeMultiplication(naiveMultiplyPolynomials);

                        break;
                    case 2:
                        // Multiplication FFT
                        printf("/******************* Algorithme de multiplication FFT *********************/\n");
                        
                        makeMultiplication(fftMultiplyPolynomials);
                        break;
                    case 3:
                        // Calcul FFT
                        printf("/************************* Fast Fourier Transform *************************/\n");
                        makeFFTorInvFFT(FFT);
                        break;
                    case 4:
                        // Calcul Inverse FFT
                        printf("/********************* Inverse Fast Fourier Transform *********************/\n");
                        makeFFTorInvFFT(invFFT);
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
