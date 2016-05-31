#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "RechercherCrit.h"

Critere* SupprimerCritRef(Critere *TabCritsRef,int *NbrCrits,long unsigned int IDcrit)
{
    int supprimer = RechercherCrit(TabCritsRef,NbrCrits,IDcrit);

    *NbrCrits -= 1;

    Critere *TempTab = NULL;
    TempTab = (Critere*)malloc(sizeof(Critere)*(*NbrCrits));
    if (TempTab == NULL)
    {
        printf("VOUS AVEZ LA MEMOIRE PLEINE, EXECUTION IMPOSSIBLE");
        exit(1);
    }

    int i;
    for (i=0;i<*NbrCrits+1;i++)
    {
        if (i<supprimer)
        {
            TempTab[i]=TabCritsRef[i];
        } else if (i>supprimer) {
            TempTab[i-1]=TabCritsRef[i];
        }
    }

    free(TabCritsRef);

    TabCritsRef = TempTab;

    return TabCritsRef;
}
