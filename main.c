#include "Data/data.h"
#include "Frontend/frontend.h"
#include "Logic/Levels/levels.h"
#include "Logic/Utils/utils.h"
#include "Logic/Structs/structs.h"
#include <stdio.h>

void main()
{
    new_binnacle();
    int data[3] = {1,2,3};
    update_binnacle(data);
}