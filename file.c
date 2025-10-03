#include <stdio.h>

int main() {

    char helloWord;

    FILE *file; // declara um ponteiro do tipo FILE
    file = fopen("teste.txt", "r"); // abre o arquivo no modo de leitura

    if(file == NULL){
        printf("Erro ao abrir o arquivo");
        return 1; // retorna um código de erro
    }

    fprintf(file, "Hello World"); // escreve no arquivo
    fscanf(file, "%c", &helloWord); // lê do arquivo

    fclose(file); // fecha o arquivo

    printf("%c", helloWord); // imprime o caractere lido do arquivo

    // tipos de segundo argumento
    // r -> ler um arquivo
    // w -> escrever um arquivo
    // a -> adicionar algo no final do arquivo
    // r+ -> ler e escrever um arquivo
}   