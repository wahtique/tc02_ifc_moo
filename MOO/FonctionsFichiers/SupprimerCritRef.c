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
            TempTab[i].a_ID=TabCritsRef[i].a_ID;
            TempTab[i].a_tNom=(char*)malloc(sizeof(char)*strlen(TabCritsRef[i].a_tNom));
            strcpy(TempTab[i].a_tNom,TabCritsRef[i].a_tNom);
        } else if (i>supprimer) {
            TempTab[i-1].a_ID=TabCritsRef[i].a_ID;
            TempTab[i-1].a_tNom=(char*)malloc(sizeof(char)*strlen(TabCritsRef[i].a_tNom));
            strcpy(TempTab[i-1].a_tNom,TabCritsRef[i].a_tNom);
        }
    }

    int Tmp;
    Tmp = (*NbrCrits)+1;
    printf("Vider un tab de %d crits\n",Tmp);
    SuppTabCrits(TabCritsRef,&Tmp);

    TabCritsRef = TempTab;

    return TabCritsRef;
}
