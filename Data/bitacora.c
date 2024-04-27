#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "../Logic/Structs/structs.h"

void new_binnacle()
{
    FILE *binnacle = fopen(BINNACLE_DIR, "w");

    if (binnacle != NULL)
    {
        fputs("0,0,0", binnacle);
    }
    else // Hubo un error al abrir el archivo
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }

    fclose(binnacle);
}

void update_binnacle(nave* jugador, int nivel)
{
    FILE *binnacle = fopen(BINNACLE_DIR, "w");

    if (binnacle != NULL)
    {
        // Datos de la bitácora
        fprintf(binnacle, "%d,%d,%d", jugador->dist, jugador->velocidad, nivel);
    }
    else // Hubo un error al abrir el archivo
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }

    fclose(binnacle);
}