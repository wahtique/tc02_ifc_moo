#include <stdio.h>
#include <stdlib.h>
#include "cout.h"


void etape2(int n, Cout matrice[n][n])
{

	int lignes_marquees[n], col_marquees[n], i, j, nb_encadres, nb_op;

	for(i=0;i<n;i++)
    {
        lignes_marquees[i] = 0;
        col_marquees[i] = 0;
    }

	//on initialise les tableaux



	//etape 2.a
	for(i=0;i<n;i++)
	{
		nb_encadres = 0;

		//je compte le nombre de zero encadres sur la ligne i
		for(j=0;j<n;j++)
		{
			nb_encadres+=1*(matrice[i][j].encadre==1);

		}

		//si c'est 0 alors je marque la ligne
		if (nb_encadres==0)
		{
			lignes_marquees[i] = 1;
		}
	}

	//dans un grand do while pour répéter les étapes tant qu'on a effectuer au moins une opération
	do
	{
		nb_op = 0;

		//etape 2.b
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if ((matrice[i][j].barre == 1) && (lignes_marquees[i] = 1))
				{
					col_marquees[j] = 1;
					nb_op += 1;
				}
			}
		}

		//etape 2.c
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if ((matrice[i][j].encadre == 1) && (col_marquees[j] = 1))
				{
					lignes_marquees[i] = 1;
					nb_op += 1;
				}
			}
		}

	}while(nb_op != 0);

	//on trace les traits

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if (lignes_marquees[i] == 0 || col_marquees[j] == 1)
				{
					matrice[i][j].trait = 1*(lignes_marquees[i] == 1) + 1*(col_marquees[j] == 1);
				}
			}
		}
}
