#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

long unsigned int GetIndexAgent(FlagAgent *Liste, long unsigned int ID)
{
    int i=-1, index = -1;
    do
    {
        i++;
        if(ID == GetAgent(Liste, i)->a_ID)
        {
            index = i;
        }
    }while((i<Liste->a_Taille)&&(ID != GetAgent(Liste, i)->a_ID));

    if(index == -1)
        {
        return NULL;
        }
        else
        {
        return index;
        }
}

