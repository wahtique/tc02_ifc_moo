#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulation.h"

void SuppSimulation(simulation*Simulation,int NbrElement)
{
    int i=0;
    //printf("NB: %d\n",NbrElement);

    for (i=0;i<NbrElement;i++)
    {
        free(Simulation->a_tAttributions[i]);
        Simulation->a_tAttributions[i]=NULL;
    }
//    free(Simulation->a_tNom);
    free(Simulation->a_tAttributions);
    Simulation->a_tAttributions=NULL;
    free(Simulation->a_tCouts);
}
