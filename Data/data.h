#ifndef DATA_H
#define DATA_H

#define BINNACLE_DIR "bitacora.csv"
#define RESULT_DIR "resultados.csv"
#define BINNACLE_OUTPUTS 4
#define RESULT_OUTPUTS 4

#include "../Logic/Structs/structs.h"
#include <stdio.h>

int* read_n_outputs(FILE*, int);

void new_binnacle();
void update_binnacle(nave*, int, short);

void save_results(nave*, int);


#endif