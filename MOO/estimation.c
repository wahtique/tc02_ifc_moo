#include <stdlib.h>
#include <stdio.h>
#include "Mission.h"
#include "Agent.h"

//on prend n le nombre de critères
double estimation(Agent agt, Mission mission, Agent agt_med, int n)
{
	double prix, perf_std = 0, perf_agt = 0, prix_std;
	int i;

	For(i=0;i<=n-1;i++)
	{
		perf_std = perf_std + mission.a_tPonderations[1][i]*agt_med.a_tScore[1][i];
	}

	
	For(i=0;i<=n-1;i++)
	{
		perf_agt = perf_agt + mission.a_tPonderations[1][i]*agt.a_tScore[1][i];
	}	

	prix_std = agt_med.a_salaire * mission.a_duree;
	prix = (1.*perf_std/perf_agt)*prix_std;
	return prix;


}
