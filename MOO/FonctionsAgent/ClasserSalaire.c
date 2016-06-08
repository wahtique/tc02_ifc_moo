#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"


void ClasserSalaire(FlagAgent *Liste)
{
    //DebugListe(Liste);
    static int Domaine=0;
    //printf("  %d  ",Domaine);
    Agent *Tmp;
    Agent *Tmp2=NULL;
    if(Domaine==0) //Astuce pour initialiser un static
    {
        Domaine=Liste->a_Taille;
    }

    float ScoreRef=Liste->a_Elmt1->a_Salaire;

    int i=0,index=0;
    //Recherche d'un maximum
    for(i=0;i<Domaine;i++)
    {
        if(ScoreRef<GetAgent(Liste,i)->a_Salaire)
        {
            ScoreRef=GetAgent(Liste,i)->a_Salaire;
            index=i;
        }
    }
    //On réduit le domaine de recherche
    Domaine--;
    //On place le maximum à la fin de la liste
    Tmp=GetAgent(Liste,index);
    Tmp2=GetAgent(Liste,Domaine);



    if(Tmp!=Tmp2)
    {


        if(Tmp->Precedent!=NULL)
        {
            Tmp->Precedent->Suivant=Tmp->Suivant;
        }
        else
        {
            Liste->a_Elmt1=Tmp->Suivant;
        }


        Tmp->Suivant->Precedent=Tmp->Precedent;
        Tmp->Precedent=Tmp2;

        Tmp->Suivant=Tmp2->Suivant;
        if(Tmp2->Suivant!=NULL)
        {
            Tmp2->Suivant->Precedent=Tmp;
        }
        else
        {
            Liste->a_Elmtn=Tmp;
        }

        Tmp2->Suivant=Tmp;

    }



    if(Domaine>0)
    {
        ClasserSalaire(Liste);
    }
    else
    {
        //Rien
    }


}

