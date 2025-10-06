// Rafael de Oliveira Machado RA: 2025105563

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define playerX 'X'
#define playerO 'O'
#define empate 'E'

#define space '_'

#define lineSize 3
#define columnSize 3

// função para criar tabela
void createTable(char table[lineSize][columnSize], int line, int lumn)
{
    for (line = 0; line < lineSize; line++)
    {
        for (lumn = 0; lumn < columnSize; lumn++)
        {
            table[line][lumn] = space;
        }
    }
}

// função para mostrar tabela
void showTable(char table[lineSize][columnSize], int line, int lumn)
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

// função para verificar vitória
int verificarVitoria(char table[lineSize][columnSize], char *winner, int *vitoriaX, int *vitoriaO)
{
    // Verificação para jogador X
    for (int line = 0; line < lineSize; line++)
    {
        if (table[line][0] == playerX && table[line][1] == playerX && table[line][2] == playerX)
        {
            *winner = playerX;
            (*vitoriaX)++;
            return 1;
        }
    }

    for (int lumn = 0; lumn < columnSize; lumn++)
    {
        if (table[0][lumn] == playerX && table[1][lumn] == playerX && table[2][lumn] == playerX)
        {
            *winner = playerX;
            (*vitoriaX)++;
            return 1;
        }
    }

    if (table[0][0] == playerX && table[1][1] == playerX && table[2][2] == playerX)
    {
        *winner = playerX;
        (*vitoriaX)++;
        return 1;
    }

    if (table[0][2] == playerX && table[1][1] == playerX && table[2][0] == playerX)
    {
        *winner = playerX;
        (*vitoriaX)++;
        return 1;
    }

    // Verificação para jogador O
    for (int line = 0; line < lineSize; line++)
    {
        if (table[line][0] == playerO && table[line][1] == playerO && table[line][2] == playerO)
        {
            *winner = playerO;
            (*vitoriaO)++;
            return 1;
        }
    }

    for (int lumn = 0; lumn < columnSize; lumn++)
    {
        if (table[0][lumn] == playerO && table[1][lumn] == playerO && table[2][lumn] == playerO)
        {
            *winner = playerO;
            (*vitoriaO)++;
            return 1;
        }
    }

    if (table[0][0] == playerO && table[1][1] == playerO && table[2][2] == playerO)
    {
        *winner = playerO;
        (*vitoriaO)++;
        return 1;
    }

    if (table[0][2] == playerO && table[1][1] == playerO && table[2][0] == playerO)
    {
        *winner = playerO;
        (*vitoriaO)++;
        return 1;
    }

    return 0; // Nenhum vencedor
}

// função jogador x jogador
void jogadorXjogador(char table[lineSize][columnSize], int line, int lumn, int position, char *winner, int *vitoriaX, int *vitoriaO, int *contJogadas, char *jogadorAtual, int *contEmpates)
{
    while (*winner == empate && *contJogadas < 9)
    {
        system("cls");
        showTable(table, line, lumn);

        printf("Jogador %c, escolha a posição (1-9): ", *jogadorAtual);
        scanf("%d", &position);

        if (position < 1 || position > 9)
        {
            printf("Posição inválida! Escolha novamente...\n");
            continue;
        }

        int linha, coluna;
        if (position >= 1 && position <= 3)
        {
            linha = 0;
            coluna = position - 1;
        }
        else if (position >= 4 && position <= 6)
        {
            linha = 1;
            coluna = position - 4;
        }
        else
        {
            linha = 2;
            coluna = position - 7;
        }

        if (table[linha][coluna] != space)
        {
            printf("Essa posição já está ocupada! Escolha outra...\n");
            continue;
        }

        table[linha][coluna] = *jogadorAtual;
        (*contJogadas)++;

        if (verificarVitoria(table, winner, vitoriaX, vitoriaO))
        {
            system("cls");
            showTable(table, line, lumn);
            printf("Jogador %c venceu!\n", *winner);
            break;
        }

        if (*contJogadas == 9)
        {
            system("cls");
            showTable(table, line, lumn);
            printf("Empate! Ninguém venceu.\n");
            (*contEmpates)++;
            break;
        }

        *jogadorAtual = (*jogadorAtual == playerX) ? playerO : playerX;
    }
}

// função para gerar jogada aleatória do computador facil
int jogadaComputadorFacil(char table[lineSize][columnSize])
{
    int posicoesVazias[9];
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] == space)
            {
                posicoesVazias[count] = i * 3 + j + 1;
                count++;
            }
        }
    }

    if (count > 0)
    {
        int indiceAleatorio = rand() % count;
        return posicoesVazias[indiceAleatorio];
    }

    return -1;
}

