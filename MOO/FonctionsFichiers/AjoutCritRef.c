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
            TempTab[i].a_ID=TabCritsRef[i].a_ID;
            TempTab[i].a_tNom=(char*)malloc(sizeof(char)*strlen(TabCritsRef[i].a_tNom));
            strcpy(TempTab[i].a_tNom,TabCritsRef[i].a_tNom);
          //  TempTab[i].a_tNom=TabCritsRef[i].a_tNom;
            printf("kk\n");
    }

    TempTab[*NbrCrits-1].a_ID = IDcrit;
    TempTab[*NbrCrits-1].a_tNom =(char*)malloc(sizeof(char)*strlen(NomCrit));
    strcpy(TempTab[*NbrCrits-1].a_tNom,NomCrit);
    int *Temp;
    *Temp= (*NbrCrits)-1;
    printf("Vider un tab de %d crits\n",*Temp);
    SuppTabCrits(TabCritsRef,Temp);
    printf("kk\n");

    TabCritsRef = TempTab;

    return TabCritsRef;

}
