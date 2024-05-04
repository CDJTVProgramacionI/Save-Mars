#ifndef DATA_H
#define DATA_H

#define BINNACLE_DIR "bitacora.csv"
#define RESULT_DIR "resultados.csv"
#define BINNACLE_OUTPUTS 3
#define RESULT_OUTPUTS 5

#include "../Logic/Structs/structs.h"
#include <stdio.h>

int* read_n_outputs(const char*, int);

void new_binnacle();
void update_binnacle(nave*, int);

void save_results(nave*, int);


#endif