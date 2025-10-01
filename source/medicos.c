#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projects.h"

Medico* cria_medico() {
    return NULL;
}

Medico* insere_medico(Medico* lista) {
    Medico* novo = (Medico*) malloc(sizeof(Medico));

    printf("\nNovo Medico.\n");
    novo->crm = get_int("Digite o CRM: ");
    get_string("Digite o nome: ", novo->nome, MAX_STRING_SIZE);
    novo->telefone = get_int("Digite o telefone: ");
    get_string("Digite a especialidade: ", novo->especialidade, MAX_STRING_SIZE);

    novo->prox = lista; 
    novo->ante = NULL; // INSERÇÃO NO INÍCIO DA LISTA

    if (lista != NULL) {
        lista->ante = novo;
    }
    return novo;
}

void imprime_medicos(Medico* lista) {
    if (lista!=NULL) {
        printf("\nImpressao dos medicos.\n");
        int cont=1;
        while (lista!=NULL) {
            printf("Medico %d.\n", cont);
            printf("CRM: %d.\n", lista->crm);
            printf("Nome: %s.\n", lista->nome);
            printf("Telefone: %d.\n", lista->telefone);
            printf("Especialidade: %s.\n", lista->especialidade);
            printf("Medico adicionado!\n\n");
            lista = lista->prox;
        }
    } else
        printf("Lista vazia.\n");
}