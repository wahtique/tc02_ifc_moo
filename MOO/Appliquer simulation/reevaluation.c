#include <stdio.h>
#include <stdlib.h>
#include "../Mission.h"
#include "../Agent.h"
#include "../simulation.h"

//modifie les scores d'un agent en fonction de son succès à une mission
//le succes peut prendre la valzur 1 ou 0
void reevaluation(Mission *m, Agent *a, int succes)
{
	int i;
	int n = m->a_DimPonderation;
	float s;
	if(succes == 1)
	{
		for(i=0;i<n; i++)
		{
			s = a->a_tScore[i][1];
			s = s + (100 - s) * ((m->a_tPonderation[i][1]) / 1000);
			a->a_tScore[i][1] = s;
		}

	}
	else
	{
		for (i=0;i<n;++i)
		{
			s = a->a_tScore[i][1];
			s = s - ((s * s) / 20000);
			a->a_tScore[i][1] = s;
		}
	}

}
