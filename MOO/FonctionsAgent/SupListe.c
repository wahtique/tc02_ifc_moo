#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void SupListe(FlagAgent *Liste)
{

    int i=0,n=Liste->a_Taille;
    for(i=0;i<n;i++)
    {
        if(GetAgent(Liste,0))
        {
            SupAgent(Liste,0);
        }
    }


    for(i=0;i<Liste->a_DimScore;i++)
    {
        free(Liste->a_tScoreSchem[i]);
        (Liste->a_tScoreSchem)[i]=NULL;
    }

    //printf("\n%d\n",Liste->a_DimScore);
    free(Liste->a_tScoreSchem);
    Liste->a_tScoreSchem=NULL;


    if(Liste)
    {
        Liste=NULL;
    }

}
