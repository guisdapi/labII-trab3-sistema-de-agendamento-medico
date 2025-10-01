#include <stdio.h>
#include <stdlib.h>
#include "projects.h"

void menu(Medico* medicos, Paciente* pacientes) {
    int aux=1;

    while (aux!=0) {

        printf("\nMenu.\n");
        printf("1. Inserir medico\n");
        printf("2. Listar medicos\n");
        printf("3. Inserir paciente\n");
        printf("4. Listar pacientes\n");
        printf("0. Sair\n");
        aux = get_int("Escolha uma opção: ");

        switch (aux)
        {
        case 1:
            medicos = insere_medico(medicos);
            break;

        case 2:
            imprime_medicos(medicos);
            break;
        
        default:
            break;
        }
    }
}