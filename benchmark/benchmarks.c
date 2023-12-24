/* Samy HORCHANI (n° étudiant : 28706765)*/

/* Fichier qui permet de realiser les courbes et tests */
#include "multiplyPolynomials.h"
#include <time.h>

int *randomPolynomial(int taille)
{
    int *result = malloc(taille * sizeof(int));

    for (int i = 0; i < taille; i++)
    {
        result[i] = (rand() % 2001) - 1000;
    }
    return result;
}
int main(void)
{
    srand(0); // pour avoir des tests reproductibles ?

    FILE *data_NAIVE = fopen("data_NAIVE.txt", "w");
    FILE *data_FFT = fopen("data_FFT.txt", "w");
    if (data_FFT == NULL || data_NAIVE == NULL)
    {
        printf("Erreur à l'ouverture des fichiers .txt\n");
        return 1;
    }
    clock_t debut, fin;
    double temps_ecoule;
    for (int i = 1; i <= 10000; i++)
    {
        int *p = randomPolynomial(i);
        int *q = randomPolynomial(i);
        int res;

        debut = clock();
        int *tmp_naiv = naiveMultiplyPolynomials(p, i, q, i, &res);
        fin = clock();

        temps_ecoule = ((double)(fin - debut)) / CLOCKS_PER_SEC;
        fprintf(data_NAIVE, "%d %d %f\n", i, i, temps_ecoule);

        debut = clock();
        int *tmp_FFT = fftMultiplyPolynomials(p, i, q, i, &res);
        fin = clock();

        temps_ecoule = ((double)(fin - debut)) / CLOCKS_PER_SEC;
        fprintf(data_FFT, "%d %d %f\n", i, i, temps_ecoule);
    
        printf("%d\n", i);
        free(p);
        free(q);
        free(tmp_naiv);
        free(tmp_FFT);
    }

    fclose(data_FFT);
    fclose(data_NAIVE);
    return 0;
}