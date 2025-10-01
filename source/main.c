#include <stdio.h>
#include <stdlib.h>
#include "projects.h"

int main() {
    
    Medico* listaMedicos = cria_medico();
    Paciente* listaPaciente = cria_paciente();
    
    menu(listaMedicos, listaPaciente);
    return 0;
}