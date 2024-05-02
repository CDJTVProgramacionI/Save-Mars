#include "frontend.h"
#include "../Logic/Structs/structs.h"
#include <stdio.h>
#include <conio.h>

// Pantalla principal
void pantallaprincipal()
{
    printf(" ______     ______     __   __   ______           __    __     ______     ______     ______\n");
    printf("/\\  ___\\   /\\  __ \\   /\\ \\ / /  /\\  ___\\         /\\ \"-./  \\   /\\  __ \\   /\\  == \\   /\\  ___\\\n");
    printf("\\ \\___  \\  \\ \\  __ \\  \\ \\ \\'/   \\ \\  __\\         \\ \\ \\-./\\ \\  \\ \\  __ \\  \\ \\  __<   \\ \\___  \\\n");
    printf(" \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\__|    \\ \\_____\\        \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\/\\_____\\\n");
    printf("  \\/_____/   \\/_/\\/_/   \\/_/      \\/_____/         \\/_/  \\/_/   \\/_/\\/_/   \\/_/ /_/   \\/_____/\n\n");

    printf("                                            @@@@\n");
    printf("                                          @@@@@@@@\n");
    printf("                                          @@....@@\n");
    printf("                                         @@@.....@@\n");
    printf("                                         @@.@@@@.@@\n");
    printf("                                       @@@@......@@@@\n");
    printf("                                     @@@@@@@@@@@@@@@@@@              PROGRAMACIÓN I\n");
    printf("                                     @@@@.@......@.@@@@       Tercer examen departamental\n");
    printf("                                     @@@@.@......@.@@@@             Huerta Johana\n");
    printf("                                     @@@@.@@@@@@@@.@@@@             García Viridiana\n");
    printf("                                   @@@@@..@......@..@@@@@           García Tania\n");
    printf("                                  @@@@@...@.@..@.@....@@@@@         Gómez Camila\n");
    printf("                                 @@@@@....@.@..@.@.....@@@@         Rosas Daniel\n");
    printf("                               @@@@@......@.@..@.@......@@@@@\n");
    printf("                             @@@@@........@......@........@@@@@\n");
    printf("                             @@@@.........@@@@@@@@.........@@@@\n");
    printf("                             @@@@....@@..@@@@@@@@@@..@@....@@@@\n");
    printf("                              @@.@@@@@@.@....@@....@.@@@@@@.@@\n");
    printf("                              @@@@@@@@@@@....@@....@.@@@@@@@@@\n");
    printf("                                       @@@@@@@@@@@@@@\n");

    entercontinuar();
}

// Menú de opciones
char menu()
{
    char opc;
    printf("------ " MAGENTA "MENÚ" WHITE " ------\n");
    printf("1. Jugar\n");
    printf("2. Ver historial de resultados\n");
    printf("3. Bitácora del último juego\n");
    printf("4. Salir\n");
    opc = getch();
    printf("\e[1;1H\e[2J"); // Borrar pantalla

    return opc;
}

// Instrucciones por nivel
void imprimir_instrucciones_nivel(int nivel, int maxvidas, int maxmisiles, int minmisiles, int minvidas, objeto *objetosPorNivel)
{
    printf("NIVEL %d\n", nivel);
    printf("En este nivel, te enfrentarás a:\n");
    switch (nivel)
    {
    case 1:
        printf("Los " BRIGHT_GREEN "PLANETAS CON VIDA " WHITE "que no pueden ser destruidos\n");
        printf("y los " BRIGHT_BLUE "PLANETAS SIN VIDA " WHITE "que pueden ser destruidos.\n");
        break;
    case 2:
        printf("Los " BLUE "ASTEROIDES\n");
        break;
    case 3:
        printf("Los " PURPLE "HOYOS NEGROS\n");
        break;
    }

    printf(WHITE "Iniciaras con %d caps. de vida y %d misiles\n", maxvidas, maxmisiles);
    printf("Si la distancia entre la nave y un obstaculo esta entre %d y %d km se DEBE evadir el obstaculo\n", objetosPorNivel[1].maxDist - 2000, objetosPorNivel[1].maxDist);
    printf("Si la distancia entre un obstaculo y la nave es menor a %d km la nave choca y pierde el juego\n", objetosPorNivel[1].maxDist - 2000);
    printf("Si la distancia entre la nave y el obstaculo es mayor a %d km la nave sigue su camino\n", objetosPorNivel[1].maxDist);
    printf("Si la distancia entre nave y objeto de interes es menor o igual a %d km se ganan %d caps. de vida (No importa la velocidad)\n", objetosPorNivel[0].maxDist, objetosPorNivel[0].vidasCorrecto);
    printf("    - Si no se cumplen las condiciones se pierden %d capsulas de vida\n", objetosPorNivel[0].vidasIncorrecto);
    printf("La nave puede destruir obstaculos si la distancia es igual o menor a %d km\n", objetosPorNivel[1].maxDist - 2000);
    printf("    - Por cada obstaculo destruido se pierden %d caps. de vida y %d misiles\n", objetosPorNivel[1].vidasCorrecto, objetosPorNivel[1].misilesCorrecto);
    printf("    - Al intentar destruir un obstaculo sin respetar las condiciones se pierden %d caps. y %d misiles\n", objetosPorNivel[1].vidasIncorrecto, objetosPorNivel[1].misilesIncorrecto);
    printf("Pierdes si tienes menos de %d misiles o menos de %d caps. de vida\n", minmisiles, minvidas);

    entercontinuar();
}

// Display
void display(nave jugador)
{
    printf(MAGENTA "CAPS. VIDA: %d  ", jugador.capsvid);
    printf(WHITE "|" CYAN "  VELOCIDAD: %d km/h  ", jugador.velocidad);
    printf(WHITE "|" YELLOW "  MISILES: %d\n", jugador.misiles);

    printf(RESET);
}