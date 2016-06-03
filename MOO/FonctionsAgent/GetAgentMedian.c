#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

Agent *GetAgentMedian(FlagAgent *Liste)
{
    int i=0,j=0;
    Agent* Tmp=Liste->a_Elmt1;
    float Max=0;

    if(Liste->a_DimScore>0&&Liste->a_Taille>0)
    {
        for(i=0;i<Liste->a_DimScore;i++)
        {
            ClasserAgent(Liste,Liste->a_tScoreSchem[i][0]);
            if(Liste->a_Taille/2<(float)(Liste->a_Taille)/2) //Si la dimension est impaire
            {
                Tmp->a_tScore[i][1]=GetAgent(Liste,Liste->a_Taille/2)->a_tScore[i][1];
            }
            else
            {
                Tmp->a_tScore[i][1]=(GetAgent(Liste,Liste->a_Taille/2)->a_tScore[i][1]+GetAgent(Liste,Liste->a_Taille/2-1)->a_tScore[i][1])/2;
            }
        }
        return Tmp;
    }
    else
    {
        printf("\nPas de critères ou d'agents...Pas de classement\n");
    }
}
