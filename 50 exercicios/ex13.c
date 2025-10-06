//Crie uma função que receba um vetor e retorne a soma de seus elementos

#include <stdio.h>

int main(){

    int vet[3][3] = {{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}};
    int i, j;
    float soma = 0;
   

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Digite o elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &vet[i][j]);
        }
    }

   soma = vet[0][0] + vet[0][1] + vet[0][2] + vet[1][0] + vet[1][1] + vet[1][2] + vet[2][0] + vet[2][1] + vet[2][2];

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d", vet[i][j]);
        }
        printf("\n");
    }

    printf("Soma dos elementos: %.1f\n", soma);
    return 0;
}