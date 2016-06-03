#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"


void AjouterNAgent(FlagAgent *Liste,unsigned int Qte,unsigned int CodePosition)
{
    int i=0;
    if(CodePosition==0)
    {
        for(i=0;i<Qte;i++)
        {
            AjouterAgent0(Liste);
        }
    }
    else if(CodePosition==1)
    {
        for(i=0;i<Qte;i++)
        {
            AjouterAgentNP1(Liste);
        }
    }
}
