#include <stdio.h>
#include <stdlib.h>
#include "../Mission.h"
#include "../Agent.h"
#include "../simulation.h"
#include "reevaluation.h"

//on applique la simulation sim
//on donne en arguments supp les listes d'agent et de mission
//et un tableau de succès forcement de taille n

void appliquersim(simulation sim, FlagAgent *ListeA, FlagMission *ListeM, int succes[])
{
	int i, n = sim.a_NbrElements;

	//passe par chaque ligne de la simulation
	for(i=0;i<n;++i)
	{
		printf("i = %d on reevalue l'agent %i \n", i, GetAgentByID(ListeA, sim.a_tAttributions[i][1]));
		reevaluation(GetMission(ListeM, GetIndexMission(ListeM, sim.a_tAttributions[i][0])), GetAgentByID(ListeA, sim.a_tAttributions[i][1]), succes[i]);
		printf("reevaluation ok \n");
	}

	printf("sortie du for");
}
