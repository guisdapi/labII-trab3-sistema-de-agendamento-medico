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
        printf("6. Listar consultas\n");
        printf("7. Desmarcar consulta\n");
        printf("8. Realizar consulta\n");
        printf("9. Relatorio 1 - Listar consultas de um dia especifico\n");
        printf("10. Relatorio 2 - Listar consultas de um paciente\n");
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
            consultas = insere_consulta(consultas, medicos, pacientes);
            break;
        case LISTAR_CONSULTA:
            listar_consultas(consultas);
            break;
        case DESMARCAR_CONSULTA:
            consultas = desmarcar_consulta(consultas);
            break;
        case REALIZAR_CONSULTA:
            realizar_consulta(consultas);
            break;
        case RELATORIO_CONSULTAS_DIA:
            relatorio_consultas_dia(consultas);
            break;
        case RELATORIO_CONSULTAS_PACIENTE:
            relatorio_consultas_paciente(consultas);
            break;
        case SAIR:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.");
            break;
        }
    }
}