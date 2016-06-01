#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"

void SuppTabCrits(Critere *TabCritsRef,int *NbrCrits)
{
    int i;
    for (i=0;i<*NbrCrits;i++)
    {
        free(TabCritsRef[i].a_tNom);
    }
    free(TabCritsRef);
}
