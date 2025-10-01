#include <stdio.h>
#include <stdlib.h>
#include "projects.h"

Paciente* cria_paciente(){
    return NULL;
}

Paciente* insere_paciente(Paciente *lista){
    Paciente* novo = (Paciente*)malloc(sizeof(Paciente));

    printf("\nNovo Paciente.\n");
    get_string("Digite o nome: ", novo->nome, MAX_STRING_SIZE);
    get_string("Digite o CPF: ", novo->cpf, MAX_STRING_SIZE);
    get_string("Digite o telefone: ", novo->telefone, MAX_STRING_SIZE);

    novo->prox = lista;
    novo->ante = NULL;

    if(lista != NULL)
        lista->ante = novo;
    
    return novo;
}

void imprime_pacientes(Paciente* lista){
    if(lista != NULL){
        printf("\nImpressão dos pacientes.\n");
        int cont = 1;
        while(lista != NULL){
            printf("Paciente %d.\n", cont);
            printf("CPF: %s.\n", lista->cpf);
            pritnf("Nome: %s.\n", lista->nome);
            printf("Telefone: %s.\n", lista->telefone);
            lista = lista->prox;
            cont++;
        }
    }
    else
        printf("Lista de pacientes vazia.\n");
}