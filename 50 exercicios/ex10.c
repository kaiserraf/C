// Escreva uma função que receba dois números e retorne o maior.
#include <stdio.h>

int main(){
    int num[2];
    int i;

    for(i = 0; i < 2; i++){
        printf("Digite um valor");
        scanf("%d", num[i]);
    }

    if(num[0] > num[1]){
        printf("O primeiro número é maior %d", num[0]);
    }else{
        printf("O segundo número é maior %d", num[1]);
    }
}