#include <stdio.h>
#include <stdlib.h>
#include "projects.h"

int main() {
    
    Medico* lista = cria_medico();
    
    
    lista = insere_medico(lista);
    imprime_medicos(lista);

    return 0;
}