#ifndef DATA_H
#define DATA_H

#include "../Logic/Structs/structs.h"
#include <stdio.h>

char* read_line(FILE);

void new_binnacle();
void update_binnacle(nave*, int);
char** read_binnacle();

void save_results(int, nave*, char*);


#endif