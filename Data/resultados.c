#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "../Logic/Structs/structs.h"

void save_results(nave *jugador, int resultado)
{
    FILE *results = fopen(RESULT_DIR, "a");
    if(results != NULL)
    {
        fprintf(results, "%d,%d,%d,%d\n", jugador->capsvid, jugador->misiles, jugador->objetosCapturados, resultado);
    }
    else
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }
    fclose(results);
}