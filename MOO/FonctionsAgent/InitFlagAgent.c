#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void InitFlagAgent(FlagAgent *Liste) //OK
{
    Liste->a_Elmt1=NULL;
    Liste->a_Elmtn=NULL;
    Liste->a_Taille=0;
    Liste->a_DimScore=0;
    Liste->a_tScoreSchem=NULL;
}
