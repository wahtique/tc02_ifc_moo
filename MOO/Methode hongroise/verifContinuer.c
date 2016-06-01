#include <stdio.h>
#include <stdlib.h>
#include "cout.h"

int verifContinuer(int n, Cout tab[n][n])
{
	int nzeros, i, j, ok = 1;

	//vérifier qu'on a bien 1 zero par ligne et par colonne
	//on check les lignes puis les colonnes, et si au cours de l'éxécution on découvre une ligne / colonne
	// avec plus de zéro on passe à la suite

	i=0;

	//vérifier un zéro par colonne
	do
	{
        nzeros = 0;
        for(j=0;j<n;j++)
        {
            nzeros += (tab[i][j].c==0);
        }
        i++;

	}while((nzeros == 1) && (i < n));

	if(nzeros != 1)
    {
        return 1;
    }

	//vérifier un zéro par ligne
    i=0;

	do
    {
        nzeros = 0;
        for(j=0;j<n;j++)
        {
            nzeros += (tab[j][i].c == 0);
        }
        i++;
    }while((nzeros == 1)&&(i<n));

    if(nzeros != 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
