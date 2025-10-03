#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projects.h"

Consultas* cria_consulta(){
    return NULL;
}

void input_consulta(Consultas* novo_node, Medico* lista){
    printf("Criando consulta...\n");
    char buffer[MAX_STRING_SIZE];
    get_string("Insira o nome do médico: \n", buffer, MAX_STRING_SIZE);
    string_to_upper(buffer);
    Medico* medico_da_consulta = procura_medico(lista, buffer);
    printf("O medico da consulta é: %s\n", medico_da_consulta->nome);
}

Consultas* insere_consulta(Consultas* l, Medico* lista){
    Consultas* novo_node;
    novo_node = (Consultas*)malloc(sizeof(Consultas));

    input_consulta(novo_node, lista);
}
