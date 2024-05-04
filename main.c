#include "Data/data.h"
#include "Frontend/frontend.h"
#include "Logic/Levels/levels.h"
#include "Logic/Structs/structs.h"
#include <time.h>
#include <stdio.h>

void imprimirUltimaBitacora()
{
    FILE *bitacora = fopen(BINNACLE_DIR, "r");
    printf("----------------- BITÁCORA -----------------------");
    while (!feof(bitacora))
    {
        printf("**********************************************");
        int* data = read_n_outputs(BINNACLE_DIR, BINNACLE_OUTPUTS);
        printf("Nivel jugado: %d", data[2]);
        printf("Distancia alcanzada: %1", data[0]);
        printf("Velocidad del turno; %d", data[1]);
    }
    fclose(bitacora);    
}

void main()
{
    // Declarar variables
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