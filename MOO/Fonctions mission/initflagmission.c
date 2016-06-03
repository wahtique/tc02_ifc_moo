#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void InitFlagMission(FlagMission *Liste)
{
    Liste->a_Elmt1=NULL;
    Liste->a_Elmtn=NULL;
    Liste->a_Taille=0;
    Liste->a_DimPonderation=0;
    Liste->a_tPonderationSchem=NULL;

}
