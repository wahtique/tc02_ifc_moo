#include <stdio.h>
#include <stdlib.h>
#include "cout.h"

void etape3(int n, Cout matrice[n][n])
{
	int i, j;
	double min;

	//on trouve le min du tableau réduit

	min = -1;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((matrice[i][j].trait == 0 && matrice[i][j].c < min) || (min < 0))
			{
				min = matrice[i][j].c;
			}
		}
	}

	//on retranche le min à toutes les cases du tableau partiel
	//et on l'ajoute à toutes les cases traversées par 2 traits

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matrice[i][j].c += (-min)*(matrice[i][j].trait == 0) + 2*min*(matrice[i][j].trait = 2); 
		}
	}
}