// função jogador vs computador facil
void computadorFacil(char table[lineSize][columnSize], int line, int lumn, int position, char *winner, int *vitoriaX, int *vitoriaO, int *contJogadas, char *jogadorAtual, int *contEmpates)
{
    while (*winner == empate && *contJogadas < 9)
    {
        system("cls");
        showTable(table, line, lumn);

        if (*jogadorAtual == playerX)
        {
            printf("Jogador %c, escolha a posição (1-9): ", *jogadorAtual);
            scanf("%d", &position);

            if (position < 1 || position > 9)
            {
                printf("Posição inválida! Escolha novamente...\n");
                continue;
            }

            int linha, coluna;
            if (position >= 1 && position <= 3)
            {
                linha = 0;
                coluna = position - 1;
            }
            else if (position >= 4 && position <= 6)
            {
                linha = 1;
                coluna = position - 4;
            }
            else
            {
                linha = 2;
                coluna = position - 7;
            }

            if (table[linha][coluna] != space)
            {
                printf("Essa posição já está ocupada! Escolha outra...\n");
                continue;
            }

            table[linha][coluna] = *jogadorAtual;
            (*contJogadas)++;
        }
        else
        {
            position = jogadaComputadorFacil(table);

            if (position != -1)
            {
                int linha, coluna;
                if (position >= 1 && position <= 3)
                {
                    linha = 0;
                    coluna = position - 1;
                }
                else if (position >= 4 && position <= 6)
                {
                    linha = 1;
                    coluna = position - 4;
                }
                else
                {
                    linha = 2;
                    coluna = position - 7;
                }

                table[linha][coluna] = *jogadorAtual;
                (*contJogadas)++;
                printf("Computador jogou na posição %d\n", position);
            }
        }

        if (verificarVitoria(table, winner, vitoriaX, vitoriaO))
        {
            system("cls");
            showTable(table, line, lumn);
            if (*winner == playerX)
            {
                printf("Jogador X venceu!\n");
            }
            else
            {
                printf("Computador (O) venceu!\n");
            }
            break;
        }

        if (*contJogadas == 9)
        {
            system("cls");
            showTable(table, line, lumn);
            printf("Empate! Ninguém venceu.\n");
            (*contEmpates)++;
            break;
        }

        *jogadorAtual = (*jogadorAtual == playerX) ? playerO : playerX;
    }
}

// função para determinar a jogada do computador dificil
int jogadaComputadorDificil(char table[lineSize][columnSize], char computador, char adversario)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        if (table[i][0] == computador && table[i][1] == computador && table[i][2] == space)
            return i * 3 + 3;
        if (table[i][0] == computador && table[i][2] == computador && table[i][1] == space)
            return i * 3 + 2;
        if (table[i][1] == computador && table[i][2] == computador && table[i][0] == space)
            return i * 3 + 1;

        if (table[0][i] == computador && table[1][i] == computador && table[2][i] == space)
            return 7 + i;
        if (table[0][i] == computador && table[2][i] == computador && table[1][i] == space)
            return 4 + i;
        if (table[1][i] == computador && table[2][i] == computador && table[0][i] == space)
            return 1 + i;
    }

    if (table[0][0] == computador && table[1][1] == computador && table[2][2] == space)
        return 9;
    if (table[0][0] == computador && table[2][2] == computador && table[1][1] == space)
        return 5;
    if (table[1][1] == computador && table[2][2] == computador && table[0][0] == space)
        return 1;
    if (table[0][2] == computador && table[1][1] == computador && table[2][0] == space)
        return 7;
    if (table[0][2] == computador && table[2][0] == computador && table[1][1] == space)
        return 5;
    if (table[1][1] == computador && table[2][0] == computador && table[0][2] == space)
        return 3;

    for (i = 0; i < 3; i++)
    {
        if (table[i][0] == adversario && table[i][1] == adversario && table[i][2] == space)
            return i * 3 + 3;
        if (table[i][0] == adversario && table[i][2] == adversario && table[i][1] == space)
            return i * 3 + 2;
        if (table[i][1] == adversario && table[i][2] == adversario && table[i][0] == space)
            return i * 3 + 1;

        if (table[0][i] == adversario && table[1][i] == adversario && table[2][i] == space)
            return 7 + i;
        if (table[0][i] == adversario && table[2][i] == adversario && table[1][i] == space)
            return 4 + i;
        if (table[1][i] == adversario && table[2][i] == adversario && table[0][i] == space)
            return 1 + i;
    }

    if (table[0][0] == adversario && table[1][1] == adversario && table[2][2] == space)
        return 9;
    if (table[0][0] == adversario && table[2][2] == adversario && table[1][1] == space)
        return 5;
    if (table[1][1] == adversario && table[2][2] == adversario && table[0][0] == space)
        return 1;
    if (table[0][2] == adversario && table[1][1] == adversario && table[2][0] == space)
        return 7;
    if (table[0][2] == adversario && table[2][0] == adversario && table[1][1] == space)
        return 5;
    if (table[1][1] == adversario && table[2][0] == adversario && table[0][2] == space)
        return 3;

    if (table[1][1] == space)
        return 5;

    int cantos[4] = {1, 3, 7, 9};
    for (i = 0; i < 4; i++)
    {
        int pos = cantos[i];
        int linha = (pos - 1) / 3;
        int coluna = (pos - 1) % 3;
        if (table[linha][coluna] == space)
            return pos;
    }

    return jogadaComputadorFacil(table);
}

