#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"

int RechercherCrit(Critere *TabCritsRef,int *NbrCrits,long unsigned int IDcrit)
{
    int i=0;
    while (i<NbrCrits && TabCritsRef[i].a_ID!=IDcrit)
    {
        i++;
    }
    return i;
}
