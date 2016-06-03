#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

int RecupIndexCritereM(FlagMission *Liste,float ID)
{
    int i=0;

    for(i=0;i<Liste->a_DimPonderation;i++)
    {
        if((int)Liste->a_tPonderationSchem[i][0]==(int)ID)
        {
            return i;
        }
    }
    if(i==Liste->a_DimPonderation)
    {
        printf("Erreur index");
        return -1;
    }
}
