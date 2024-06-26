#include "levels.h"
#include "../Structs/structs.h"
#include "../../Frontend/frontend.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

char perder(nave jugador)
{
    char op;

    printf("Perdiste\n");
    display(jugador); // Mostrar últimos resultados

    // obtener input del usuario
    do
    {
        printf(WHITE "¿Deseas continuar? [s/n]\n");
        op = getch();
        printf("\e[1;1H\e[2J"); // Borrar pantalla

        if (op != 's' && op != 'S' && op != 'N' && op != 'n')
        {
            printf("No presionó una opción válida\n");
        }
            
    } while (op != 's' && op != 'S' && op != 'N' && op != 'n');

    return tolower(op);
}

void finalizarJuego()
{
    printf("FIN DEL JUEGO\n");
}