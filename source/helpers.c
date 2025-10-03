#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "projects.h"

//Deixa uma string em caixa alta
void string_to_upper(char *str){
    int i = 0;
    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
}

//Pede por uma string e padroniza, podemos usar pra sanitizar melhor dps
void get_string(const char *pergunta, char *destino, int tam){
    printf("%s", pergunta);
    if(fgets(destino, tam, stdin)){
        destino[strcspn(destino, "\n")] = '\0';
    }
}

//Pede por uma string e depois transforma pra int, não aceita entrada inválida
int get_int(const char *pergunta){
    char buffer[100];
    int numero;
    char *endptr;

    while(true){
        get_string(pergunta, buffer, MAX_STRING_SIZE);

        numero = strtol(buffer, &endptr, 10);

        if(endptr == buffer || *endptr != '\0')
            printf("Entrada inválida, digite um número inteiro\n");
        else
            return numero;
    }
}