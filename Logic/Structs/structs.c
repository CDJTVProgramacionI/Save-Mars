#include "structs.h"
typedef struct
{
    int capsvid;
    int misiles;
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