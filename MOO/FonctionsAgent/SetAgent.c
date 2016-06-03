#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void SetAgent(FlagAgent *Liste,unsigned int index,long unsigned int ID,char Nom[],float Salaire) //OK
{
    Agent *Pivot=Liste->a_Elmt1;
    int i=0;

    if(index>=Liste->a_Taille)
    {
        printf("### ERREUR:SetAgent index incorrect ###");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<index;i++)
    {
        Pivot=Pivot->Suivant;
    }

    Pivot->a_ID=ID;
    Pivot->a_tNom=(char*)malloc(strlen(Nom)*sizeof(char));
    strcpy(Pivot->a_tNom,Nom);

    if(Salaire>0)
    {
        Pivot->a_Salaire=(float)Salaire;
    }
    else
    {
        printf("/!/ Impossible d attribuer un salaire negatif a un employe /!/\nL'employe n# %lu conserve son salaire de %.2f",Pivot->a_ID,Pivot->a_Salaire);
    }
}
