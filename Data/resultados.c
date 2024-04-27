#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "../Logic/Structs/structs.h"

void save_results(int num_juego, nave *jugador, char* resultado)
{
    FILE *results = fopen("resultados.txt", "a");
    if(results != NULL)
    {
        fprintf(results, "-------------------JUEGO #%d-----------------------------------------\n", num_juego);
        fprintf(results, "Capsulas de vida: %d\n", jugador->capsvid);
        fprintf(results, "Misiles: %d\n", jugador->misiles);
        fprintf(results, "Objetos Capturados: %d\n", jugador->objetosCapturados);
        fprintf(results, "Resultado del juego: %s\n", resultado);
    }
    else
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }
    fclose(results);
}