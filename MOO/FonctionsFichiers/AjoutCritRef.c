#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"

void AjoutCritRef(Critere *TabCritsRef,int NbrCrits,long unsigned int IDcrit,char NomCrit[])
{

    printf("crits : %d\n",NbrCrits);

    Critere *TempTab = NULL;
    TempTab = malloc(sizeof(Critere)*NbrCrits);
    if (TempTab == NULL)
    {
        printf("VOUS AVEZ LA MEMOIRE PLEINE, EXECUTION IMPOSSIBLE");
        exit(1);
    }


    int i;
    for (i=0;i<NbrCrits-1;i++)
    {
            TempTab[i]=TabCritsRef[i];
    }
    TempTab[NbrCrits-1].a_ID = IDcrit;
    TempTab[NbrCrits-1].a_tNom = NomCrit;

    {
        int i;
        for (i=0;i<NbrCrits;i++)
        {
            printf("Temp : %lu : %s\n",TempTab[i].a_ID,TempTab[i].a_tNom);
        }
    }
    free(TabCritsRef);

    TabCritsRef = TempTab;

}
