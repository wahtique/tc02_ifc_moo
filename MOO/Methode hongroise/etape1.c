#include <stdio.h>
#include <stdlib.h>
#include "cout.h"


//etape 1 : toujours la même matrice des couts,
//n le nombre de lignes / colonnes

void etape1(int n, Cout matrice[][n])
{
	int ligne, ligne_choisie, i, j, k, min_non_barres = 0, nb_non_barres, num_colonne_zero, continuer, nb_zero_restant;

	do
	{
		//on initiamise en choisissant arbitrairement la ligne 0 comme reference

		/*ligne_choisie = 0;
		min_non_barres = 0;

		for(k=0;k<n;k++)
		{
			if((matrice[0][k].c==0) && (matrice[0][k].barre == 0))
			{
				min_non_barres += 1;
			}
		}*/

		//on cherche si une autre ligne a moins de zeros non barres
		min_non_barres = n+1;
		for(j=0;j<n;j++)
		{
			nb_non_barres = 0;

			//on teste chaque case de la ligne
			for(k=0;k<n;k++)
			{
				if((matrice[j][k].c==0) && (matrice[j][k].barre == 0))
				{
					nb_non_barres += 1;
				}
			}

			// si cette ligne a moins de zero que la ligne choisie alors cette ligne j devient la ligne choisie
			if(nb_non_barres<min_non_barres && nb_non_barres != 0)
			{
				min_non_barres = nb_non_barres;
				ligne_choisie = j;
			}

		}

		//on encadre le zero non encadré et non barré le plus à gauche de cette ligne
		continuer = 1;
		i = 0;
		do
		{
			if (matrice[ligne_choisie][i].c == 0 && matrice[ligne_choisie][i].barre == 0 && matrice[ligne_choisie][i].encadre == 0)
			{
				matrice[ligne_choisie][i].encadre = 1;
				continuer = 0;
			}
			else
			{
				i += 1;
			}

		}while(continuer = 1);

		//on barre touts les zeros de la même ligne
		//on commence à i+1 car jai déjà selectionné le zero le plus à gauche

		for(k=i+1;k<n;k++)
		{
			if (matrice[ligne_choisie][k].c==0)
			{
				matrice[ligne_choisie][k].barre = 1;
			}
		}

		//même chose pour les colonnes

		for(j=0;j<n;j++)
		{
			if (matrice[j][k].c == 0 && matrice[j][k].barre == 0 && matrice[j][k].encadre == 0)
			{
				matrice[j][k].barre == 1;
			}
		}

		//on check le nombre de zeros restant, cad non barrés ou encadrés

		nb_zero_restant = 0;
		for (j = 0; i < n; i++)
		{
			for(k=0;k<n;k++)
			{
				if (matrice[j][k].c == 0 && matrice[j][k].barre == 0 && matrice[j][k].encadre == 0)
				{
					nb_zero_restant += 1;
				}
			}
		}


	}while(nb_zero_restant!=0);


}