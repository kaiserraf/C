// Como gerar números aleatórios em C

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // variavel que armazena o tempo do sistema

int main(){

    int i;
    int num[10];

    srand(time(NULL)); // inicializa o gerador de números aleatórios com o tempo atual do sistema

    for(i = 0; i < 10; i++)
    {
        num[i] = 1 + rand() % 9; // gera um número aleatório
    }

    for(i = 0; i < 10; i++)
    {
        printf("%d\n", num[i]);
    }
    return 0;
    
}
/*
=============================================================================

srand(time(NULL)); // inicializa o gerador de números aleatórios com o tempo atual do sistema

    for(i = 0; i < 10; i++)
    {
        num[i] = 1 + rand() % 9; // gera um número aleatório
    }

    explicação do código acima:
    -> 1 + rand() % 9
    -> rand() % 9 -> gera números de 0 a 8
    -> 1 + (0 a 8) -> gera números de 1 a 9

=============================================================================


*/