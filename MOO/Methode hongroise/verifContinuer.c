#include <stdio.h>
#include <stdlib.h>
#include "cout.h"

int verifContinuer(int n, Cout tab[n][n])
{
	int nzeros, i, j, ip, jp, ok = 1;

	//vérifier qu'on a bien 1 zero encadre par ligne et par colonne
	//on check les lignes puis les colonnes, et si au cours de l'éxécution on découvre une ligne / colonne
	//avec plus de zéro on passe à la suite


	//vérifier un zéro marque par ligne
    i=0;
	do
	{
        printf("test ligne %d", i);
        nzeros = 0;
        for(j=0;j<n;++j)
        {
            if((tab[i][j].c==0) && (tab[i][j].encadre == 1))
            {
                nzeros++;
            }
        }
    if(nzeros != 1)
    {
        return 1;
    }
    else
    {
        i += 1;
    }

	}while(i < n);

    printf("lignes ok");

	//vérifier un zéro par colonne

    jp=0;
	do
    {
        printf("test colonne %d \n", jp);
        nzeros = 0;
        for(ip=0;ip<n;++ip)
        {
            if((tab[ip][jp].c == 0) && (tab[ip][jp].encadre == 1))
            {
                nzeros += 1;

                printf(" i = %d, j %dnzeros : %d \n",ip, jp, nzeros);
            }   
        }

        if(nzeros != 1)
        {
            printf("col exit");
            return 1;
        }
        else
        {
            j += 1;
        }
    }while(j<n);

    return 0;


}
