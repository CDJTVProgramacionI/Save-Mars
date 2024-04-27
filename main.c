#include "Data/data.h"
#include "Frontend/frontend.h"
#include "Logic/Levels/levels.h"
#include "Logic/Utils/utils.h"
#include "Logic/Structs/structs.h"
#include <stdio.h>

void main()
{
    nave jugador = {0,0,0,0,0};
    save_results(1, &jugador, "Ganó");
}