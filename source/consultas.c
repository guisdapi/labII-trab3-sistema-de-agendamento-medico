#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "projects.h"

Consultas* cria_consulta(){
    return NULL;
}


bool verifica_disponibilidade(Consultas* lista_consultas, Medico* medico, Paciente* paciente, int dia, int mes, int hora, int minuto) {
    Consultas* p = lista_consultas;
    while(p != NULL) {
        // Verifica se a data e o horário são os mesmos
        if (p->data[0] == dia && p->data[1] == mes && p->horario[0] == hora && p->horario[1] == minuto) {
            // Médico já tem consulta nesse horário
            if (p->medico == medico) {
                printf("ERRO: O medico %s ja possui uma consulta neste horario.\n", medico->nome);
                return false;
            }
            // Paciente já tem consulta nesse horário
            if (p->paciente == paciente) {
                printf("ERRO: O paciente %s ja possui uma consulta neste horario.\n", paciente->nome);
                return false;
            }
        }
        p = p->prox;
    }

    return true;
}

void input_consulta(Consultas* novo_node, Medico* listaMedico, Paciente* listaPaciente, Consultas* listaConsultas){
    printf("\nAgendamento de Consulta\n");
    char buffer[MAX_STRING_SIZE];

    get_string("Insira o nome do medico: ", buffer, MAX_STRING_SIZE);
    string_to_upper(buffer);
    Medico* medico_da_consulta = procura_medico(listaMedico, buffer);
    if(medico_da_consulta == NULL){
        printf("Medico nao encontrado.\n");
        return;
    }

    get_string("Insira o CPF do paciente: ", buffer, MAX_STRING_SIZE);
    Paciente* paciente_da_consulta = procura_paciente(listaPaciente, buffer);
    if(paciente_da_consulta == NULL){
        printf("Paciente nao encontrado.\n");
        return;
    }
    
    printf("Digite a data da consulta:\n");
    int dia = get_int("Dia: ");
    int mes = get_int("Mes: ");
    
    printf("Digite o horario da consulta (consultas de 30 em 30 min):\n");
    int hora = get_int("Hora (8-11 ou 14-17): ");

    int minuto = get_int("Minuto (0 ou 30): ");

    // Validação do horário de atendimento
    bool minuto_valido = (minuto == 0 || minuto == 30);
    bool horario_manha_valido = (hora >= 8 && hora < 12); // Válido de 8:00 a 11:30
    bool horario_tarde_valido = (hora >= 14 && hora < 18); // Válido de 14:00 a 17:30

    if (!minuto_valido || (!horario_manha_valido && !horario_tarde_valido)) {
        printf("ERRO: Horario invalido! Permitido: 08:00 as 11:30 e 14:00 as 17:30, em intervalos de 30 minutos.\n");
        return;
    }

    if (!verifica_disponibilidade(listaConsultas, medico_da_consulta, paciente_da_consulta, dia, mes, hora, minuto)) {
        return;
    }

    novo_node->paciente = paciente_da_consulta;

    novo_node->medico = medico_da_consulta;

    novo_node->data[0] = dia;
    novo_node->data[1] = mes;

    novo_node->horario[0] = hora;
    novo_node->horario[1] = minuto;

    novo_node->agendadaFlag = MARCADA;

    strcpy(novo_node->descricao, "Descricao a ser preenchida.");

    printf("\nConsulta agendada com sucesso!\n");
}

Consultas* insere_consulta(Consultas* l, Medico* listaMedico, Paciente* listaPaciente){
    Consultas* novo_node;
    novo_node = (Consultas*)malloc(sizeof(Consultas));
    novo_node->paciente = NULL; 

    input_consulta(novo_node, listaMedico, listaPaciente, l);

    // Se a função input_consultas retornar sem preencher (erro)
    if(novo_node->paciente == NULL){
        free(novo_node);
        return l;
    }

    novo_node->prox = l;
    novo_node->ante = NULL;

    if (l != NULL)
        l->ante = novo_node;
    return novo_node;
}

void listar_consultas (Consultas* l) {
    if (l == NULL) {
        printf("\nNao ha consultas agendadas.\n");
        return;
    }

    printf("\nImpressao das consultas.\n");
    Consultas* p = l;
    while (p != NULL) {
        printf("Paciente: %s - CPF: %s\n", p->paciente->nome, p->paciente->cpf);
        printf("Medico: %s - Especialidade: %s\n", p->medico->nome, p->medico->especialidade);
        printf("Data: %02d/%02d\n", p->data[0], p->data[1]);
        printf("Horario: %02d:%02d\n", p->horario[0], p->horario[1]);
        printf("---------------------------\n");
        p = p->prox;
    }
}

