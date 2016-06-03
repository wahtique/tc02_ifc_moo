#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

// Affichage

void AfficherListeAgent(FlagAgent *Liste)
{
    if(Liste->a_Elmt1!=NULL)
    {
        int i=0;
        Agent *Pivot=Liste->a_Elmt1;
        for(i=0;i<Liste->a_Taille;i++)
        {

            printf("Agent %d: Nom: %s  Salaire: %5.0f\n",Pivot->a_ID,Pivot->a_tNom==NULL?'\0':Pivot->a_tNom,Pivot->a_Salaire);
            Pivot=Pivot->Suivant;
        }
    }
    else
    {
        printf("Pas d'agents dans cette liste\n");
    }
}
