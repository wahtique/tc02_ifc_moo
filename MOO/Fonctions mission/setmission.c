#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void SetMission(FlagMission *Liste,unsigned int index,long unsigned int ID,char Nom[],float Duree)
{
    Mission *Pivot=Liste->a_Elmt1;
    int i=0;

    if(index>=Liste->a_Taille)
    {
        printf("### ERREUR:SetMission index incorrect ###");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<index;i++)
    {
        Pivot=Pivot->Suivant;
    }

    Pivot->a_ID=ID;
    Pivot->a_tNom=(char*)malloc((strlen(Nom)+1)*sizeof(char));
    strcpy(Pivot->a_tNom,Nom);

    if(Duree>0)
    {
        Pivot->a_Duree=(float)Duree;
    }
    else
    {
        printf("/!/ Impossible d attribuer une duree negative a une mission /!/\nLa mission n# %lu conserve sa duree de %.2f",Pivot->a_ID,Pivot->a_Duree);
    }

}
