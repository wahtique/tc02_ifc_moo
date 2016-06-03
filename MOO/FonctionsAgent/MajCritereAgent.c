#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void MajCritereAgent(FlagAgent *Liste,unsigned int indexAgent)
{
    if(Liste->a_DimScore>0)
    {
        int i=0;

        GetAgent(Liste,indexAgent)->a_tScore=(float**)malloc(Liste->a_DimScore*sizeof(float*));
        for(i=0;i<Liste->a_DimScore;i++)
        {
            GetAgent(Liste,indexAgent)->a_tScore[i]=(float*)malloc(2*sizeof(float));
            GetAgent(Liste,indexAgent)->a_tScore[i][0]=Liste->a_tScoreSchem[i][0];
            GetAgent(Liste,indexAgent)->a_tScore[i][1]=Liste->a_tScoreSchem[i][1];
        }
        GetAgent(Liste,indexAgent)->a_DimScore=Liste->a_DimScore;
    }
}
