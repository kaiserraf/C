#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define playerX 'X'
#define playerO 'O'
#define empate 'E'

#define space '_'

#define lineSize 3
#define columnSize 3

void createTable(char table[lineSize][columnSize], int line, int lumn, int position)
{
    for (line = 0; line < lineSize; line++)
    {
        for (lumn = 0; lumn < columnSize; lumn++)
        {
            table[line][lumn] = space;
        }
    }
}

void showTable(char table[lineSize][columnSize], int line, int lumn, int position)
{
    for (line = 0; line < lineSize; line++)
    {
        for (lumn = 0; lumn < columnSize; lumn++)
        {
            printf("%c ", table[line][lumn]);
        }

        printf("\n");
    }
}

int main()
{

    srand(time(NULL));

    int option;
    int escolhaComputador;

    int line, lumn, position;
    int contJogadas = 0;
    int vitoriaX = 0;
    int vitoriaO = 0;
    int vitoriaComp = 0;
    int voltarMenu;

    char jogadorAtual = playerX; // começa com jogador X, e alternando com o passar do jogo
    char winner = empate;
    char table[lineSize][columnSize];

    createTable(table, line, lumn, position); // inicializa a tabela com espaços vazios

    while (winner == empate && contJogadas < 9)
    {

        showTable(table, line, lumn, position);

        // escolha do jogador

        while (contJogadas % 2 == 0)
        {
            printf("Jogador %c, digite uma posição: ", jogadorAtual);
            scanf("%d", &position);

            if (position < 1 || position > 9)
            {
                printf("Posição inválida, escolha novamente... \n");
                continue;
            }

            if (position >= 1 && position <= 3)
            {
                if (table[0][position - 1] != space)
                {
                    printf("Essa posição já está ocupada, escolha outra posição: \n");
                    continue;
                }

                table[0][position - 1] = jogadorAtual;
            }
            else if (position >= 4 && position <= 6)
            {
                if (table[1][position - 4] != space)
                {
                    printf("Essa posição já está ocupada, escolha outra posição: \n");
                    continue;
                }

                table[1][position - 4] = jogadorAtual;
            }
            else if (position >= 7 && position <= 9)
            {
                if (table[2][position - 7] != space)
                {
                    printf("Essa posição já está ocupada, escolha outra posição: \n");
                    continue;
                }

                table[2][position - 7] = jogadorAtual;
            }

            contJogadas++;
        }

        // jogadas Computador

        while (contJogadas % 2 != 0)
        {
            escolhaComputador = 1 + rand() % 9; // gera uma posição aleatória entre 1 e 9

            if (escolhaComputador >= 1 && escolhaComputador <= 3)
            {
                if (table[0][escolhaComputador - 1] != space)
                {
                    continue;
                }
                table[0][escolhaComputador - 1] = playerO;
            }
            else if (escolhaComputador >= 4 && escolhaComputador <= 6)
            {
                if (table[1][escolhaComputador - 4] != space)
                {
                    continue;
                }
                table[1][escolhaComputador - 4] = playerO;
            }
            else if (escolhaComputador >= 7 && escolhaComputador <= 9)
            {
                if (table[2][escolhaComputador - 7] != space)
                {
                    continue;
                }
                table[2][escolhaComputador - 7] = playerO;
            }

            contJogadas++;
        }

        //troca de jogador

        if (contJogadas % 2 == 0)
        {
            jogadorAtual = playerX;
        }
        else
        {
            jogadorAtual = playerO;
        }

        // verificação de vitória jogador X

        for (line = 0; line < lineSize; line++)
        {
            if (table[line][0] == playerX && table[line][1] == playerX && table[line][2] == playerX)
            {
                winner = playerX;
                printf("Jogador %c venceu!\n", winner);

                vitoriaX++;

                break;
            }
        }

        for (lumn = 0; lumn < columnSize; lumn++)
        {
            if (table[0][lumn] == playerX && table[1][lumn] == playerX && table[2][lumn] == playerX)
            {
                winner = playerX;
                printf("Jogador %c venceu!\n", winner);

                vitoriaX++;

                break;
            }
        }

        if (table[0][0] == playerX && table[1][1] == playerX && table[2][2] == playerX)
        {
            winner = playerX;
            printf("Jogador %c venceu!\n", winner);

            vitoriaX++;

            break;
        }

        if (table[0][2] == playerX && table[1][1] == playerX && table[2][0] == playerX)
        {
            winner = playerX;
            printf("Jogador %c venceu!\n", winner);

            vitoriaX++;

            break;
        }

        // verificação de vitória jogador O

        for (line = 0; line < lineSize; line++)
        {
            if (table[line][0] == playerO && table[line][1] == playerO && table[line][2] == playerO)
            { // verifica linhas X
                winner = playerO;
                printf("Jogador %c venceu!\n", winner);

                vitoriaO++;

                break;
            }
        }

        for (lumn = 0; lumn < columnSize; lumn++)
        {
            if (table[0][lumn] == playerO && table[1][lumn] == playerO && table[2][lumn] == playerO)
            { // verifica colunas X
                winner = playerO;
                printf("Jogador %c venceu!\n", winner);

                vitoriaO++;

                break;
            }
        }

        if (table[0][0] == playerO && table[1][1] == playerO && table[2][2] == playerO)
        {
            winner = playerO;
            printf("Jogador %c venceu!\n", winner);

            vitoriaO++;

            break;
        }

        if (table[0][2] == playerO && table[1][1] == playerO && table[2][0] == playerO)
        {
            winner = playerO;
            printf("Jogador %c venceu!\n", winner);

            vitoriaO++;

            break;
        }

        if (contJogadas > 8)
        {
            showTable(table, line, lumn, position);
            printf("Empate! Ninguém venceu.\n");
            break; // sai do loop se houver empate
        }

    } // fim loop while(1)

    return 0;
}