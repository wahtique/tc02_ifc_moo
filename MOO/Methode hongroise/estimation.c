#include <stdlib.h>
#include <stdio.h>
#include "../Mission.h"
#include "../Agent.h"

//fonction prenant comme arguments un agent, une mission, l'agent médian
//cad un agent avec des scores médians (des scores de tous les agents)
//et n le nombre de critères de la mission
//ressort le cout de la mission pour l'agent donné
double estimation(Agent agt, Mission mission, Agent agt_med)
{
	double prix, perf_std = 0, perf_agt = 0, prix_std;
	int i, j, n;

	n = mission.a_DimPonderation;

	//calcul de l'indice de performance médian
	for(i=0;i<n;i++)
	{
		//on a pas forcément tout les critères pour une mission donnée
		//jintroduis donc un deuxième compteur pour chercher
		//l'id du critère qu'o nconsidère dans lê calcul du côté mission
		//dans le tableau de scores de l'agent
		j = 0;
		while(mission.a_tPonderation[0][j] != agt_med.a_tScore[0][j])
		{
			j = j+1;

		}

		perf_std = perf_std + mission.a_tPonderation[1][i]*agt_med.a_tScore[1][j];
	}


	for(i=0;i<n;i++)
	{
		j = 0;
		while(mission.a_tPonderation[0][j] != agt.a_tScore[0][j])
		{
			j = j+1;

		}
		perf_agt = perf_agt + mission.a_tPonderation[1][i]*agt.a_tScore[1][j];
	}

	//le cout standard = salaire * durée
	prix_std = agt_med.a_Salaire * mission.a_Duree;
	// le cout pour l'agent fourni en parametres : perf agt / perf mediane * cout standard
	// on peut supprime rune variables pour rendre les choses plus opti mais cest moins clair
	prix = (1.*perf_std/perf_agt)*prix_std;
	return prix;


}
