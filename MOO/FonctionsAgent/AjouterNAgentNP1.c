#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void AjouterNAgentNP1(FlagAgent *Liste,unsigned int Qte)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        AjouterAgentNP1(Liste);
    }
}
