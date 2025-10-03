#include <stdio.h>
#include <stdlib.h>
#include "projects.h"

void menu(Medico* medicos, Paciente* pacientes, Consultas* consultas) {
    int aux=1;

    while (aux!=0) {

        printf("\nMenu.\n");
        printf("1. Inserir medico\n");
        printf("2. Listar medicos\n");
        printf("3. Inserir paciente\n");
        printf("4. Listar pacientes\n");
        printf("5. Inserir consulta\n");
        printf("0. Sair\n");
        aux = get_int("Escolha uma opção: ");

        switch (aux)
        {
        case INSERIR_MEDICO:
            medicos = insere_medico(medicos);
            break;
        case LISTAR_MEDICOS:
            imprime_medicos(medicos);
            break;
        case INSERIR_PACIENTE:
            pacientes = insere_paciente(pacientes);
            break;
        case LISTAR_PACIENTES:
            imprime_pacientes(pacientes);
            break;
        case INSERIR_CONSULTA:
            insere_consulta(consultas, medicos);
        default:
            printf("Opção inválida.");
            break;
        }
    }
}