#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void SaisieScore(FlagAgent *Liste)
{
    int i=0,j=0;
    char Clear=0;
    printf("Veuillez saisir les scores des agents un a un:\n\n");
    for(i=0;i<Liste->a_Taille;i++)
    {
        printf("Agent %s   n# %d",GetAgent(Liste,i)->a_tNom,i+1);
        for(j=0;j<Liste->a_DimScore;j++)
        {
            printf("\nScore du critere ID: %.f:  ",GetAgent(Liste,i)->a_tScore[j][0]);
            scanf("%f",&(GetAgent(Liste,i)->a_tScore[j][1]));
            while((Clear=getchar())!=EOF&&Clear!='\n'&&Clear!='\0');
        }
        printf("\n\n\n");
    }
}
