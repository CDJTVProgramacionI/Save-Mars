#include "Data/data.h"
#include "Frontend/frontend.h"
#include "Logic/Levels/levels.h"
#include "Logic/Structs/structs.h"
#include <time.h>
#include <stdio.h>

void imprimirUltimaBitacora()
{
    FILE *bitacora = fopen(BINNACLE_DIR, "r");
    printf("----------------- BITÁCORA -----------------------\n");
    while (!feof(bitacora))
    {
        printf("**********************************************\n");
        int* data = read_n_outputs(bitacora, BINNACLE_OUTPUTS);
        printf("Nivel: %d, turno: %d\n", data[2], data[3]);
        printf("Distancia alcanzada: %d\n", data[0]);
        printf("Velocidad del turno: %d\n", data[1]);
    }
    fclose(bitacora);    
}

void imprimirHistorico()
{
    FILE *archivo = fopen(RESULT_DIR, "r");
    int juegos = 1;
    printf("----------------- HISTÓRICO DE JUEGOS -----------------------\n");
    while(!feof(archivo))
    {
        printf("*********************************************************\n");
        int* data = read_n_outputs(archivo, RESULT_OUTPUTS);
        printf("Juego: %d\n", juegos);
        printf("Capsulas de vida finales: %d\n", data[0]);
        printf("Misiles finales: %d\n", data[1]);
        printf("Objetos de interés capturados: %d\n", data[2]);
        printf("Resultado del juego: %s\n", data[2] == 1 ? "Ganó" : "Perdió");
        if(juegos%5 == 0)
        {
            entercontinuar();
        }
        juegos++;
    }
    fclose(archivo); 
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