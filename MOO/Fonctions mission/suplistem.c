#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void SupListeM  (FlagMission *Liste)
{
    int i=0,n=Liste->a_Taille;
    for(i=0;i<n;i++)
    {
        if(GetMission(Liste,0))
        {
            SupMission(Liste,0);
        }
    }

    for(i=0;i<Liste->a_DimPonderation;i++)
    {
     //   free(Liste->a_tPonderationSchem[i]);
       // (Liste->a_tPonderationSchem)[i]=NULL;
    }

    printf("\n%d\n",Liste->a_DimPonderation);
   // free(Liste->a_tPonderationSchem);
   // Liste->a_tPonderationSchem=NULL;


    if(Liste)
    {
        Liste=NULL;
    }

}
