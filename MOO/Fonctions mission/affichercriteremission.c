#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void AfficherCritereMission(FlagMission *Liste)
{
    int i=0,j=0;
    for(i=0;i<Liste->a_Taille;i++)
    {

        printf("Mission n: %d: \n",i);
        for(j=0;j<Liste->a_DimPonderation;j++)
        {
            printf("ID: %f   Score: %f\n",GetMission(Liste,i)->a_tPonderation[j][0],GetMission(Liste,i)->a_tPonderation[j][1]);
        }
    }
    printf("\n");
}