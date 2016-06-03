#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void AjouterNMissionNP1(FlagMission *Liste,unsigned int Qte)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        AjouterMissionNP1(Liste);
    }
}
