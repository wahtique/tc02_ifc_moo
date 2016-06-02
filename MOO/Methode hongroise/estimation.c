#include <stdlib.h>
#include <stdio.h>
#include "../Mission.h"
#include "../Agent.h"

//fonction prenant comme arguments un agent, une mission, l'agent médian
//cad un agent avec des scores médians (des scores de tous les agents)
//et n le nombre de critères de la mission
//ressort le cout de la mission pour l'agent donné
float estimation(Agent agt, Mission mission, Agent agt_med)
{
	float prix, perf_std, perf_agt = 0, prix_std = 0;
	int i, n;

	n = mission.a_DimPonderation;
	//printf("mission.a_DimmPonderation = %d", n);

	//calcul de l'indice de performance médian
	//printf("perf_std = %d", perf_std);

    i = 0;
	for(i=0;i<n;i++)
	{
		/*
		//printf("i = %i \n", i);
		//on a pas forcément tout les critères pour une mission donnée
		//jintroduis donc un deuxième compteur pour chercher
		//l'id du critère qu'on consdère dans le calcul du côté mission
		//dans le tableau de scores de l'agent
		j = 0;
		//printf("j = %d \n", j);
		while(mission.a_tPonderation[i][0] != agt_med.a_tScore[j][0])
		{
			j = j+1;
			//printf("%f i = %d \n",mission.a_tPonderation[i][0], i);
			//printf("j = %d \n", j);
			//getch();


		}
		*/

		perf_std = perf_std + mission.a_tPonderation[i][1] * (agt_med.a_tScore[i][1] / 100);

	}

	printf("perf std = %f \n", perf_std);

    i=0;
	for(i=0;i<n;i++)
	{
		/*j = 0;
		while(mission.a_tPonderation[i][0] != agt.a_tScore[j][0])
		{
			j = j+1;

		}*/
		perf_agt = perf_agt + mission.a_tPonderation[i][1] * (agt.a_tScore[i][1] / 100);
	}
    printf("perf agent : %f \n", perf_agt);
	//le cout standard = salaire * durée
	prix_std = agt_med.a_Salaire * mission.a_Duree;
	//printf("prixstd = %f \n", prix_std);
	// le cout pour l'agent fourni en parametres : perf agt / perf mediane * cout standard
	// on peut supprime rune variables pour rendre les choses plus opti mais cest moins clair
	prix = (perf_std/perf_agt)*prix_std;
	printf("prix : %f \n",prix);

    perf_std = 0;
    perf_agt = 0;
	return prix;


}
