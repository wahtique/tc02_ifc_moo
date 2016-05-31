#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"

Critere* AjoutCritRef(Critere *TabCritsRef,int *NbrCrits,long unsigned int IDcrit,char NomCrit[])
{
    *NbrCrits += 1;

    Critere *TempTab = NULL;
    TempTab = (Critere*)malloc(sizeof(Critere)*(*NbrCrits));
    if (TempTab == NULL)
    {
        printf("VOUS AVEZ LA MEMOIRE PLEINE, EXECUTION IMPOSSIBLE");
        exit(1);
    }


    int i;

    for (i=0;i<*NbrCrits-1;i++)
    {
            TempTab[i]=TabCritsRef[i];
    }

    TempTab[*NbrCrits-1].a_ID = IDcrit;
    TempTab[*NbrCrits-1].a_tNom = NomCrit;

    free(TabCritsRef);

    TabCritsRef = TempTab;

    return TabCritsRef;

}
