#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define playerX 'X'
#define playerO 'O'
#define empate 'E'

#define space '_'

#define lineSize 3
#define columnSize 3

void createTable(char table[lineSize][columnSize], int line, int lumn, int position){
    for(line = 0; line < lineSize; line++){
        for(lumn = 0; lumn < columnSize; lumn++){
            table[line][lumn] = space;
        }
    }
}

void showTable(char table[lineSize][columnSize], int line, int lumn, int position){
    for(line = 0; line < lineSize; line++){
        for(lumn = 0; lumn < columnSize; lumn++){
            printf("%c ", table[line][lumn]);
        }

        printf("\n");
    }
}

int main(){
    
    srand(time(NULL));
    
    int option;
    int escolhaComputador;

    int line, lumn, position;
    int contJogadas = 0;
    int vitoriaX = 0;
    int vitoriaO = 0;
    int vitoriaComp = 0;
    int contEmpate = 0;
    int voltarMenu;

    char jogadorAtual = playerX; // começa com jogador X, e alternando com o passar do jogo
    char winner = empate;
    char table[lineSize][columnSize];

    createTable(table, line,lumn, position); // inicializa a tabela com espaços vazios

    while(winner == empate)
    {

        showTable(table, line, lumn, position);

        while(contJogadas % 2 == 0)
        {
            printf("Jogador %c, digite uma posição: ", jogadorAtual);
            scanf("%d", &position);

            if(position < 1 || position > 9)
            {
                printf("Posição invalida, escolha novamente...");
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


        while (contJogadas % 2 != 0)
        {

            // verifica primeira linha

            if((table[0][0] == playerX && table[0][1] == playerX) ||
                (table[0][1] == playerX && table[0][2] == playerX) || 
                (table[0][0] == playerX && table[0][2] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;

                if(escolhaComputador == 1)
                {
                    if(table[0][2]  != space && table[0][1] != space)
                    {
                        table[0][0] = playerO;
                    }else if(table[0][0]  != space && table[0][1]  != space)
                    {
                        table[0][2] = playerO;
                    }else if(table[0][2]  != space && table[0][0]  != space)
                    {
                        table[0][1] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9;
                }
            }

            // verifica segunda linha

            if((table[1][0] == playerX && table[1][1] == playerX) || 
                (table[1][1] == playerX && table[1][2] == playerX) ||
                (table[1][0] == playerX && table[1][2] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;

                if(escolhaComputador == 1)
                {
                    if(table[1][2]  != space && table[1][1] != space)
                    {
                        table[1][0] = playerO;
                    }else if(table[1][0]  != space && table[1][1]  != space)
                    {
                        table[1][2] = playerO;
                    }else if(table[1][2]  != space && table[1][0]  != space)
                    {
                        table[1][1] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9;
                }
            }

            // verifica terceira linha

            if((table[2][0] == playerX && table[2][1] == playerX) || 
                (table[2][1] == playerX && table[2][2] == playerX) || 
                (table[2][0] == playerX && table[2][2] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;

                if(escolhaComputador == 1)
                {
                    if(table[2][2] != space && table[2][1] != space)
                    {
                        table[2][0] = playerO;
                    }else if(table[2][0]  != space && table[2][1]  != space)
                    {
                        table[2][2] = playerO;
                    }else if(table[2][2]  != space && table[2][0]  != space)
                    {
                        table[2][1] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9; // programar se o a posição já está ocupada
                }
            }

            // verifica primeira coluna

            if((table [0][0] == playerX && table[1][0] == playerX) ||
               (table [2][0] == playerX && table[1][0] == playerX) || 
               (table [2][0] == playerX && table[0][0] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;
                
                if(escolhaComputador == 1)
                {
                    if(table[0][0] != space && table[2][0] != space)
                    {
                        table[1][0] = playerO;
                    }else if(table[0][0] != space && table[1][0] != space)
                    {
                        table[2][0] = playerO;
                    }else if(table[2][0] != space && table[1][0] != space)
                    {
                        table[0][0] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9;
                }
            }

            // verifica segunda coluna

            if((table [0][1] == playerX && table[1][1] == playerX) || 
                (table [1][1] == playerX && table[2][1] == playerX) ||
                (table [2][1] == playerX && table[0][1] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;
                
                if(escolhaComputador == 1)
                {
                    if(table[0][1] != space && table[2][1] != space)
                    {
                        table[1][1] = playerO;
                    }else if(table[0][1] != space && table[1][1] != space)
                    {
                        table[2][1] = playerO;
                    }else if(table[2][1] != space && table[1][1] != space)
                    {
                        table[0][1] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9;
                }
            }

            // verifica terceira coluna

            if((table [0][2] == playerX && table[1][2] == playerX) ||
                (table [2][2] == playerX && table[1][2] == playerX) ||
                (table [2][2] == playerX && table[0][2] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;
                
                if(escolhaComputador == 1)
                {
                    if(table[0][2] != space && table[2][2] != space)
                    {
                        table[1][2] = playerO;
                    }else if(table[0][2] != space && table[1][2] != space)
                    {
                        table[2][2] = playerO;
                    }else if(table[2][2] != space && table[1][2] != space)
                    {
                        table[0][2] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9;
                }
            }

            // verifica primeira diagonal

            if((table [0][0] == playerX && table[1][1] == playerX) || 
                (table [2][2] == playerX && table[1][1] == playerX) ||
                (table [2][2] == playerX && table[0][0] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;
                
                if(escolhaComputador == 1)
                {
                    if(table[0][0] != space && table[1][1] != space)
                    {
                        table[2][2] = playerO;
                    }else if(table[1][1] != space && table[2][2] != space)
                    {
                        table[0][0] = playerO;
                    }else if(table[0][0] != space && table[2][2] != space)
                    {
                        table[1][1] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9;
                }
            }

            // verifica segunda diagonal

            if((table [2][0] == playerX && table[1][1] == playerX) ||
                (table [1][1] == playerX && table[0][2] == playerX) || 
                (table [2][0] == playerX && table[0][2] == playerX))
            {
                escolhaComputador = 1 + rand() % 2;
                
                if(escolhaComputador == 1)
                {
                    if(table[0][2] != space && table[1][1] != space)
                    {
                        table[2][0] = playerO;
                    }else if(table[1][1] != space && table[2][0] != space)
                    {
                        table[0][2] = playerO;
                    }else if(table[2][0] != space && table[0][2] != space)
                    {
                        table[1][1] = playerO;
                    }
                }else if(escolhaComputador == 2)
                {
                    position = 1 + rand() % 9;
                }
            }

            if (position >= 1 && position <= 3)
            {

                if (table[0][position - 1] != space)
                { // verifica se a posição já está ocupada
                    continue;
                }
                table[0][position - 1] = playerO; // atribui o jogador atual na posição escolhida
            }
            else if (position >= 4 && position <= 6)
            {

                if (table[1][position - 4] != space)
                {
                    continue; // pula para o início do loop se a posição for inválida
                }
                table[1][position - 4] = playerO;
            }
            else if (position >= 7 && position <= 9)
            {

                if (table[2][position - 7] != space)
                {
                    continue;
                }
                table[2][position - 7] = playerO;
            }

            contJogadas++;
        }

        // verificador de empate e troca de jogador

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
            printf("Empate! Ninguém venceu.\n");
            contEmpate++;
            break; // sai do loop se houver empate
        }


    } // fim do loop while
        

    return 0;
}