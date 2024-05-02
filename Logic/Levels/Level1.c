#include "levels.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "../../Frontend/frontend.h"
#include "../Structs/structs.h"

#define MAXMISILES 8000
#define MAXVIDAS 2000
#define MINMISILES 7800
#define MINVIDAS 1900
#define MAXVEL 20000
#define NIVEL 0
#define MAXOBJETOS 3

short nivel1()
{
    short int contdecisiones = 1, siguiente_nivel = 0;
    int distancia, supera = 0;
    objeto *objeto_actual;
    char op = 'c';
    int *dist_obstaculos = distanciazar();

    // Datos del jugador
    nave jugador = {MAXVIDAS, MAXMISILES, 0, MAXVEL, 0};

    // Obstáculos por nivel
    objeto *objetosPorNivel = (objeto *)calloc(MAXOBJETOS, sizeof(objeto));

    //Crear objetos por nivel
    objetosPorNivel[0].esObstaculo = 0;
    objetosPorNivel[0].nombre = BRIGHT_RED "OBJETO DE INTERES";
    objetosPorNivel[0].maxDist = 6000;
    objetosPorNivel[0].vidasCorrecto = 5;
    objetosPorNivel[0].vidasIncorrecto = 3;

    objetosPorNivel[1].esObstaculo = 1;
    objetosPorNivel[1].nombre = BRIGHT_BLUE "PLANETA SIN VIDA";
    objetosPorNivel[1].maxDist = 10000;
    objetosPorNivel[1].misilesCorrecto = 50;
    objetosPorNivel[1].misilesIncorrecto = 25;
    objetosPorNivel[1].vidasCorrecto = 25;
    objetosPorNivel[1].vidasIncorrecto = 15;

    objetosPorNivel[2].esObstaculo = 1;
    objetosPorNivel[2].nombre = BRIGHT_GREEN "PLANETA CON VIDA";
    objetosPorNivel[2].maxDist = 10000;

    imprimir_instrucciones_nivel(NIVEL);

    while (jugador.misiles >= MAXMISILES && jugador.capsvid >= MAXVIDAS && contdecisiones <= 7)
    {
        // Si ya avanzó 100 km, variar la velocidad aleatoriamente
        if (jugador.dist - supera >= 100)
        {
            jugador.velocidad = velocidad(9, 12);
        }

        // Calcular distancia
        distancia = (dist_obstaculos[contdecisiones - 1]) * 1000 - jugador.dist;

        // Display
        display(jugador);

        // Generar objeto al azar
        objeto_actual = objetoaleatorio(NIVEL, objetosPorNivel, MAXOBJETOS);

        // Mostrar objeto generado
        printf("Un %s" WHITE " se encuentra a %d km de distancia\n", objeto_actual->nombre, distancia);

        // Si se generó un obstáculo
        if (objeto_actual->esObstaculo)
        {
            // Obtener input del usuario
            do
            {
                printf("¿Qué desea hacer?\n");
                printf("Presione [S] para seguir adelante, [E] para esquivar o [D] para destruir\n");
                op = getch();

                switch (op)
                {
                    case 's':
                    case 'S':
                        seguir_adelante_obstaculo(distancia, objeto_actual, jugador, 20);
                        break;
                    // Evitar un obstáculo
                    case 'E':
                    case 'e':
                        evitar_obstaculo(distancia, objeto_actual, jugador);
                        break;
                    // Destruir un obstáculo
                    case 'D':
                    case 'd':
                        destruir_obstaculo(distancia, objeto_actual, jugador, 20);
                        break;
                    default:
                        printf("No presionó una opción válida.\n");
                        break;
                }
            } while (op != 'e' && op != 'E' && op != 'D' && op != 'd' && op != 's' && op != 'S');
        }
        // Si se generó un objeto de interés
        else
        {
            // Obtener input del usuario
            do
            {
                printf("¿Qué desea hacer?\n");
                printf("Presione [C] para capturar y [S] para seguir adelante\n");
                op = getch();

                switch (op)
                {
                    // Decisiones para capturar o esquivar
                    case 'c':
                    case 'C':
                        capturar_capsula(distancia, objeto_actual, jugador);
                        break;
                    case 's':
                    case 'S':
                        // Se saltó la capsula por completo
                        if (distancia <= 25)
                        {
                            // Ir al siguiente obstáculo
                            op = 'c';
                            contdecisiones++;
                        }
                        jugador.dist += 25;
                        break;
                    default:
                        printf("No presionó una opcion correcta.\n");
                        break;
                }
            } while (op != 's' && op != 'S' && op != 'C' && op != 'c' && op != 's' && op != 'S');
        }

        entercontinuar();
    }

    // Compara la cantidad de misiles y de capsulas restantes y define si pierdes o ganas
    if (jugador.misiles >= MINMISILES && jugador.capsvid >= MINVIDAS)
    {
        ganar();
        siguiente_nivel = 1;
    }
    else
    {
        siguiente_nivel = perder();
    }

    return siguiente_nivel;
}