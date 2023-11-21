#include <stdio.h>

void multiplyPolynomials(int p1[], int size_p1, int p2[], int size_p2){
    
    if(p1 == NULL || p2 == NULL){
        printf("polynome 1 ou polynome 2 fournit non valide");
        return;
    }

    /* création du polynome résultat */
    int size_res = size_p1 + size_p2 - 1;
    int result[size_res];

    /* initialisation du polynome */

    for (int i = 0; i < size_res; i++){
        result[i] = 0;
    }

    /* Multiplication du polynome*/
    for(int i = 0; i < size_p1; i++){
        for(int j = 0; j < size_p2; j++){
            result[i+j] += p1[i] * p2[j];
        }
    }

    printf("Result polynomial: ");
    for (int i = 0; i < size_res; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}