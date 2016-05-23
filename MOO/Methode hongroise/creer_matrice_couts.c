#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"
#include "Mission.h"
#include "estimation.h"
#include "cout.h"

//une fonction pour créer une matrice de cout pour une simulations
//on considere l'agent median med comme preexistant il doit donc avoir une existance persistante
//n est ici le nombre d'agents / missions
void creer_matrice_couts(Agent agts[], Mission m[], Agent med, Cout matrice_couts[][n], int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matrice_couts[i][j].c = estimation(agts[i], m[j], med);
			matrice_couts[i][j].barre = 0;
			matrice_couts[i][j].encadre = 0;
			matrice_couts[i][j].trait = 0;

		}
	}
}
