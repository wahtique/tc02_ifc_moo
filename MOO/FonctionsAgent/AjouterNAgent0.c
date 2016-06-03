#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void AjouterNAgent0(FlagAgent *Liste,unsigned int Qte)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        AjouterAgent0(Liste);
    }
}

