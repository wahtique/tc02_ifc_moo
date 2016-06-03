#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void SaisieScoreM(FlagMission *Liste)
{
    int i=0,j=0;
    char Clear=0;
    printf("Veuillez saisir les pondérations des missions une a une:\n\n");
    for(i=0;i<Liste->a_Taille;i++)
    {
        printf("Mission %s   n# %d",GetMission(Liste,i)->a_tNom,i+1);
        for(j=0;j<Liste->a_DimPonderation;j++)
        {
            printf("\nScore du critere ID: %.f:  ",GetMission(Liste,i)->a_tPonderation[j][0]);
            scanf("%f",&(GetMission(Liste,i)->a_tPonderation[j][1]));
            while((Clear=getchar())!=EOF&&Clear!='\n'&&Clear!='\0');
        }
        printf("\n\n\n");
    }

}