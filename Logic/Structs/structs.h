#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct
{
    int capsvid;
    int misiles;
    int objetosCapturados;
    int velocidad;
    int dist;
} nave;

typedef struct
{
    short int esObstaculo;
    char* nombre;
    int maxDist;
    int misilesCorrecto;
    int misilesIncorrecto;
    int vidasCorrecto;
    int vidasIncorrecto;
} objeto;

#endif