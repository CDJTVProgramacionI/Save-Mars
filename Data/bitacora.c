#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "../Logic/Structs/structs.h"

void new_binnacle()
{
    FILE *binnacle = fopen(BINNACLE_DIR, "w");

    fclose(binnacle);
}

void update_binnacle(nave* jugador, int nivel, short turno)
{
    FILE *binnacle = fopen(BINNACLE_DIR, "a");

    if (binnacle != NULL)
    {
        // Datos de la bitácora
        fprintf(binnacle, "%d,%d,%d,%d", jugador->dist, jugador->velocidad, nivel, turno);
    }
    else // Hubo un error al abrir el archivo
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }

    fclose(binnacle);
}