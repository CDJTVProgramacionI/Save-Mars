#include "data.h"
#include <stdio.h>
#include <stdlib.h>

//Obtener un número
int get_number(FILE *file)
{
    char *num = calloc(sizeof(char), 1);
    char actual = '\0';
    int tam = 1;

    while (!feof(file) && actual != ',' && actual !='\n')
    {
        actual = fgetc(file);
        num[tam - 1] = actual;
        tam++;
        //Añadir caracteres a arreglo dinámico
        num = (char *)realloc(num, tam * sizeof(char));
        if (num == NULL)
        {
            printf("Ha ocurrido un error");
            exit(1);
        }
    }

    return atoi(num);
}

//Leer del archivo la cantidad de entradas especificadas
int *read_n_outputs(FILE* file, int output_size)
{
    int *data = calloc(output_size, sizeof(int));

    //Verificar que no hayan errores
    if(data == NULL)
    {
        printf("Ha ocurrido un error");
        exit(1);
    }
    else
    {
        // Leer números
        for (int i = 0; i < output_size; i++)
        {
            data[i] = get_number(file);
            if(feof(file)) return NULL;
        }
    }

    return data;
}