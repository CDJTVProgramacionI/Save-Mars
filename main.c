#include "Data/data.h"
#include "Frontend/frontend.h"
#include "Logic/Levels/levels.h"
#include "Logic/Utils/utils.h"
#include "Logic/Structs/structs.h"
#include <time.h>

void main()
{
    // Declarar variables
    int juego = 1;
    char opc;

    // Establecer la semilla para números aleatorios
    // La función time() nos permite que sea más aleatorio el número
    srand(time(0));

    //configurar consola
    setup_console();

    // Pantalla principal
    pantallaprincipal();
    
    do
    {
        //Presentar menú
        opc = menu();
        switch (opc)
        {
            case '1':
                //Comenzar un juego nuevo en el nivel 1
                nivel1();
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
                printf("Opción no válida\n");
                break;
        }

        entercontinuar();
    } while (opc != '4');
}