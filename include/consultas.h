#ifndef CONSULTAS_H
#define CONSULTAS_H

enum AgendadaFlag{
    LIVRE = 0,
    MARCADA,
    REALIZADA,
};

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

Consultas* cria_consulta();
void input_consulta(Consultas* novo_node, Medico* lista);
Consultas* insere_consulta(Consultas* l, Medico* lista);

#endif