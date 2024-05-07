#ifndef UTILS_H
#define UTILS_H

#include "../Structs/structs.h"


//actions
nave seguir_adelante_obstaculo(int, objeto*, nave, int);
nave evitar_obstaculo(int, objeto* , nave);
nave destruir_obstaculo(int , objeto*, nave , int);
nave capturar_capsula(int , objeto* , nave);

//mechanics
int velocidad(int, int); //Varia velocidad
objeto* objetoaleatorio(objeto *, int);
int* distanciazar(); //generar distancia 

#endif