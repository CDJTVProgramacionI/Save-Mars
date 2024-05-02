#include "levels.h"
#include "../Structs/structs.h"
#include "../../Frontend/frontend.h"

void ganar(objeto *objetosPorNivel, int nivel)
{
    free(objetosPorNivel);
    printf("Ganaste el nivel %d\n", nivel);
    entercontinuar();
}

short perder(objeto *objetosPorNivel, int nivel)
{
    char op;

    printf("Perdiste\n");
    display(); //Mostrar últimos resultados

    // obtener input del usuario
    do
    {
        printf(WHITE "Deseas continuar? [s/n]\n");
        op = getch();
        printf("\e[1;1H\e[2J"); // Borrar pantalla

        if (op != 's' && op != 'S' && op != 'N' && op != 'n')
            printf("No presiono una opcion correcta\n");
    } while (op != 's' && op != 'S' && op != 'N' && op != 'n');

    //-1 es para salir del juego y volver al menú de inicio
    //0 es para repetir el nivel
    return op == 's' || op == 'S' ? 0 : -1;
}