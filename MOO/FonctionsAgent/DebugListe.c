#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"


// Fonction de Debug
void DebugListe(FlagAgent *Liste)
{
    if(Liste->a_Elmt1!=NULL) //Si il y a des éléments à afficher
    {
        int i=0;
        Agent *Pivot=Liste->a_Elmt1;
        for(i=0;i<Liste->a_Taille;i++)
        {
            printf("Element %d: p: %p  &Suivant: %p  &Precedent:  %p  Salaire: %2.0f\n",i,Pivot,Pivot->Suivant==NULL?0:Pivot->Suivant,Pivot->Precedent==NULL?0:Pivot->Precedent,Pivot->a_Salaire);
            Pivot=Pivot->Suivant;

        }
    }
    else
    {
        printf("Pas d'agents dans cette liste\n");
    }
}
