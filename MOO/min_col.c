#include <stdio.h>
#include <stdlib.h>
#include <cout.h>

//fonction donnant la valeur minimale d'une colonne d'un tableau de couts
double min_col(Cout tab[][], int colonne, int nb_lignes)
{
	int i;
	double min = tab[0][colonne];

	for(i=1;i<nb_lignes;i++)
	{
		if(tab[i][colonne]<min)
		{
			min = tab[i][colonne];
		}
	}
	return min;  