#include "utils.h"
#include "../../Frontend/frontend.h"
#include "../Structs/structs.h"

nave seguir_adelante_obstaculo(int distancia, objeto *objeto_actual, nave jugador, int maxvel)
{
    if (distancia <= objeto_actual->maxDist - 2000 || (distancia < objeto_actual->maxDist && jugador.velocidad >= maxvel))
    {
        jugador.capsvid = 0;
        printf("Se ha estrellado con el %s\n", objeto_actual->nombre);
    }
    else
        jugador.dist += 25;

    return jugador;
}

nave evitar_obstaculo(int distancia, objeto *objeto_actual, nave jugador)
{
    if (distancia >= objeto_actual->maxDist - 2000)
        printf("Se esquivo el %s\n", objeto_actual->nombre);
    else
    {
        printf("Se ha estrellado con el %s\n", objeto_actual->nombre);
        jugador.capsvid = 0;
    }
    jugador.dist += distancia;

    return jugador;
}

nave destruir_obstaculo(int distancia, objeto *objeto_actual, nave jugador, int maxvel)
{
    if (distancia <= (objeto_actual->maxDist - 2000) && jugador.velocidad >= maxvel)
    {
        printf("Se destruyo el %s\n", objeto_actual->nombre);
        jugador.capsvid -= objeto_actual->vidasCorrecto;
        jugador.misiles -= objeto_actual->misilesCorrecto;
    }
    else if (distancia > (objeto_actual->maxDist - 2000) && distancia < objeto_actual->maxDist && jugador.velocidad >= maxvel)
    {
        printf("Debiste haber esquivado\n");
        jugador.capsvid = 0;
    }
    else
    {
        printf("No has podido destruir el %s\n", objeto_actual->nombre);
        jugador.capsvid -= objeto_actual->vidasIncorrecto;
        jugador.misiles -= objeto_actual->misilesIncorrecto;
    }
    jugador.dist += distancia;
    return jugador;
}

// Acciones para capsulas
nave capturar_capsula(int distancia, objeto* objeto_actual, nave jugador)
{
    if (distancia <= objeto_actual->maxDist)
    {
        printf("Objeto capturado\n");
        jugador.capsvid += objeto_actual->vidasCorrecto;
    }
    else 
    {
        printf("Objeto no capturado\n");
        jugador.capsvid -= objeto_actual->vidasIncorrecto;
    }
    jugador.dist += distancia;
}