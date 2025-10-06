// Faça uma função que encontre o menor valor de um vetor

#include <stdio.h>

int main(){
    int vet[6];
    int i;
    int menor = vet[0];

    for(i = 0; i < 6; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }

    for(i = 1; i < 6; i++)
    {
        if(vet[i] < menor)
        {
            menor = vet[i];
        }
    }

    printf("O menor valor é: %d", menor);

    

    
}