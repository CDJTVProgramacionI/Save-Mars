#include "frontend.h"
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
    printf("                                     @@@@@@@@@@@@@@@@@@              PROGRAMACION I\n");
    printf("                                     @@@@.@......@.@@@@       Segundo examen departamental\n");
    printf("                                     @@@@.@......@.@@@@             Huerta Johana\n");
    printf("                                     @@@@.@@@@@@@@.@@@@             Garcia Viridiana\n");
    printf("                                   @@@@@..@......@..@@@@@           Garcia Tania\n");
    printf("                                  @@@@@...@.@..@.@....@@@@@         Gomez Camila\n");
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
    printf("------ " MAGENTA "MENU" WHITE " ------\n");
    printf("1. Jugar\n");
    printf("2. Ver historial de resultados\n");
    printf("3. Bitácora del último juego\n");
    printf("4. Salir\n");
    opc = getch();
    printf("\e[1;1H\e[2J"); //Borrar pantalla

    return opc;
}

// Instrucciones por nivel
void imprimir_instrucciones_nivel(int nivel)
{
    printf("NIVEL %d\n", nivel);
    printf("En este nivel, te enfrentaras a:\n");
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

    entercontinuar();
}

// Display
void display(int vida, int velocidad, int misiles)
{
    printf(MAGENTA "CAPS. VIDA: %d  ",vida);
    printf(WHITE "|" CYAN "  VELOCIDAD: %d km/h  ", velocidad);
    printf(WHITE "|" YELLOW "  MISILES: %d\n", misiles);

    printf(RESET);
}