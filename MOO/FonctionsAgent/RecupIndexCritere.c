#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Critere.h"
#include "../Agent.h"

int RecupIndexCritere(FlagAgent *Liste,float ID)
{
    int i=0;

    for(i=0;i<Liste->a_DimScore;i++)
    {
        if((int)round(Liste->a_tScoreSchem[i][0])==(int)round(ID))
        {
            return i;
        }
    }
    if(i==Liste->a_DimScore)
    {
        printf("Erreur index");
        return -1;
    }
}
