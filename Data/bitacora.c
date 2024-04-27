#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void new_binnacle()
{
    FILE *binnacle = fopen("bitacora.txt", "w");

    if (binnacle != NULL)
    {
        // Datos de la bitácora
        fputs("Velocidad: 0\n", binnacle);
        fputs("Distancia: 0\n", binnacle);
        fputs("Nivel: 0", binnacle);
    }
    else // Hubo un error al abrir el archivo
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }

    fclose(binnacle);
}

void update_binnacle(int new_values[3])
{
    FILE *binnacle = fopen("bitacora.txt", "w");

    if (binnacle != NULL)
    {
        // Datos de la bitácora
        fprintf(binnacle, "Velocidad: %d\n", new_values[0]);
        fprintf(binnacle, "Distancia: %d\n", new_values[1]);
        fprintf(binnacle, "Nivel: %d\n", new_values[2]);
    }
    else // Hubo un error al abrir el archivo
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }

    fclose(binnacle);
}
