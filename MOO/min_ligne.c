
#include <stdio.h>
#include <stdlib.h>
#include <cout.h>

//fonction donnant la valeur minimale d'une ligne d'un tableau de couts
double min_ligne(Cout tab[][], int ligne, int nb_col)
{
	int i;
	double min = tab[ligne][0];

	for(i=1;i<nb_col;i++)
	{
		if(tab[ligne][i]<min)
		{
			min = tab[ligne][i];
		}
	}
	return min;  
}