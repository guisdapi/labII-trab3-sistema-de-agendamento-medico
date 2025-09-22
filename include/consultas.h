#ifndef CONSULTAS_H
#define CONSULTAS_H

#include <stdbool.h>
#include "pacientes.h"
#include "medicos.h"

typedef struct Consultas{
    Paciente *paciente;
    Medico *medico;
    int data[2];
    int horario[2];
    int agendadaFlag; // 0 para livre, 1 para marcada, 2 para realizada
    char descricao[MAX_STRING_SIZE];
    struct Consultas *prox;
    struct Consultas *ante;
}Consultas;

#endif