#ifndef PACIENTES_H
#define PACIENTES_H

typedef struct Paciente{
    int cpf;
    char nome[MAX_STRING_SIZE];
    int telefone;
    struct Paciente *prox;
    struct Paciente *ante;
} Paciente;

#endif