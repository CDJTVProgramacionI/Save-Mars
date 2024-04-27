#ifndef DATA_H
#define DATA_H

#define BINNACLE_DIR "bitacora.csv"
#define RESULT_DIR

#include "../Logic/Structs/structs.h"
#include <stdio.h>

void new_binnacle();
void update_binnacle(nave*, int);
int* read_n_outputs(const char*, int);

void save_results(int, nave*, char*);


#endif