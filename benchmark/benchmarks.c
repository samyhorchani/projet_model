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

    FILE *fichier = fopen("data_FFT.txt", "w"); // Ouvre le fichier en mode écriture
    if (fichier == NULL)
    {
        printf("Erreur à l'ouverture du fichier\n");
        return 1;
    }
    clock_t debut, fin;
    double temps_ecoule;
    for (int i = 1; i <= 100000; i++)
    {
        int *p = randomPolynomial(i);
        int *q = randomPolynomial(i);
        int res;
        debut = clock();
        fftMultiplyPolynomials(p, i, q, i, &res);
        fin = clock();
        temps_ecoule = ((double)(fin - debut)) / CLOCKS_PER_SEC;
        fprintf(fichier, "%d %d %f\n", i, i, temps_ecoule);
        printf("%d\n", i);
    }

    fclose(fichier);
    return 0;
}