#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void AfficherCritereAgent(FlagAgent *Liste)
{
    int i=0,j=0;
    for(i=0;i<Liste->a_Taille;i++)
    {

        printf("Agent n: %d: \n",GetAgent(Liste,i)->a_ID);
        for(j=0;j<Liste->a_DimScore;j++)
        {
            printf("ID: %f   Score: %f\n",GetAgent(Liste,i)->a_tScore[j][0],GetAgent(Liste,i)->a_tScore[j][1]);
        }
    }
    printf("\n");
}
