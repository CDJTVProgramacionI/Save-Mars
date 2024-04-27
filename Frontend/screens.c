#include "frontend.h"
#include <stdio.h>
#include <conio.h>

// Pantalla principal

//Menú de opciones
char menu()
{
    char opc;
    do
    {
        printf("------ " MAGENTA "MENU" WHITE" ------\n");
        printf("1. Jugar\n");
        printf("2. Ver historial de resultados\n");
        printf("3. Bitácora del último juego\n");
        printf("4. Salir\n");
        opc = getch();
        if(opc < 49 || opc > 52) //Sí el número está fuera del rango 1-4
        {
            printf("Opción no válida\n");
            //TODO: ENTER PARA BORRAR
        }
    } while (opc < 49 || opc > 52); //Repetir mientras la opción esté fuera del rango 1-4

    return opc;
}

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