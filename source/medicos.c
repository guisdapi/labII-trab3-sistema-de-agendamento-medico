#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "projects.h"

Medico* cria_medico() {
    return NULL;
}

Medico* insere_medico(Medico* lista) {
    Medico* novo = (Medico*) malloc(sizeof(Medico));

    int crm;
    char nome[MAX_STRING_SIZE];
    int telefone;
    char especialidade[MAX_STRING_SIZE];

    printf("\nNovo Medico.\n");
    printf("Digite o CRM: ");
    scanf("%d", &crm);
    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite o telefone: ");
    scanf("%d", &telefone);
    printf("Digite a especialidade: ");
    scanf("%s", especialidade);

    novo->crm = crm;
    strcpy(novo->nome, nome);
    novo->telefone = telefone;
    strcpy(novo->especialidade, especialidade);

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