#include <stdio.h>

int main()
{
    int vet[3] = {1, 2, 3};
    int i;
    int tamanho = sizeof(vet);

    while(i = 0, i < tamanho, i++)
    {
        printf("%d", vet[i]);
    }
}