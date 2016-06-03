#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

long unsigned int GetIndexMission(FlagMission *Liste, long unsigned int ID)
{
    int i = -1, index = -1;
    do
    {
        i++;
        if(ID == GetMission(Liste, i)->a_ID)
        {
            index = i;
        }


    }while((i<Liste->a_Taille)&&(ID != GetMission(Liste, i)->a_ID));
    if(index == -1)
    {
        return NULL;
    }
    else
    {
        return index;
    }
}
