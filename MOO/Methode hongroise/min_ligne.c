
#include <stdio.h>
#include <stdlib.h>
#include <cout.h>

//fonction donnant la valeur minimale d'une ligne d'un tableau de couts
double min_ligne(Cout tab[][], int ligne, int nb_col)
{
	int i;
	double min = tab[ligne][0].c;

	for(i=1;i<nb_col;i++)
	{
		if(tab[ligne][i].c<min)
		{
			min = tab[ligne][i].c;
		}
	}
	return min;  
}