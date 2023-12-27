/* Samy HORCHANI (n° étudiant : 28706765)*/

/* Fichier qui permet de realiser les courbes et tests */
#include "multiplyPolynomials.h"
#include <time.h>
#define MAX_TAILLE_POLY 15000 // Taille MAX de l'entrée (polynomes)
#define NUM_TESTS 5 // Nombre de mesure par tests afin de realiser une moyenne

int *randomPolynomial(int taille){ 
    int *result = malloc(taille * sizeof(int));

    for (int i = 0; i < taille; i++)
    {
        result[i] = (rand() % 2001) - 1000;
    }
    return result;
}

double measureTime(int *(*multiplicationFunc)(int *, int, int *, int, int *), int *p, int *q, int size){
    clock_t debut, fin;
    double temps_ecoule = 0.0;
    int res;
    for (int i = 0; i < NUM_TESTS; ++i) {
        debut = clock();
        int *tmp = multiplicationFunc(p, size, q, size, &res);
        fin = clock();

        temps_ecoule += ((double)(fin - debut)) / CLOCKS_PER_SEC;
        free(tmp);
          
    }
    return temps_ecoule / NUM_TESTS;  
}

int main(void){  
    //rechauffer le cache
    // int *warmup_p = randomPolynomial(MAX_TAILLE_POLY);
    // int *warmup_q = randomPolynomial(MAX_TAILLE_POLY);
    // int warmup_res;
    // int *warmup_tmp = naiveMultiplyPolynomials(warmup_p, MAX_TAILLE_POLY, warmup_q, MAX_TAILLE_POLY, &warmup_res);
    // free(warmup_tmp);
    // free(warmup_p);
    // free(warmup_q);


    // FILE *data_NAIVE = fopen("benchmark/data_NAIVE.txt", "w");
    // FILE *data_FFT = fopen("benchmark/data_FFT.txt", "w");
    // if (data_FFT == NULL || data_NAIVE == NULL)
    // {
    //     printf("Erreur à l'ouverture des fichiers .txt\n");
    //     return 1;
    // }
    
    // for (int i = 1; i <= MAX_TAILLE_POLY; i++)
    // {
    //     int *p = randomPolynomial(i);
    //     int *q = randomPolynomial(i);

    //     double temps_naive = measureTime(naiveMultiplyPolynomials, p, q, i);
    //     fprintf(data_NAIVE, "%d %f\n", i, temps_naive);

    //     double temps_FFT = measureTime(fftMultiplyPolynomials, p, q, i);
    //     fprintf(data_FFT, "%d %f\n", i, temps_FFT);

    //     printf("%d\n", i);
    //     free(p);
    //     free(q);
    // }

    // fclose(data_FFT);
    // fclose(data_NAIVE);

    /* ************************************************************************************ */
    FILE *data_NAIVE_THEO = fopen("benchmark/data_NAIVE_THEO.txt", "w");
    FILE *data_FFT_THEO = fopen("benchmark/data_FFT_THEO.txt", "w");
    if (data_FFT_THEO == NULL || data_NAIVE_THEO == NULL)
    {
        printf("Erreur à l'ouverture des fichiers .txt\n");
        return 1;
    }

    // for(int i = 1; i <= MAX_TAILLE_POLY; i++){
    //     for(int j = 1; j <= MAX_TAILLE_POLY; j++){
    //         fprintf(data_NAIVE_THEO, "%d %d %d\n", i, j , j*i);
    //         //int temps_fft = pow(2, () )
    //     }
    //     printf("%d\n", i);
    //     fprintf(data_NAIVE_THEO, "\n");
    // }
    for(int i = 1; i <= MAX_TAILLE_POLY; i++){
        fprintf(data_FFT_THEO, "%d %f\n", i , i*log(i) );
        fprintf(data_NAIVE_THEO, "%d %d\n", i , i*i );
    }

    fclose(data_FFT_THEO);
    fclose(data_NAIVE_THEO);
    return 0;
}