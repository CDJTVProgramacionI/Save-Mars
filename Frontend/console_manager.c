#include "frontend.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

static HANDLE stdoutHandle;
static DWORD outModeInit;

//Permitir que la consola de windows acepte colores y caracteres especiales
void setup_console()
{
    DWORD outMode = 0;
    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(stdoutHandle == INVALID_HANDLE_VALUE) {
        exit(GetLastError());
    }
    
    if(!GetConsoleMode(stdoutHandle, &outMode)) {
        exit(GetLastError());
    }

    outModeInit = outMode;
    
    // Enable ANSI escape codes
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if(!SetConsoleMode(stdoutHandle, outMode)) {
        exit(GetLastError());
    }

    setlocale(LC_ALL, "es_ES.UTF-8");
}  


//Enter para borrar
void entercontinuar()
{
    printf(WHITE "Presiona enter para continuar...");
    while (getch() != 13);
    printf("\e[1;1H\e[2J");
}