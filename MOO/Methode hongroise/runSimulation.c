#include <stdlib.h>
#include <stdio.h>
#include "Agent.h"
#include "Mission.h"
#include "simulation.h"
#include "purger.h"
#include "verifContinuer.h"
#include "etapeO.h"
#include "etape1.h"
#include "etape2.h"
#include "etape3.h"
#include "creer_matrice_couts.h"



void runSimulation(simulation *sim, Agent agts[n], Mission m[n], int n, Agent med)
{
	Cout couts[n][n], couts0[n][n] ;
	int continuer =1, i, j;

	//on cree une copie qui ne bouge pas

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			couts0[i][j] = couts[i][j];
		}
	}

	creer_matrice_couts(agts, m, med, couts);
	etapeO(couts, n);
	do
	{
		purger(couts, n);
		etape1(couts, n);
		continue = verifContinuer(couts, n);
		if (continue == 1)
		{
			etape2(couts, n);
			etape3(couts, n);
		}

	}While(continue == 1);

	//mnt on a une matrice des couts optimale
	//on remplis tout ça dans la simulation


}