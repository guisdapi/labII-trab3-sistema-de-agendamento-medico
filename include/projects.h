#ifndef PROJECTS_H
#define PROJECTS_H

#define MAX_STRING_SIZE 512

enum Status{
    INSERIR_MEDICO = 1,
    LISTAR_MEDICOS,
    INSERIR_PACIENTE,
    LISTAR_PACIENTES
};

#include "pacientes.h"
#include "medicos.h"
#include "consultas.h"
#include "lista.h"
#include "menu.h"
#include "helpers.h"

#endif