#include <stdio.h>
#include <stdlib.h>
#include "cout.h"

void purger(int n, Cout tab[n][n])
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			tab[i][j].barre = 0;
			tab[i][j].encadre = 0;
			tab[i][j].trait = 0;
        }
    }
}

