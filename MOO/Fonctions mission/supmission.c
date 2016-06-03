#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void SupMission(FlagMission *Liste,unsigned int index)
{

    unsigned int i=0;
    Mission *Pivot=NULL;

    if(index>=Liste->a_Taille)
    {
        printf("### ERREUR:SupMission: Index incorrect ###");
        exit(EXIT_FAILURE);
    }

    Pivot=Liste->a_Elmt1;

    for(i=0;i<index;i++) // On parcours les mission jusqu'à atteindre la i-ème en partant du début
    {
        Pivot=Pivot->Suivant;
    }
    if(Pivot->a_tNom)
    {
      //  free(Pivot->a_tNom);
     //   Pivot->a_tNom=NULL;
    }

    for(i=0;i<Liste->a_DimPonderation;i++)
    {
        if(Pivot->a_tPonderation)
        {
            if(Pivot->a_tPonderation[i])
            {
                if((Pivot->a_tPonderation)[i])
                {
   //                free(Pivot->a_tPonderation[i]);
     //              (Pivot->a_tPonderation)[i]=NULL;
                }
            }
        }
    }

    if(Pivot->a_tPonderation)
    {
        free(Pivot->a_tPonderation);
        Pivot->a_tPonderation=NULL;
    }


    if(Pivot->Suivant==NULL&&Pivot->Precedent==NULL) //Si il n y a qu'un seul élément
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
        Liste->a_Taille--; //Si la liste contient des éléments, on décremente la nombre d'élément, sinon on reste à 0
    }


}
