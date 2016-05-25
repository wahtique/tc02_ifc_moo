#include <stdlib.h>
#include <stdio.h>
#include "../Agent.h"
#include "../Mission.h"
#include "../simulation.h"
#include "purger.h"
#include "verifContinuer.h"
#include "etape0.h"
#include "etape1.h"
#include "etape2.h"
#include "etape3.h"
#include "creer_matrice_couts.h"

//*sim est un pointeur vers une variable de type simulation déjà définie à l'extérieur
//elle doit avoir un tableau a_tAttributions de taille [n][2], initialisé ou pas

void runSimulation(int n, simulation *sim, Agent agts[n], Mission m[n], Agent med)
{
	Cout couts[n][n], couts0[n][n] ;
	int continuer =1, i, j, k;

	//on cree une copie qui ne bouge pas

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			couts0[i][j] = couts[i][j];
		}
	}

	creer_matrice_couts(n, agts, m, med, couts);
	etape0(n, couts);
	do
	{
		purger(n, couts);
		etape1(n, couts);
		continuer = verifContinuer(n, couts);
		if (continuer == 1)
		{
			etape2(n, couts);
			etape3(n, couts);
		}

	}while(continuer == 1);

	//mnt on a une matrice des couts optimale
	//on remplis tout ça dans la simulation

	k = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(couts[i][j].c == 0)
			{
				sim->a_tAttributions[k][0] = m[j].a_ID;
				sim->a_tAttributions[k][i] = agts[i].a_ID;
				sim->a_tCouts[k] = couts0[i][j].c;
				k += 1;
			}
		}
	}


}
