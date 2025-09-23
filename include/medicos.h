#ifndef MEDICOS_H
#define MEDICOS_H

typedef struct Medico{
    int crm;
    char nome[MAX_STRING_SIZE];
    int telefone;
    char especialidade[MAX_STRING_SIZE];
    struct Medico *prox;
    struct Medico *ante;
} Medico;

Medico* cria_medico();
Medico* insere_medico(Medico* lista);

#endif