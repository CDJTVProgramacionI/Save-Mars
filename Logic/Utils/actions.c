#include "utils.h"
#include "../../Frontend/frontend.h"
#include "../Structs/structs.h"

// Acciones para obstáculos
nave accionobstaculo(char op, nave jugador, objeto *objeto_actual, int distancia)
{
    switch (op)
    {
    // Seguir adelante
    case 's':
    case 'S':
        if (distancia <= objeto_actual->maxDist - 2000 || (distancia < objeto_actual->maxDist && jugador.velocidad >= (MAXVEL[nivel][1] * 1000)))
        {
            jugador.capsvid = 0;
            printf("Se ha estrellado con el %s\n", objeto_actual->nombre);
        }
        else
            jugador.dist += 25;
        break;
    // Evitar un obstaculo
    case 'E':
    case 'e':
        if (distancia >= objeto_actual->maxDist - 2000)
            printf("Se esquivo el %s\n", objeto_actual->nombre);
        else
        {
            printf("Se ha estrellado con el %s\n", objeto_actual->nombre);
            jugador.capsvid = 0;
        }
        jugador.dist += distancia;
        // contdecisiones++;
        break;
    // Destruir un obstaculo
    case 'D':
    case 'd':
        // Un planeta con vida, no se puede destruir
        if (strcmp(BRIGHT_GREEN "PLANETA CON VIDA", objeto_actual->nombre) == 0)
        {
            printf("Se ha estrellado con el %s\n", objeto_actual->nombre);
            jugador.capsvid = 0;
        }
        else if (distancia <= (objeto_actual->maxDist - 2000) && jugador.velocidad >= (MAXVEL[nivel][1] * 1000))
        {
            printf("Se destruyo el %s\n", objeto_actual->nombre);
            jugador.capsvid -= objeto_actual->vidasCorrecto;
            jugador.misiles -= objeto_actual->misilesCorrecto;
        }
        else
        {
            if (distancia > (objeto_actual->maxDist - 2000) && distancia < objeto_actual->maxDist && jugador.velocidad >= (MAXVEL[nivel][1] * 1000))
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
        }
        //|contdecisiones++;
        jugador.dist += distancia;
        break;
    default:
        printf("No presiono una opcion correcta.\n");
        break;
    }
    return;
}

// Acciones para capsulas

// Input - validación