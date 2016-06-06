#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void SupAgent(FlagAgent *Liste,unsigned int index) //OK
{
    unsigned int i=0;
    Agent *Pivot=NULL;

    if(index>=Liste->a_Taille)
    {
        printf("### ERREUR:SupAgent: Index incorrect ###");
        exit(EXIT_FAILURE);
    }



    Pivot=Liste->a_Elmt1;

    for(i=0;i<index;i++) // On parcours les agents jusqu'� atteindre le i-�me en partant du d�but
    {
        Pivot=Pivot->Suivant;
    }
    if(Pivot->a_tNom)
    {
        free(Pivot->a_tNom);
        Pivot->a_tNom=NULL;
    }

    for(i=0;i<Liste->a_DimScore;i++)
    {
        if(Pivot->a_tScore)
        {
            if(Pivot->a_tScore[i])
            {
                if((Pivot->a_tScore)[i])
                {
                    free(Pivot->a_tScore[i]);
                    (Pivot->a_tScore)[i]=NULL;
                }
            }
        }
    }

    if(Pivot->a_tScore)
    {
        free(Pivot->a_tScore);
        Pivot->a_tScore=NULL;
    }


    if(Pivot->Suivant==NULL&&Pivot->Precedent==NULL) //Si il n y a qu'un seul �l�ment
    {
        free(Pivot);
        Liste->a_Elmt1=NULL;
        Liste->a_Elmtn=NULL;

    }
    else if(Pivot->Precedent==NULL)//Si on supprime le 1er elmt
    {
        Liste->a_Elmt1=Liste->a_Elmt1->Suivant;
        Pivot->Suivant=NULL;
        free(Pivot);
        Pivot=NULL;
        Liste->a_Elmt1->Precedent=NULL;
    }
    else if(Pivot->Suivant==NULL) //Si on supprime le dernier elmt
    {
        Liste->a_Elmtn=Liste->a_Elmtn->Precedent;
        if(Pivot)
        {
            free(Pivot);
            Pivot=NULL;
        }
        Liste->a_Elmtn->Suivant=NULL;

    }
    else // Si on supprime au millieu ...
    {
        Pivot->Precedent->Suivant=Pivot->Suivant;
        Pivot->Suivant->Precedent=Pivot->Precedent;
        Pivot->Precedent=NULL;
        Pivot->Suivant=NULL;
        free(Pivot);
        Pivot=NULL;
    }

    if(Liste->a_Taille>0)
    {
        Liste->a_Taille--; //Si la liste contient des �l�ments, on d�cremente la nombre d'�l�ment, sinon on reste � 0
    }
}
