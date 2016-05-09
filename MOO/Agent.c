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

void cpAgent(Agent *MembreRemplace,Agent *MembreACopier) // Les attributs de MembreRemplace deviennent ceux de MembreACopier
{
    MembreRemplace->a_ID=MembreACopier->a_ID;
    MembreRemplace->a_tScore=MembreACopier->a_tScore;
    strcpy(MembreRemplace->a_tNom,MembreACopier->a_tNom);


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


void AjouterAgent(FlagAgent *Liste,int index)
{
    if(index>Liste->a_Taille+1) // Vérification de l'index entré
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
        Pivot->Precedent=NouvelAgent;
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
        Pivot->Precedent=NouvelAgent;
    }


    //InitAgent(Curseur);
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

        printf("Element %d: p: %p    &Suivant: %p    &Precedent:  %p     Salaire: %f\n",i,Pivot,Pivot->Suivant==NULL?0:Pivot->Suivant,Pivot->Precedent==NULL?0:Pivot->Precedent,Pivot->a_Salaire);
        Pivot=Pivot->Suivant;
    }

}


