#ifndef CONSULTAS_H
#define CONSULTAS_H

#include <stdbool.h>

enum AgendadaFlag{
    MARCADA = 1,
    REALIZADA = 2
};

typedef struct Consultas{
    Paciente *paciente;
    Medico *medico;
    int data[2]; // dia / mes
    int horario[2];
    int agendadaFlag; // 0 para livre, 1 para marcada, 2 para realizada
    char convenio[MAX_STRING_SIZE];
    char descricao[MAX_STRING_SIZE];
    struct Consultas *prox;
    struct Consultas *ante;
}Consultas;

Consultas* cria_consulta();
bool verifica_disponibilidade(Consultas* lista_consultas, Medico* medico, Paciente* paciente, int dia, int mes, int hora, int minuto);
void input_consulta(Consultas* novo_node, Medico* listaMedico, Paciente* listaPaciente, Consultas* listaConsultas);
Consultas* insere_consulta(Consultas* l, Medico* listaMedico, Paciente* listaPaciente);
void listar_consulta(Consultas* consulta);
void listar_todas_consultas(Consultas* l);
Consultas* desmarcar_consulta(Consultas* l);
void realizar_consulta(Consultas* l);
void relatorio_consultas_dia(Consultas* l);
void relatorio_consultas_paciente(Consultas* l);
void relatorio_consulta_descricao(Consultas* l);
void relatorio_pacientes_especialidade(Consultas* l);
void relatorio_pacientes_medicos(Consultas* l);

#endif