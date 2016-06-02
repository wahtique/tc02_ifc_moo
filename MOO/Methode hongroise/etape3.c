#include <stdio.h>
#include <stdlib.h>
#include "cout.h"

void etape3(int n, Cout matrice[n][n])
{
	int i, j, c1 = 0, c2 = 0;
	double min = 0;;

	//on initialise le min
	while((matrice[c1][c2].c == 0) || (matrice[c1][c2].trait > 0));
	{		
		c1++;
		c2++;
	}

	min = matrice[c1][c2].c;

	printf("min initialise a %f \n", min);

	//on cherche le min du tableau réduit
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(((matrice[i][j].trait == 0) && (matrice[i][j].c < min)))
			{
				min = matrice[i][j].c;
			}
		}
	}

	printf("on a trouve le min qui est %f \n", min);

	//on retranche le min à toutes les cases du tableau partiel
	//et on l'ajoute à toutes les cases traversées par 2 traits

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(matrice[i][j].trait == 0)
			{
				matrice[i][j].c = matrice[i][j].c - min;
			}
			if(matrice[i][j].trait == 2)
			{
				matrice[i][j].c += min;
			}
		}
	}
}
