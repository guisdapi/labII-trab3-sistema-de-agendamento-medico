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
    get_string("Digite o CRM:", novo->crm, MAX_STRING_SIZE);
    get_string("Digite o nome: ", novo->nome, MAX_STRING_SIZE);
    get_string("Digite o telefone: ", novo->telefone, MAX_STRING_SIZE);
    get_string("Digite a especialidade: ", novo->especialidade, MAX_STRING_SIZE);

    novo->prox = lista; 
    novo->ante = NULL; // INSERÇÃO NO INÍCIO DA LISTA

    if (lista != NULL)
        lista->ante = novo;

    return novo;
}

void imprime_medicos(Medico* lista) {
    if (lista != NULL) {
        printf("\nImpressão dos médicos.\n");
        int cont = 1;
        while (lista != NULL) {
            printf("Medico %d.\n", cont);
            printf("CRM: %s.\n", lista->crm);
            printf("Nome: %s.\n", lista->nome);
            printf("Telefone: %s.\n", lista->telefone);
            printf("Especialidade: %s.\n", lista->especialidade);
            lista = lista->prox;
            cont++;
        }
    } else
        printf("Lista de médicos vazia.\n");
}