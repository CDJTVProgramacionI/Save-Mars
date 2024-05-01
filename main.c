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
    pantallaprincipal();
    
    do
    {
        //Presentar menú
        opc = menu();
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

        entercontinuar();
    } while (opc != '4');
}