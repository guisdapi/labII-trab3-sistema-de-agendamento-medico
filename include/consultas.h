#ifndef CONSULTAS_H
#define CONSULTAS_H

#include <stdbool.h>
#include "pacientes.h"
#include "medicos.h"

typedef struct Consultas{
    Paciente *paciente;
    Medico *medico;
    int data;
    int horario;
    bool agendadaFlag;
    char descricao[MAX_STRING_SIZE];
}Consultas;

#endif