// função computador dificil
void computadorDificil(char table[lineSize][columnSize], int line, int lumn, int position, char *winner, int *vitoriaX, int *vitoriaO, int *contJogadas, char *jogadorAtual, int *contEmpates)
{
    while (*winner == empate && *contJogadas < 9)
    {
        system("cls");
        showTable(table, line, lumn);

        if (*jogadorAtual == playerX)
        {
            printf("Jogador %c, escolha a posição (1-9): ", *jogadorAtual);
            scanf("%d", &position);

            if (position < 1 || position > 9)
            {
                printf("Posição inválida! Escolha novamente...\n");
                continue;
            }

            int linha, coluna;
            if (position >= 1 && position <= 3)
            {
                linha = 0;
                coluna = position - 1;
            }
            else if (position >= 4 && position <= 6)
            {
                linha = 1;
                coluna = position - 4;
            }
            else
            {
                linha = 2;
                coluna = position - 7;
            }

            if (table[linha][coluna] != space)
            {
                printf("Essa posição já está ocupada! Escolha outra...\n");
                continue;
            }

            table[linha][coluna] = *jogadorAtual;
            (*contJogadas)++;
        }
        else
        {

            position = jogadaComputadorDificil(table, playerO, playerX);

            if (position != -1)
            {
                int linha, coluna;
                if (position >= 1 && position <= 3)
                {
                    linha = 0;
                    coluna = position - 1;
                }
                else if (position >= 4 && position <= 6)
                {
                    linha = 1;
                    coluna = position - 4;
                }
                else
                {
                    linha = 2;
                    coluna = position - 7;
                }

                table[linha][coluna] = *jogadorAtual;
                (*contJogadas)++;
            }
        }

        if (verificarVitoria(table, winner, vitoriaX, vitoriaO))
        {
            system("cls");
            showTable(table, line, lumn);
            if (*winner == playerX)
            {
                printf("Parabéns! Jogador X venceu\n");
            }
            else
            {
                printf("Computador venceu! Tente novamente.\n");
            }
            break;
        }

        if (*contJogadas == 9)
        {
            system("cls");
            showTable(table, line, lumn);
            printf("Empate! Ninguém venceu.\n");
            (*contEmpates)++;
            break;
        }

        *jogadorAtual = (*jogadorAtual == playerX) ? playerO : playerX;
    }
}

// ranking
void Ranking(int vitoriaX, int vitoriaO, int contEmpates)
{
    printf("=====================================\n");
    printf("                RANKING              \n");
    printf("=====================================\n");
    printf("JOGADOR X: %d\n", vitoriaX);
    printf("JOGADOR O: %d\n", vitoriaO);
    printf("EMPATES: %d\n", contEmpates);
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    int option;
    int escolhaComputador;
    int line, lumn, position;
    int contJogadas = 0;
    int vitoriaX = 0;
    int vitoriaO = 0;
    int contEmpates = 0;
    int voltarMenu;

    char jogadorAtual = playerX;
    char winner = empate;
    char table[lineSize][columnSize];

    while (1)
    {
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

        createTable(table, line, lumn);

        switch (option)
        {
        case 1:
            system("cls");
            jogadorXjogador(table, line, lumn, position, &winner, &vitoriaX, &vitoriaO, &contJogadas, &jogadorAtual, &contEmpates);

            winner = empate;
            contJogadas = 0;
            jogadorAtual = playerX;
            createTable(table, line, lumn);

            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
                system("cls");
            break;

        case 2:
            system("cls");
            computadorFacil(table, line, lumn, position, &winner, &vitoriaX, &vitoriaO, &contJogadas, &jogadorAtual, &contEmpates);

            winner = empate;
            contJogadas = 0;
            jogadorAtual = playerX;
            createTable(table, line, lumn);

            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
                system("cls");
            break;

        case 3:
            system("cls");
            computadorDificil(table, line, lumn, position, &winner, &vitoriaX, &vitoriaO, &contJogadas, &jogadorAtual, &contEmpates);

            winner = empate;
            contJogadas = 0;
            jogadorAtual = playerX;
            createTable(table, line, lumn);

            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
                system("cls");
            break;

        case 4:
            system("cls");
            Ranking(vitoriaX, vitoriaO, contEmpates);
            printf("Digite 1 para voltar ao menu: ");
            scanf("%d", &voltarMenu);
            if (voltarMenu == 1)
                system("cls");
            break;

        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}

/*
 * Alterações realizadas:
 * - Implemento de funções para o organizar e modularizar o código.
 * - Melhorado dificuldade do computador dificil.
 * - Ponteiros para contadores de vitórias, empates e jogadas.
 * Bugs corrigidos:
 *    - Primeira jogada do computador dificil corrigida.
 *    - Correção na contagem de vitórias e empates.
 *    - Melhoria na verificação de vitória.
 *    - Duas jogadas no computador modo facil
 *
 * @author Rafael de Oliveira Machado
 * @date 2025-09-26
 */