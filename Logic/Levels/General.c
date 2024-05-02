#include "levels.h"
#include "../Structs/structs.h"
#include "../../Frontend/frontend.h"
#include <stdio.h>
#include <conio.h>

void ganar(objeto *objetosPorNivel)
{
    free(objetosPorNivel);
    printf("Ganaste el nivel\n");
    entercontinuar();
}

short perder(objeto *objetosPorNivel)
{
    char op;

    printf("Perdiste\n");
    display(); // Mostrar últimos resultados

    // obtener input del usuario
    do
    {
        printf(WHITE "¿Deseas continuar? [s/n]\n");
        op = getch();
        printf("\e[1;1H\e[2J"); // Borrar pantalla

        if (op == 'n' || op == 'N')
        {
            free(objetosPorNivel);
        }
        else if(op == 's' || op == 'S')
        {
            entercontinuar();
        }
        else
        {
            printf("No presionó una opción válida\n");
        }
            
    } while (op != 's' && op != 'S' && op != 'N' && op != 'n');

    //-1 es para salir del juego y volver al menú de inicio
    // 0 es para repetir el nivel
    return op == 's' || op == 'S' ? 0 : -1;
}