#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulation.h"

simulation* AllocSimulation(simulation*Simulation,int NbrElement)
{
    Simulation->a_tAttributions=NULL;
    Simulation->a_tAttributions=(long unsigned int **)malloc(sizeof(long unsigned int *)*NbrElement*2);
    Simulation->a_tCouts = NULL;
    Simulation->a_tCouts = (double*)malloc(sizeof(double)*(NbrElement+1));
    int i;
    for (i=0;i<NbrElement;i++)
    {
        Simulation->a_tAttributions[i]=(long unsigned int *)malloc(sizeof(long unsigned int)*2);
    }
    return Simulation;
}
