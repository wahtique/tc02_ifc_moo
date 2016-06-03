#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void MajCritereMission(FlagMission *Liste,unsigned int indexMission)
{
    if(Liste->a_DimPonderation>0)
    {
        int i=0;

        GetMission(Liste,indexMission)->a_tPonderation=(float**)malloc(Liste->a_DimPonderation*sizeof(float*));
        for(i=0;i<Liste->a_DimPonderation;i++)
        {
            GetMission(Liste,indexMission)->a_tPonderation[i]=(float*)malloc(2*sizeof(float));
            GetMission(Liste,indexMission)->a_tPonderation[i][0]=Liste->a_tPonderationSchem[i][0];
            GetMission(Liste,indexMission)->a_tPonderation[i][1]=Liste->a_tPonderationSchem[i][1];
        }
        GetMission(Liste,indexMission)->a_DimPonderation=Liste->a_DimPonderation;
    }


}
