#include "Data/data.h"
#include "Frontend/frontend.h"
#include "Logic/Levels/levels.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void imprimirUltimaBitacora()
{
    FILE *bitacora = fopen(BINNACLE_DIR, "r");
    if(bitacora == NULL)
    {
        printf("Necesitas jugar primero\n");
        return;
    }

    printf("----------------- BITÁCORA -----------------------\n");
    int* data = read_n_outputs(bitacora, BINNACLE_OUTPUTS);
    while (data != NULL)
    {
        printf("**********************************************\n");
        printf("Nivel: %d, turno: %d\n", data[2], data[3]);
        printf("Distancia alcanzada: %d\n", data[0]);
        printf("Velocidad del turno: %d\n", data[1]);
        data = read_n_outputs(bitacora, BINNACLE_OUTPUTS);
    }
    fclose(bitacora);    
}

void imprimirHistorico()
{
    FILE *archivo = fopen(RESULT_DIR, "r");
    int juegos = 1;

    if(archivo == NULL)
    {
        printf("Necesitas jugar primero\n");
        return;
    }

    int* data = read_n_outputs(archivo, RESULT_OUTPUTS);    

    printf("----------------- HISTÓRICO DE JUEGOS -----------------------\n");
    while(data != NULL)
    {
        printf("*********************************************************\n");
        printf("Juego: %d\n", juegos);
        printf("Capsulas de vida finales: %d\n", data[0]);
        printf("Misiles finales: %d\n", data[1]);
        printf("Objetos de interés capturados: %d\n", data[2]);
        printf("Resultado del juego: %s\n", data[3] == 1 ? "Ganó" : "Perdió");
        if(juegos%5 == 0)
        {
            entercontinuar();
            printf("----------------- HISTÓRICO DE JUEGOS -----------------------\n");
        }
        juegos++;
        data = read_n_outputs(archivo, RESULT_OUTPUTS);
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
                // Imprimir historico de juegos
                imprimirHistorico();
                break;
            case '3':
                // Imprimir última bitácora
                imprimirUltimaBitacora();
                break;
            case '4': // Salir
                printf("¡Gracias por jugar!\n");
                break;
            default:
                printf("Opción no válida\n");
                break;
        }

        entercontinuar();
    } while (opc != '4');
}