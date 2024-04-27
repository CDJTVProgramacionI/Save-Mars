#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int get_number(FILE* file)
{
    char* num;
    int tam = 1;
    do
    {
        num = (char*)realloc(num, tam * sizeof(char));
        num[tam - 1] = fgetc(file);
        tam++;
    } while (!feof(file) && num[tam - 2] != ',');
    return atoi(num);
}

int* read_n_outputs(const char* dir, int output_size)
{

    int* data = calloc(output_size, sizeof(int));
    FILE *file = fopen(dir, "r");
    //leer números
    for(int i = 0; i < output_size; i++)
    {
        data[i] = get_number(file);
    }

    fclose(file);

    return data;
}