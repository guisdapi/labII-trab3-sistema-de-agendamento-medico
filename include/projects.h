#ifndef PROJECTS_H
#define PROJECTS_H

#define MAX_STRING_SIZE 512

enum Status{
    SAIR = 0,
    INSERIR_MEDICO,
    LISTAR_MEDICOS,
    INSERIR_PACIENTE,
    LISTAR_PACIENTES,
    INSERIR_CONSULTA,
    LISTAR_CONSULTA,
    DESMARCAR_CONSULTA,
    REALIZAR_CONSULTA,
    RELATORIO_CONSULTAS_DIA
};

#include "pacientes.h"
#include "medicos.h"
#include "consultas.h"
#include "lista.h"
#include "menu.h"
#include "helpers.h"
#include <stdbool.h>

#endif