#include <stdio.h>
#include <stdlib.h>
#include "cout.h"
#include "min_col.h"
#include "min_ligne.h"


//réduction initiale du tableau
void etape0(int n, Cout matrice[n][n])
{
	int i, j;
	double min;
	//reduction des lignes
	for(i=0;i<n;i++)
	{

		min = min_ligne(i, n, matrice);
		for(j=0;j<n;j++)
		{
			matrice[i][j].c = matrice[i][j].c - min;

		}
	}

	//réduction des colonnes
	for(i=0;i<n;i++)
	{
		min = min_col(i, n, matrice);
		for(j=0;j<n;j++)
		{
			matrice[j][i].c = matrice[j][i].c - min;

		}
	}


}
