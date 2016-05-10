#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agent.h"


void InitAgent(Agent *Membre)
{
    Membre->a_ID=0;
    Membre->a_tScore=NULL;
    Membre->a_tNom=NULL;
    Membre->a_Salaire=0;

    Membre->Suivant=NULL;
    Membre->Precedent=NULL;


}


void InitFlagAgent(FlagAgent *Liste)
{
    Liste->a_Elmt1=NULL;
    Liste->a_Elmtn=NULL;
    Liste->a_Taille=0;

    //Expérimental

    Liste->a_LongueurSegment=5;
    Liste->a_Ref=NULL;


}

/*

void AjouterAgent(FlagAgent *Liste,int index)
{
    if(index>Liste->a_Taille+1) // Vérification de l'index entré
    {
        printf("ERREUR: Index incorrect \a");
        break;
    }

    int i=0;
    if(Liste->a_Elmt1==NULL)
    {
        Liste->a_Elmt1=(Agent*)malloc(sizeof(Agent));
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    else if(index>Liste->a_Taille/2)
    {
        for(i=n;i>=index;i--)
        {

        }
    }
    else if(index<=Liste->a_Taille/2)
    {

    }


    InitAgent(Curseur);

}
*/

/*
void InsAgent(FlagAgent *Liste,int index)
{
    if(index>Liste->a_Taille) // Vérification de l'index entré
    {
        printf("ERREUR: Index incorrect \a");
        exit(EXIT_FAILURE);
    }

    int i=0;
    if(Liste->a_Elmt1==NULL)
    {
        Liste->a_Elmt1=(Agent*)malloc(sizeof(Agent));
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    else if(index>Liste->a_Taille/2)  // 0  1  2 .. i-1  i  ... n-1
    {
        Agent *NouvelAgent=(Agent*)malloc(sizeof(Agent));
        Agent *Pivot=Liste->a_Elmtn;
        for(i=index;i<Liste->a_Taille-1;i++)
        {
            Pivot=Pivot->Precedent;
        }
        // En supposant que pivot pointe sur le i-1 terme
        NouvelAgent->Precedent=Pivot->Precedent;
        NouvelAgent->Suivant=Pivot;
        Pivot=NouvelAgent;


        if(index==Liste->a_Taille)
        {
            Liste->a_Elmtn=NouvelAgent;
        }
    }
    else if(index<=Liste->a_Taille/2)
    {
        Agent *NouvelAgent=(Agent*)malloc(sizeof(Agent));
        Agent *Pivot=Liste->a_Elmt1;
        printf("Bla\n");
        for(i=0;i<index;i++)
        {
            Pivot=Pivot->Suivant;
        }
        // En supposant que pivot pointe sur le i terme
        NouvelAgent->Precedent=Pivot->Precedent;
        NouvelAgent->Suivant=Pivot;
        Pivot=NouvelAgent;

        if(index==Liste->a_Taille)
        {
            Liste->a_Elmtn=NouvelAgent;
        }


    }

    //InitAgent(Curseur);
    Liste->a_Taille++;

}
*/

void InsAgent(FlagAgent *Liste,unsigned int index) //OK
{
    unsigned int i=0;
    Agent *Pivot=NULL;
    Agent *NouvelAgent=NULL;
    if(index>Liste->a_Taille)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        NouvelAgent=(Agent*)malloc(sizeof(Agent));
        InitAgent(NouvelAgent);
    }


    if(Liste->a_Taille==0) // Si la liste est encore vide
    {
        Liste->a_Elmt1=NouvelAgent;
        Liste->a_Elmtn=Liste->a_Elmt1;

    }

    Pivot=Liste->a_Elmt1;


    for(i=0;i<index;i++)
    {
        Pivot=Pivot->Suivant;
    }

    if(Pivot==NULL) //Si on ajoute un élément à la fin de la liste
    {
        Pivot=NouvelAgent;
        Liste->a_Elmtn->Suivant=Pivot;
        Pivot->Precedent=Liste->a_Elmtn;
        Liste->a_Elmtn=Pivot;
    }
    else if(Liste->a_Elmt1!=Pivot) //Si l'élélement
    {
        if(Pivot==Liste->a_Elmt1) // Si on ajoute l'élément au début
        {
            Pivot->Precedent=NouvelAgent;
            NouvelAgent->Suivant=Pivot;
        }
        else //Si on ajoute au millieu de la liste
        {
            NouvelAgent->Precedent=Pivot->Precedent;
            NouvelAgent->Suivant=Pivot;
            Pivot->Precedent=NouvelAgent;
        }
    }
    Liste->a_Taille++;

}



void AjouterAgentNP1(FlagAgent Liste)
{
    if(Liste.a_Elmt1==NULL)
    {

    }
}

 void AjouterAgent0(FlagAgent Liste)
 {

 }

void SupprimerAgent(int ID)
{

}



Agent AfficherListeAgent(Agent *PremierElement)
{
    if(PremierElement!=NULL)
    {
        printf("Agent n°: %d\n",PremierElement->a_ID);
        AfficherListeAgent(PremierElement->Suivant);
    }
    else
    {
        printf("#Fin de liste#\n");
    }

}



void DebugListe(FlagAgent *Liste)
{
    int i=0;
    Agent *Pivot=Liste->a_Elmt1;
    for(i=0;i<Liste->a_Taille;i++)
    {

        printf("Element %d: p: %p  &Suivant: %p  &Precedent:  %p  Salaire: %2.0f\n",i,Pivot,Pivot->Suivant==NULL?0:Pivot->Suivant,Pivot->Precedent==NULL?0:Pivot->Precedent,Pivot->a_Salaire);

        Pivot=Pivot->Suivant;

    }

}


