#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulation.h"

void SuppSimulation(simulation*Simulation,int NbrElement)
{
    int i;
    for (i=0;i<NbrElement;i++)
    {
        free(Simulation->a_tAttributions[i]);
    }
    free(Simulation->a_tAttributions);
    free(Simulation->a_tCouts);
}
