#include <stdio.h>
#include <stdlib.h>
#include "cout.h"


//etape 1 : toujours la même matrice des couts,
//n le nombre de lignes / colonnes

void etape1(int n, Cout matrice[][n])
{
	int ligne, colonne_choisie, ligne_choisie, i, j, k, min_non_barres = 0, nb_non_barres, num_colonne_zero, continuer, nb_zero_restant;

	do
	{
		//on initialise en choisissant arbitrairement la ligne 0 comme reference

		ligne_choisie = 0;
		min_non_barres = n+1;
		/*
		//parcourir la ligne 0 pour compter les zeros
		for(k=0;k<n;k++)
		{
			if((matrice[0][k].c==0) && (matrice[0][k].barre == 0))
			{
				min_non_barres += 1;
			}
		}
		*/
		//on cherche si une autre ligne a moins de zeros non barres
		for(j=0;j<n;j++)
		{
			nb_non_barres = 0;

			//on teste chaque case de la ligne
			for(k=0;k<n;k++)
			{
				if((matrice[j][k].c == 0) && (matrice[j][k].barre == 0) && (matrice[j][k].encadre == 0))
				{
					nb_non_barres += 1;
				}

			}
            printf("%d zeros non barres sur la ligne %d \n", nb_non_barres, j);
            //printf("test des cases ok \n ");
			// si cette ligne a moins de zero que la ligne choisie alors cette ligne j devient la ligne choisie
			if((nb_non_barres < min_non_barres) && (nb_non_barres > 0))
			{
				min_non_barres = nb_non_barres;
				ligne_choisie = j;
			}

		}
		printf("ligne choisie : %d \n", ligne_choisie);

		//printf("on passe a letape suivante \n");

		//on encadre le zero non encadré et non barré le plus à gauche de cette ligne
		continuer = 1;
		i = 0;

		do
		{
			if ((matrice[ligne_choisie][i].c == 0) && (matrice[ligne_choisie][i].barre == 0) && (matrice[ligne_choisie][i].encadre == 0))
			{
				matrice[ligne_choisie][i].encadre = 1;
				colonne_choisie = i;
				continuer = 0;
			}
			else
			{
				i += 1;
			}

		}while(continuer == 1);

		printf("colonne : %d \n", colonne_choisie);


		//on barre touts les zeros de la même ligne
		//on commence à i+1 car jai déjà selectionné le zero le plus à gauche

		for(k=0;k<n;k++)
		{
			if ((matrice[ligne_choisie][k].c == 0) && (matrice[ligne_choisie][k].encadre == 0) && (matrice[ligne_choisie][k].barre == 0))
			{
				matrice[ligne_choisie][k].barre = 1;
			}
		}

		//même chose pour les colonnes

		for(k=0;k<n;k++)
		{
			if ((matrice[k][colonne_choisie].c == 0) && (matrice[k][colonne_choisie].barre == 0) && (matrice[k][colonne_choisie].encadre == 0))
			{
				matrice[k][colonne_choisie].barre = 1;
			}
		}

				//debug
        printf("etat des encadres a la fin de letape 1 \n");
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%d \t", matrice[i][j].encadre);
            }

            printf("\n");
        }

        printf("etat des barres a la fin de letape 1 \n");
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%d \t", matrice[i][j].barre);
            }

            printf("\n");
        }


		//on check le nombre de zeros restant, cad non barrés ou encadrés

		nb_zero_restant = 0;

		for (j=0; j<n; j++)
		{
			for(k=0;k<n;k++)
			{
				if ((matrice[j][k].c == 0) && (matrice[j][k].barre == 0) && (matrice[j][k].encadre == 0))
				{
					nb_zero_restant ++;
				}
			}
		}


	}while(nb_zero_restant > 0);

    printf("etape1 ok \n");
}
