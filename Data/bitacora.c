#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "../Logic/Structs/structs.h"

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

void update_binnacle(nave* jugador, int nivel)
{
    FILE *binnacle = fopen("bitacora.txt", "w");

    if (binnacle != NULL)
    {
        // Datos de la bitácora
        fprintf(binnacle, "Velocidad: %d\n", jugador->velocidad);
        fprintf(binnacle, "Distancia: %d\n", jugador->dist);
        fprintf(binnacle, "Nivel: %d\n", nivel);
    }
    else // Hubo un error al abrir el archivo
    {
        printf("Ha ocurrido un error!");
        exit(0);
    }

    fclose(binnacle);
}

char** read_binnacle()
{
    FILE *binnacle = fopen("bitacora.txt", "r");

    char* file_lines[3];

    // Se encontró el archivo de la bitácora
    if (binnacle != NULL)
    {
        for(int i = 0; i < 3 && !feof(binnacle); i++)
        {
            file_lines[i] = read_line(binnacle);
        }
    }

    return file_lines;
}

char *read_line(FILE *file)
{
    char actual;
    char *line = NULL;
    int tam = 1;
    do
    {
        actual = fgetc(file);
        // Crear espacio para añadir un caracter
        line = (char *)realloc(line, tam * sizeof(char));
        if (line != NULL)
        {
            line[tam - 1] = actual; //Añadir caracter leído
        }
        else
        {
            printf("Ha ocurrido un error!");
            exit(0);
        }
        tam++;
    } while (!feof(file) && actual != '\n');
}
