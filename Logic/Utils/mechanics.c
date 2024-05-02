#include "utils.h"
#include "../Structs/structs.h"
#include <stdlib.h>

//Variar velocidad aleatoriamente
int velocidad(int amplitud, int valor_min)
{
    return (rand() % amplitud + valor_min) * 1000;
}
// Generar obstáculos aleatorios
objeto* objetoaleatorio(int nivel, objeto *objetosPorNivel, int max_objetos)
{
    return &objetosPorNivel[rand()%max_objetos];
}

// Generar distancias
int* distanciazar()
{
    int *distobst = (int*)malloc(7*sizeof(int));
    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            distobst[0] = (rand() % 8) + 5;
        }
        else
        {
            distobst[i] = (rand() % 8) + (distobst[i - 1]) + 1;
        }
    }

    return distobst;
}