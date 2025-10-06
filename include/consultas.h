#ifndef CONSULTAS_H
#define CONSULTAS_H
#include <stdbool.h>

enum AgendadaFlag{
    LIVRE = 0,
    MARCADA,
    REALIZADA,
};

typedef struct Consultas{
    Paciente *paciente;
    Medico *medico;
    int data[2]; // dia / mes
    char *horario;
    int agendadaFlag; // 0 para livre, 1 para marcada, 2 para realizada
    char convenio[MAX_STRING_SIZE];
    char descricao[MAX_STRING_SIZE];
    struct Consultas *prox;
    struct Consultas *ante;
}Consultas;

Consultas* cria_consulta();
bool consulta_pode_ser_agendada(Consultas* consulta, int dia, int mes, int horario);
void print_horarios_disponiveis();
bool procura_consulta_disponivel(Consultas* consulta);
Consultas* input_consulta(Consultas* novo_node, Medico* listaMedico, Paciente* listaPaciente);
Consultas* insere_consulta(Consultas* l, Medico* listaMedico, Paciente* listaPaciente);

#endif