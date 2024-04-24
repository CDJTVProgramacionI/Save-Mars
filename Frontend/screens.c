#include "frontend.h"

// Pantalla principal

// Instrucciones generales

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
}

// Display