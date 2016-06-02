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
	creer_matrice_couts(n, agts, m, med, couts);

	for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%f \t", couts[i][j].c);
        }
        printf("\n");
    }

	//on cree une copie qui ne bouge pas

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			couts0[i][j] = couts[i][j];
		}
	}

	etape0(n, couts);
	printf("etape 0 ok\n");
	do
	{
		purger(n, couts); //ok
		printf("purge ok\n");
		etape1(n, couts); //ok
		printf("etape1 ok\n");
		continuer = verifContinuer(n, couts); //ok
		printf("continuer = %d\n", continuer);
		if (continuer == 1)
		{
			etape2(n, couts); //ok
			printf("etape 2 ok\n");
			etape3(n, couts); //ok
			printf("etape 3 ok\n");
		}

	}while(continuer == 1);

	printf("simulation finie\n");

	//mnt on a une matrice des couts optimale
	//on remplis tout ça dans la simulation


	//a rework avec les fonctions pour la sim

	k = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((couts[i][j].c == 0) && (couts[i][j].encadre == 1))
			{
				sim->a_tAttributions[k][0] = m[j].a_ID;
				sim->a_tAttributions[k][1] = agts[i].a_ID;
				sim->a_tCouts[k] = couts0[i][j].c;
				k += 1;
				//printf("%d et %d à la ligne %d \n", m[j].a_ID, agts[i].a_ID, k);
			}
		}
	}


}
