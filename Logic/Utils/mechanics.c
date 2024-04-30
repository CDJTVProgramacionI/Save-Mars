#include "utils.h"
// Mecánica de velocidad
int velocidad(int distancia, int a, int b)
{
    int vel = 0;
    // Si ya avanzó 100 km, variar la velocidad aleatoriamente
    if (distancia >= 100)
        vel = (rand() % a + b) * 1000;

    return vel;
}
// Generar obstáculos aleatorios

// Generar distancias
int distanciazar()
{
    int distobst[7];
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