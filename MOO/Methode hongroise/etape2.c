#include <stdio.h>
#include <stdlib.h>
#include "cout.h"


void etape2(int n, Cout matrice[n][n])
{

	int lignes_marquees[n], col_marquees[n], i, j, nb_encadres, nb_op;

	//on initialise les tableaux

	for(i=0;i<n;i++)
    {
        lignes_marquees[i] = 0;
        col_marquees[i] = 0;
    }

	//etape 2.a
	for(i=0;i<n;i++)
	{
		nb_encadres = 0;

		//je compte le nombre de zero encadres sur la ligne i
		for(j=0;j<n;j++)
		{
			if((matrice[i][j].encadre == 1)&&(matrice[i][j].c == 0))
			{
				nb_encadres += 1;
			}

		}
		printf("%d zeros encadres sur la ligne %d \n", nb_encadres, i);
		//si c'est 0 alors je marque la ligne
		if (nb_encadres == 0)
		{
			lignes_marquees[i] = 1;
			printf("ligne %d marquees \n", i);
		}
	}


	//dans un grand do while pour répéter les étapes tant qu'on a effectuer au moins une opération
	do
	{
		nb_op = 0;

		//etape 2.b : marquer toute colonne avec un zero barré sur une ligne marquée
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if ((matrice[i][j].barre == 1) && (lignes_marquees[i] == 1) && (col_marquees[j] == 0))
				{
					col_marquees[j] = 1;
					printf("colonne %d marquee \n", j);
					nb_op += 1;
				}
			}
		}
		
		//etape 2.c : marquer toute ligne ayant un zéro mencdré dans une colonne marquée
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if ((matrice[i][j].encadre == 1) && (col_marquees[j] == 1) && (lignes_marquees[i] == 0))
				{
					lignes_marquees[i] = 1;
					printf("ligne %d marquee \n", i);
					nb_op += 1;
				}
			}
		}
		

	}while(nb_op > 0);

	//on trace les traits : 
	//trait vaut 0 si la colonne n'est pas marquée et si la ligne l'est
	// 1 si la colonne est marquée XOR la ligne ne l'est pas
	// 2 si colonne marquee et ligne non

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(lignes_marquees[i] == 0)
				{
					matrice[i][j].trait += 1;

				}
				if(col_marquees[j] == 1)
				{
					matrice[i][j].trait += 1;
				}
			}
		}
}
