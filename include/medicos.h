#ifndef MEDICOS_H
#define MEDICOS_H

#define HORARIOS 18

typedef struct Consultas Consultas;

typedef struct Medico{
    char crm[MAX_STRING_SIZE];
    char nome[MAX_STRING_SIZE];
    char telefone[MAX_STRING_SIZE];
    char especialidade[MAX_STRING_SIZE];
    struct Medico *prox;
    struct Medico *ante;
} Medico;

Medico* cria_medico();
Medico* insere_medico(Medico* lista);
void imprime_medicos(Medico* lista);
Medico* procura_medico(Medico* lista, char* nome);
#endif