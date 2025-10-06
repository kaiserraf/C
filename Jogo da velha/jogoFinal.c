/*
    Rafael Machado = 2025105563
    Danilo Campelo = 2025105340
    Fernando Correa= 2025105720
    Matheus Padilha = 2025105420
*/


// bibliotecas usadas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// definições usadas

#define playerX 'X' // player X
#define playerO 'O' // player O
#define empate 'E' // empate (usado para loop do jogo)

#define space '_' // espaço vazio para o tabuleiro

// define o tamanho do tabuleiro
#define lineSize 3
#define columnSize 3

// funções usadas (criar e mostrar tabela)

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

    setlocale(LC_ALL, "pt_BR.UTF-8"); // configura o idioma para português

    srand(time(NULL)); // inicializa o gerador de números aleatórios

    // criação das variaveis

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
    char winner = empate; // define o vencedor, começa com empate
    char table[lineSize][columnSize];

    while (1)
    {
        // Menu jogo

        printf("=====================================\n");
        printf("             JOGO DA VELHA          \n");
        printf("=====================================\n");
        printf("1. Jogador vs Jogador\n");
        printf("2. Jogador vs Computador - Nivel: Facil\n");
        printf("3. Jogador vs Computador - Nivel: Difcil\n");
        printf("4. Ranking \n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        createTable(table, line, lumn, position); // inicializa o tabuleiro

        switch (option) // switch case para as opções do menu
        {
            // jogador X jogador
        case 1:

            system("cls"); // limpa a tela (windows)
            while (winner == empate && contJogadas < 9)
            { // loop infinito para continuar o jogo -> jogador VS jogador

                showTable(table, line, lumn, position);

                printf("Jogador %c, escolha a posição: ", jogadorAtual); // pede a posição do jogador atual
                scanf("%d", &position); // lê a posição

                // validação da posição
                if (position < 1 || position > 9)
                {
                    printf("Posição inválida!, escolha novamente...\n");
                    continue; // pula para inicio do loop while
                }

                // atribuição da posição no tabuleiro
                if (position >= 1 && position <= 3)
                {

                    // verifica se a posição já está ocupada
                    if (table[0][position - 1] != space)
                    {
                        printf("Essa posição já está ocupada, ecolha outra posição: \n");
                        continue;
                    }
                    table[0][position - 1] = jogadorAtual; // atribui o jogador atual na posição escolhida
                }
                else if (position >= 4 && position <= 6)
                {

                    if (table[1][position - 4] != space)
                    {
                        printf("Essa posição já está ocupada, ecolha outra posição: \n");
                        continue; // pula para o início do loop se a posição for inválida
                    }
                    table[1][position - 4] = jogadorAtual;
                }
                else if (position >= 7 && position <= 9)
                {

                    if (table[2][position - 7] != space)
                    {
                        printf("Essa posição já está ocupada, ecolha outra posição: \n");
                        continue;
                    }
                    table[2][position - 7] = jogadorAtual;
                }

                // verificação de vitória jogador X

                // verifica as linhas
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

                // verifica as colunas
                for (lumn = 0; lumn < columnSize; lumn++)
                {
                    if (table[0][lumn] == playerX && table[1][lumn] == playerX && table[2][lumn] == playerX)
                    { // verifica colunas X
                        winner = playerX;
                        printf("Jogador %c venceu!\n", winner);

                        vitoriaX++;

                        break;
                    }
                }

                // verifica as diagonais
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

                // Alterna o jogador atual

                contJogadas++;
                if (contJogadas % 2 == 0) // jogadas pares == jogador X
                { 
                    jogadorAtual = playerX;
                }
                else // jogadas ímpares == jogador O
                { 
                    jogadorAtual = playerO;
                }

                if (winner != empate) // sai do loop se houver um vencedor
                {
                    showTable(table, line, lumn, position);
                    break;
                }

                if (contJogadas == 9) // sai do loop se houver empate
                {
                    showTable(table, line, lumn, position);
                    printf("Empate! Ninguém venceu.\n");
                    break;
                }

            } // fim loop while(1)

            option = 0;
            contJogadas = 0;
            winner = empate;

            // Retorno ao menu
            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
            {
                system("cls");
                continue;
            }
            break;

            // jogador X computador facil

        case 2:

            system("cls");
            while (winner == empate && contJogadas < 9) //loop infinito para continuar o jogo -> jogador VS computador
            {
                showTable(table, line, lumn, position);

                // escolha do jogador

                while (contJogadas % 2 == 0) //jogadas pares = jogador X (mesma lógica do jogador vs jogador)
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

                    // mesma lógica do jogador, atribui a posição no tabuleiro

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

                // troca de jogador

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
            
            option = 0;
            contJogadas = 0;
            winner = empate;

            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
            {
                system("cls");
                continue;
            }

            break;
            // jogador X computador dificil

        case 3:

            system("cls");
            while (winner == empate && contJogadas < 9)
            {
                showTable(table, line, lumn, position);

                while (contJogadas % 2 == 0)
                {
                    printf("Jogador %c, digite uma posição: ", jogadorAtual);
                    scanf("%d", &position);

                    if (position < 1 || position > 9)
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

                    if (position >= 4 && position <= 6)
                    {
                        if (table[1][position - 4] != space)
                        {
                            printf("Essa posição já está ocupada, escolha outra posição: \n");
                            continue;
                        }

                        table[1][position - 4] = jogadorAtual;
                    }

                    if (position >= 7 && position <= 9)
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

                    escolhaComputador = 1 + rand() % 2; // gera um número aleatório entre 1 e 2

                    if (escolhaComputador == 1)
                    {
                        // verifica primeira linha (bloqueio)

                        if ((table[0][0] == playerX && table[0][1] == playerX) ||
                            (table[0][1] == playerX && table[0][2] == playerX) ||
                            (table[0][0] == playerX && table[0][2] == playerX))
                        {
                            if (table[0][2] != space && table[0][1] != space && table[0][0] == space)
                            {
                                table[0][0] = playerO;
                            }
                            else if (table[0][0] != space && table[0][1] != space && table[0][2] == space)
                            {
                                table[0][2] = playerO;
                            }
                            else if (table[0][2] != space && table[0][0] != space && table[0][1] == space)
                            {
                                table[0][1] = playerO;
                            }
                        }

                        // verifica segunda linha (bloqueio)

                        if ((table[1][0] == playerX && table[1][1] == playerX) ||
                            (table[1][1] == playerX && table[1][2] == playerX) ||
                            (table[1][0] == playerX && table[1][2] == playerX))
                        {
                            if (table[1][2] != space && table[1][1] != space && table[1][0] == space)
                            {
                                table[1][0] = playerO;
                            }
                            else if (table[1][0] != space && table[1][1] != space && table[1][2] == space)
                            {
                                table[1][2] = playerO;
                            }
                            else if (table[1][2] != space && table[1][0] != space && table[1][1] == space)
                            {
                                table[1][1] = playerO;
                            }
                        }

                        // verifica terceira linha (bloqueio)

                        if ((table[2][0] == playerX && table[2][1] == playerX) ||
                            (table[2][1] == playerX && table[2][2] == playerX) ||
                            (table[2][0] == playerX && table[2][2] == playerX))
                        {
                            if (table[2][2] != space && table[2][1] != space && table[2][0] == space)
                            {
                                table[2][0] = playerO;
                            }
                            else if (table[2][0] != space && table[2][1] != space && table[2][2] == space)
                            {
                                table[2][2] = playerO;
                            }
                            else if (table[2][2] != space && table[2][0] != space && table[2][1] == space)
                            {
                                table[2][1] = playerO;
                            }
                        }

                        // verifica primeira coluna (bloqueio)

                        if ((table[0][0] == playerX && table[1][0] == playerX) ||
                            (table[2][0] == playerX && table[1][0] == playerX) ||
                            (table[2][0] == playerX && table[0][0] == playerX))
                        {
                            if (table[0][0] != space && table[2][0] != space && table[1][0] == space)
                            {
                                table[1][0] = playerO;
                            }
                            else if (table[0][0] != space && table[1][0] != space && table[2][0] == space)
                            {
                                table[2][0] = playerO;
                            }
                            else if (table[2][0] != space && table[1][0] != space && table[0][0] == space)
                            {
                                table[0][0] = playerO;
                            }
                        }

                        // verifica segunda coluna (bloqueio)

                        if ((table[0][1] == playerX && table[1][1] == playerX) ||
                            (table[1][1] == playerX && table[2][1] == playerX) ||
                            (table[2][1] == playerX && table[0][1] == playerX))
                        {
                            if (table[0][1] != space && table[2][1] != space && table[1][1] == space)
                            {
                                table[1][1] = playerO;
                            }
                            else if (table[0][1] != space && table[1][1] != space && table[2][1] == space)
                            {
                                table[2][1] = playerO;
                            }
                            else if (table[2][1] != space && table[1][1] != space && table[0][1] == space)
                            {
                                table[0][1] = playerO;
                            }
                        }

                        // verifica terceira coluna (bloqueio)

                        if ((table[0][2] == playerX && table[1][2] == playerX) ||
                            (table[2][2] == playerX && table[1][2] == playerX) ||
                            (table[2][2] == playerX && table[0][2] == playerX))
                        {

                            if (table[0][2] != space && table[2][2] != space && table[1][2] == space)
                            {
                                table[1][2] = playerO;
                            }
                            else if (table[0][2] != space && table[1][2] != space && table[2][2] == space)
                            {
                                table[2][2] = playerO;
                            }
                            else if (table[2][2] != space && table[1][2] != space && table[0][2] == space)
                            {
                                table[0][2] = playerO;
                            }
                        }

                        // verifica primeira diagonal (bloqueio)

                        if ((table[0][0] == playerX && table[1][1] == playerX) ||
                            (table[2][2] == playerX && table[1][1] == playerX) ||
                            (table[2][2] == playerX && table[0][0] == playerX))
                        {
                            if (table[0][0] != space && table[1][1] != space && table[2][2] == space)
                            {
                                table[2][2] = playerO;
                            }
                            else if (table[1][1] != space && table[2][2] != space && table[0][0] == space)
                            {
                                table[0][0] = playerO;
                            }
                            else if (table[0][0] != space && table[2][2] != space && table[1][1] == space)
                            {
                                table[1][1] = playerO;
                            }
                        }

                        // verifica segunda diagonal (bloqueio)

                        if ((table[2][0] == playerX && table[1][1] == playerX) ||
                            (table[1][1] == playerX && table[0][2] == playerX) ||
                            (table[2][0] == playerX && table[0][2] == playerX))
                        {
                            if (table[0][2] != space && table[1][1] != space && table[2][0] == space)
                            {
                                table[2][0] = playerO;
                            }
                            else if (table[1][1] != space && table[2][0] != space && table[0][2] == space)
                            {
                                table[0][2] = playerO;
                            }
                            else if (table[2][0] != space && table[0][2] != space && table[1][1] == space)
                            {
                                table[1][1] = playerO;
                            }
                        }
                    }
                    else if (escolhaComputador == 2 || contJogadas == 1) // se não conseguir bloquear, joga aleatório
                    {
                        position = 1 + rand() % 9; // gera um número aleatório entre 1 e 9 para posição

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

            option = 0;
            contJogadas = 0;
            winner = empate;

            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
            {
                system("cls");
                continue;
            }

            break;

            // ranking

        case 4:

            system("cls");

            printf("=====================================\n");
            printf("                RANKING              \n");
            printf("=====================================\n");
            printf("JOGADOR X: %d\n", vitoriaX);
            printf("JOGADOR O: %d\n", vitoriaO);
            printf("COMPUTADOR: %d\n", vitoriaComp);
            printf("EMPATES: %d\n", contEmpate);

            option = 0;
            contJogadas = 0;
            winner = empate;

            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
            {
                system("cls");
                continue;
            }

            break;

            // sair

        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}