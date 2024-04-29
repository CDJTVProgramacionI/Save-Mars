#include "utils.h"
//Mecánica de velocidad

//Generar obstáculos aleatorios

//Generar distancias
int distanciazar()   
{
    int distobst[7];
    for (int i =0;i<7;i++)
    {
        if(i==0)
        {
            distobst[0]=(rand()%8)+5;
        }
        else 
        {
            distobst[i]=(rand()%8)+(distobst[i-1])+1;
        }
    }

    return distobst;
}