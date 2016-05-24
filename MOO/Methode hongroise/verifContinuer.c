#include <stdio.h>
#include <stdlib.h>
#include "cout.h"

int verifContinuer(Cout tab[n][n], int n)
{
	int n0l, n0c, i, j, ok = 1;

	//vérifier qu'on a bien 1 zero par ligne et par colonne

	i=0;
	do
	{
		n0l = 0;
		n0c = 0;

		for(j=0;j<n;j++)
		{
			n0l += (tab[i][j].c == 0);
			n0c += (tab[i][j].c == 0);
		}

		ok = 0.5*((n0l==1) + (n0c == 1));

		i+=1;

	}while(i<n && ok == 1);

	if (ok == 1)
	{	
		ok = 0
		return ok;
	}
	else
	{
		return ok;
	}

}