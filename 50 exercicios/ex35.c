// Crie um programa que leia um vetor e multiplique seus elementos por 2

#include <stdio.h>

int main(){

    int vet[3];
    int i;

    for(i = 0; i < 3; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }

    printf("Vetor multiplicado por 2: ");
    
    for(i = 0; i < 3; i++){
        printf("%d ", vet[i] * 2);
    }

    
}