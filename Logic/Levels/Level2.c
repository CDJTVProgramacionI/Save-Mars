#include "levels.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#include "../../Frontend/frontend.h"
#include "../Structs/structs.h"
#include "../../Data/data.h"
#include "../Utils/utils.h"

#define MAXMISILES 7800
#define MAXVIDAS 1900
#define MINMISILES 7100
#define MINVIDAS 1500
#define MAXVEL 20000
#define NIVEL 1
#define MAXOBJETOS 2

void nivel2()
{
    short int contdecisiones = 1;
    int distancia, supera = 0;
    objeto *objeto_actual;
    char op = 'c';
    int *dist_obstaculos = distanciazar();

    //Crear bitácora para el nivel
    new_binnacle();

    // Datos del jugador
    nave jugador = {MAXVIDAS, MAXMISILES, 0, MAXVEL, 0};

    // Obstáculos por nivel
    objeto *objetosPorNivel = (objeto *)calloc(MAXOBJETOS, sizeof(objeto));

    // Crear objetos nivel 2
    objetosPorNivel[0].esObstaculo = 0;
    objetosPorNivel[0].nombre = BRIGHT_RED "OBJETO DE INTERES";
    objetosPorNivel[0].maxDist = 4000;
    objetosPorNivel[0].vidasCorrecto = 10;
    objetosPorNivel[0].vidasIncorrecto = 7;

    objetosPorNivel[1].esObstaculo = 1;
    objetosPorNivel[1].nombre = BLUE "ASTEROIDE";
    objetosPorNivel[1].maxDist = 8000;
    objetosPorNivel[1].misilesCorrecto = 60;
    objetosPorNivel[1].misilesIncorrecto = 40;
    objetosPorNivel[1].vidasCorrecto = 30;
    objetosPorNivel[1].vidasIncorrecto = 20;

    imprimir_instrucciones_nivel(NIVEL, MAXVIDAS, MAXMISILES, MAXMISILES, MINVIDAS, objetosPorNivel);

    while (jugador.misiles >= MINMISILES && jugador.capsvid >= MINVIDAS && contdecisiones <= 7)
    {
        // Si ya avanzó 100 km, variar la velocidad aleatoriamente
        if (jugador.dist - supera >= 100)
        {
            jugador.velocidad = velocidad(9, 20);
            supera=jugador.dist;
        }

        // Calcular distancia
        distancia = (dist_obstaculos[contdecisiones - 1]) * 1000 - jugador.dist;

        // Display
        display(jugador);

        // Generar objeto al azar si la última decisión fue capturar, destruir o esquivar
        if(tolower(op) == 'c' || tolower(op) == 'd' || tolower(op) == 'e')
        {
            objeto_actual = objetoaleatorio(objetosPorNivel, MAXOBJETOS);
        }

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
                        jugador = seguir_adelante_obstaculo(distancia, objeto_actual, jugador, MAXVEL);
                        break;
                    // Evitar un obstáculo
                    case 'E':
                    case 'e':
                        jugador = evitar_obstaculo(distancia, objeto_actual, jugador);
                        contdecisiones++;
                        break;
                    // Destruir un obstáculo
                    case 'D':
                    case 'd':
                        jugador = destruir_obstaculo(distancia, objeto_actual, jugador, MAXVEL);
                        contdecisiones++;
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
                        jugador = capturar_capsula(distancia, objeto_actual, jugador);
                        contdecisiones++;
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
        update_binnacle(&jugador, NIVEL + 1, contdecisiones-1);
    }

    free(objetosPorNivel);
    free(dist_obstaculos);

    // Compara la cantidad de misiles y de capsulas restantes y define si pierdes o ganas
    if (jugador.misiles >= MINMISILES && jugador.capsvid >= MINVIDAS)
    {
        save_results(&jugador, 1);
        printf("Ganaste el nivel\n");
        entercontinuar();
        nivel3();
    }
    else
    {
        save_results(&jugador, 0);
        if(perder(jugador) == 's')
        {
            nivel2();
        }
        else
        {
            finalizarJuego();
        }
    }
}