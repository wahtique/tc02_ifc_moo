#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void InsAgent(FlagAgent *Liste,unsigned int index) //OK
{
    unsigned int i=0;
    Agent *Pivot=NULL;
    Agent *NouvelAgent=NULL;
    if(index>Liste->a_Taille) // L'index peut etre �gal � la taille lorsque l'on souhaite ajouter un �lement
    {
        printf("### ERREUR:InsAgent: Index incorrect###");
        exit(EXIT_FAILURE);
    }
    else
    {
        NouvelAgent=(Agent*)malloc(sizeof(Agent));
        if(NouvelAgent==NULL) // Si l'allocation �choue
        {
            printf("### ERREUR:InsAgent: Allocation impossible ###");
            exit(EXIT_FAILURE);
        }
        InitAgent(NouvelAgent);
    }
    Pivot=Liste->a_Elmt1;
    for(i=0;i<index;i++) // On parcours les agens jusqu'� atteindre le i-�me en partant du d�but
    {
        Pivot=Pivot->Suivant;
    }
    if(Liste->a_Taille==0) // Si la liste est encore vide
    {
        Liste->a_Elmt1=NouvelAgent;
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    else
    {
        if(Pivot==NULL) //Si on ajoute � la fin
        {
            Liste->a_Elmtn->Suivant=NouvelAgent;
            NouvelAgent->Precedent=Liste->a_Elmtn;
            Liste->a_Elmtn=NouvelAgent;
        }
        else if(Pivot->Precedent==NULL)//Si on ajoute au d�but
        {
            Liste->a_Elmt1->Precedent=NouvelAgent;
            NouvelAgent->Suivant=Liste->a_Elmt1;
            Liste->a_Elmt1=NouvelAgent;
        }
        else // Si on ajoute au millieu ...
        {
            NouvelAgent->Precedent=Pivot->Precedent;
            NouvelAgent->Suivant=Pivot;
            Pivot->Precedent->Suivant=NouvelAgent;
            Pivot->Precedent=NouvelAgent;
        }
    }


    //Initialisation des crit�res


    Liste->a_Taille++;
}
