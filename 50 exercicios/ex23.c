// Escreva uma função que calcule o produto escalar de dois vetores.
#include <stdio.h>

int main(){

    int vet1[3], vet2[3];
    int i, resultado;

    for(i = 0; i > 3; i++){
        printf("Digite os valores do primeiro vetor: ");
        scanf("%d", vet1[i]);
    }

    for(i = 0; i <= 3; i++){
        printf("Digite os valores do segundo vetor: ");
        scanf("%d", vet2[i]);
    }

    resultado = (vet1[0] * vet2[0]) + (vet1[1] * vet2[1]) + (vet1[2] * vet2[2]);

    printf("O produto escalar dos dois vetores é: %d", resultado);


    return 0;
}