Consultas* desmarcar_consulta(Consultas* l) {
    printf("\nDesmarcar Consulta\n");

    char cpf_busca[MAX_STRING_SIZE];
    get_string("Digite o CPF do paciente: ", cpf_busca, MAX_STRING_SIZE);

    printf("Digite a data da consulta a ser desmarcada:\n");
    int dia_busca = get_int("Dia: ");
    int mes_busca = get_int("Mes: ");

    printf("Digite o horario da consulta a ser desmarcada:\n");
    int hora_busca = get_int("Hora: ");
    int min_busca = get_int("Minuto: ");

    Consultas* p = l;

    while (p != NULL) {
        if (strcmp(p->paciente->cpf, cpf_busca) == 0 &&
            p->data[0] == dia_busca &&
            p->data[1] == mes_busca &&
            p->horario[0] == hora_busca &&
            p->horario[1] == min_busca)
        {
            // Remover primeiro nó da lista
            if (p->ante == NULL) {
                l = p->prox;
                if (l != NULL) {
                    l->ante = NULL;
                }
            }
            // Remover meio ou fim da lista
            else {
                p->ante->prox = p->prox;
                if (p->prox != NULL) {
                    p->prox->ante = p->ante;
                }
            }

            free(p);
            printf("\nConsulta desmarcada com sucesso!\n");
            return l;
        }
        p = p->prox;
    }

    printf("\nNenhuma consulta encontrada para os dados informados.\n");
    return l;
}

void realizar_consulta(Consultas* l) {
    printf("\nRealizar Consulta\n");

    char cpf_busca[MAX_STRING_SIZE];
    get_string("Digite o CPF do paciente que esta sendo atendido: ", cpf_busca, MAX_STRING_SIZE);

    printf("Digite a data e horario da consulta:\n");
    int dia_busca = get_int("Dia: ");
    int mes_busca = get_int("Mes: ");
    int hora_busca = get_int("Hora: ");
    int min_busca = get_int("Minuto: ");

    Consultas* p = l;

    while (p != NULL) {
        if (strcmp(p->paciente->cpf, cpf_busca) == 0 &&
            p->data[0] == dia_busca && p->data[1] == mes_busca &&
            p->horario[0] == hora_busca && p->horario[1] == min_busca)
        {
            // Checa se a consulta tá realmente agendada para ser realizada
            if (p->agendadaFlag == MARCADA) {
                p->agendadaFlag = REALIZADA;
                printf("Status da consulta alterado para 'REALIZADA'.\n");

                // Descrição é preenchida no momento da consulta
                printf("Por favor, insira a descricao da consulta (exames, medicamentos, etc.):\n");
                get_string("Descricao: ", p->descricao, MAX_STRING_SIZE);

                printf("\nConsulta finalizada e descricao salva com sucesso!\n");
                return;
            } else if (p->agendadaFlag == REALIZADA) {
                printf("\nERRO: Esta consulta ja foi realizada anteriormente.\n");
                return;
            }
        }
        p = p->prox;
    }
    printf("\nNenhuma consulta AGENDADA foi encontrada para os dados informados.\n");
}

void relatorio_consultas_dia(Consultas* l) {
printf("\nR1: Consultas Agendadas por Dia\n");

    int dia_busca = get_int("Digite o dia que deseja consultar: ");
    int mes_busca = get_int("Digite o mes: ");

    Consultas* p = l;
    int consultas_encontradas = 0;

    printf("\n-- Consultas agendadas para %02d/%02d --\n", dia_busca, mes_busca);

    while (p != NULL) {

        if (p->data[0] == dia_busca && p->data[1] == mes_busca && p->agendadaFlag == MARCADA) {

            printf("----------------------------------\n");
            printf("Horario: %02d:%02d\n", p->horario[0], p->horario[1]);
            printf("Paciente: %s\n", p->paciente->nome);
            printf("Medico: %s - Especialidade: %s\n", p->medico->nome, p->medico->especialidade);
            consultas_encontradas++;
        }
        p = p->prox;
    }

    if (consultas_encontradas == 0) {
        printf("\nNenhuma consulta AGENDADA foi encontrada para esta data.\n");
    } else {
        printf("----------------------------------\n");
        printf("Total: %d consulta(s) agendada(s).\n", consultas_encontradas);
    }

}