#include <stdio.h>

int main()
{

    int num1, num2, soma;


    printf("Digite um valor: ");
    scanf("%d", &num1);

    printf("Digite um valor: ");
    scanf("%d", &num2);

    soma = num1 + num2;

    printf("%d + %d = %d", num1, num2, soma);




    return 0;
}

/*

int i;
    int vet[2];
    int soma;

    for(i = 0; i <= 1; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }

    soma = vet[0] + vet[1];

    printf("A soma dos valores é: %d", soma);

*/