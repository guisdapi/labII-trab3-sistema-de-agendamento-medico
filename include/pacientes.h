#ifndef PACIENTES_H
#define PACIENTES_H

typedef struct Paciente{
    char cpf[MAX_STRING_SIZE];
    char nome[MAX_STRING_SIZE];
    char telefone[MAX_STRING_SIZE];
    struct Paciente *prox;
    struct Paciente *ante;
} Paciente;

Paciente* cria_paciente();
Paciente* insere_paciente(Paciente *lista);
void imprime_pacientes(Paciente *lista);

#endif