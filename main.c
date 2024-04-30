#include "Data/data.h"
#include "Frontend/frontend.h"
#include "Logic/Levels/levels.h"
#include "Logic/Utils/utils.h"
#include "Logic/Structs/structs.h"

void main()
{
    // Declarar variables
    int juego = 1;
    char opc;

    // Pantalla principal

    // Menu

    do
    {
        switch (opc)
        {
            case '1':
                // Juego nuevo
                break;
            case '2':
                // Imprimir última bitácora
                break;
            case '3':
                // Imprimir historico de juegos
                break;
            case '4': // Salir
                break;
            default:
                printf("Opción no válida");
                break;
        }

        //Enter para borrar
    } while (opc != '4');

    //Este es un comentario
    //cambios
    //cambios
}