#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void AfficherCritereM(Critere *ListeCritere,long unsigned int TailleDuTableau)
{
    int i=0;
    for(i=0;i<TailleDuTableau;i++)
    {
        printf("%s   n°: %d\n",ListeCritere[i].a_tNom,ListeCritere[i].a_ID);
    }
}
