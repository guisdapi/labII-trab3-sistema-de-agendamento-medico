#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "projects.h"

static const char *LISTA_HORARIOS[HORARIOS] = {
    "08:00", "08:30", "09:00", "09:30", "10:00", "10:30", 
    "11:00", "11:30", "12:00", "14:00", "14:30", "15:00", 
    "15:30", "16:00", "16:30", "17:00", "17:30", "18:00"
};

Consultas* cria_consulta(){
    return NULL;
}

bool consulta_pode_ser_agendada(Consultas* consulta, int dia, int mes, int horario){
    Consultas* p = consulta;
    //vai pro começo da lista  
    while(p != NULL)
        p = p->ante;
    
    while(p != NULL){
        if(p->data[0] == dia && p->data[1] == mes){
            if(strcmp(LISTA_HORARIOS[horario], p->horario) == 0)
                return false;
        }
        p = p->prox;
    }
    return true;
}

void print_horarios_disponiveis(){
    printf("tem q fazer essa func aqui\n=\n=\n=\n");
}

bool procura_consulta_disponivel(Consultas* consulta){
    int dia, mes, horario;
    do{
        mes = get_int("Em que mês deseja marcar a consulta?\n");
        if(mes < 1 || mes > 12)
            printf("Insira um mês válido [1 - 12]\n");
    }while(mes < 1 || mes > 12);

    do{
        dia = get_int("Em que dia do mês deseja marcar a consulta?\n");
        if(dia < 1 || dia > 30)
            printf("Insira um dia válido [1 - 30]\n");
    }while(dia < 1 || dia > 30);

    print_horarios_disponiveis();
    //horario é um int de 0 a 17 que corresponde aos horarios
    do{
        horario = get_int("Digite o código [] dos horário disponíveis\n");
        if(horario < 0 || horario > 17)
            printf("Insira um horário válido [0 - 17]");
    }while(horario < 1 || horario > 17);

    //Procura se a consulta pode ser marcada
    if(consulta_pode_ser_agendada(consulta, dia, mes, horario)){
        consulta->data[0] = dia;
        consulta->data[1] = mes;
        consulta->horario = LISTA_HORARIOS[horario];
        return true;
    }
    return false;

}

Consultas* input_consulta(Consultas* novo_node, Medico* listaMedico, Paciente* listaPaciente){
    printf("Criando consulta...\n");
    Medico* medico_da_consulta;
    Paciente* paciente_da_consulta;
    char buffer[MAX_STRING_SIZE];

    do{
        get_string("Insira o nome do médico: \n", buffer, MAX_STRING_SIZE);
        string_to_upper(buffer);
        medico_da_consulta = procura_medico(listaMedico, buffer);
        if(medico_da_consulta == NULL){
            printf("Médico não encontrado, confira se digitou o nome corretamente\n");
    }
    }while(medico_da_consulta == NULL);
    novo_node->medico = medico_da_consulta;

    do{
        get_string("Insira o CPF do paciente: \n", buffer, MAX_STRING_SIZE);
        paciente_da_consulta = procura_paciente(listaPaciente, buffer);
        if(paciente_da_consulta == NULL){
            printf("Paciente não encontrado, confira se digitou o cpf corretamente\n");
    }
    }while(paciente_da_consulta == NULL);
    novo_node->paciente = paciente_da_consulta;

    get_string("Insira o convênio utilizado: \n", buffer, MAX_STRING_SIZE);
    strcpy(novo_node->convenio, buffer);

    if(procura_consulta_disponivel(novo_node))
        printf("Data agendada com sucesso\n");
    else
        printf("Já existe uma consulta marcada nessa data\n");
    
    novo_node->agendadaFlag = MARCADA;
    return novo_node;
}

Consultas* insere_consulta(Consultas* l, Medico* listaMedico, Paciente* listaPaciente){
    Consultas* novo_node;
    novo_node = (Consultas*)malloc(sizeof(Consultas));

    novo_node = input_consulta(novo_node, listaMedico, listaPaciente);

    novo_node->prox = l;
    novo_node->ante = NULL;

    if(l != NULL)
        l->ante = novo_node;
    return novo_node;
}
