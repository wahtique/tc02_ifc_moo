#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"


void InsNAgent(FlagAgent *Liste,unsigned int Qte,unsigned int index)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        InsAgent(Liste,index);
    }
}
