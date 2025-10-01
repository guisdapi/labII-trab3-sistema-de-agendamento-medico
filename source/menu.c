#include <stdio.h>
#include <stdlib.h>
#include "projects.h"

void menu(Medico* lista) {
    int aux=1;

    while (aux!=0) {

        printf("\nMenu.\n");
        printf("1. Inserir medico\n");
        printf("2. Listar medicos\n");
        printf("0. Sair\n");
        aux = get_int("Escolha uma opção: ");

        switch (aux)
        {
        case 1:
            lista = insere_medico(lista);
            break;

        case 2:
            imprime_medicos(lista);
            break;
        
        default:
            break;
        }
    }
}