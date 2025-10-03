#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projects.h"

Consultas* cria_consulta(){
    return NULL;
}

void input_consulta(Consultas* novo_node, Medico* listaMedico, Paciente* listaPaciente){
    printf("Criando consulta...\n");
    char buffer[MAX_STRING_SIZE];
    get_string("Insira o nome do médico: \n", buffer, MAX_STRING_SIZE);
    string_to_upper(buffer);
    Medico* medico_da_consulta = procura_medico(listaMedico, buffer);
    if(medico_da_consulta == NULL){
        printf("Médico não encontrado, confira se digitou o nome corretamente\n");
        return;
    }
    get_string("Insira o CPF do paciente: \n", buffer, MAX_STRING_SIZE);
    Paciente* paciente_da_consulta = procura_paciente(listaPaciente, buffer);
    if(paciente_da_consulta == NULL){
        printf("Paciente não encontrado, confira se digitou o cpf corretamente\n");
        return;
    }
    
}

Consultas* insere_consulta(Consultas* l, Medico* listaMedico, Paciente* listaPaciente){
    Consultas* novo_node;
    novo_node = (Consultas*)malloc(sizeof(Consultas));

    input_consulta(novo_node, listaMedico, listaPaciente);

    novo_node->prox = l;
    novo_node->ante = NULL;

    if(l != NULL)
        l->ante = novo_node;
    return novo_node;
}
