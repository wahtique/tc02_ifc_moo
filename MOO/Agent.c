#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agent.h"


void InitAgent(Agent *Membre) //OK
{
    Membre->a_ID=0;
    Membre->a_tScore=NULL;
    Membre->a_tNom=NULL;
    Membre->a_Salaire=0;

    Membre->Suivant=NULL;
    Membre->Precedent=NULL;


}


void InitFlagAgent(FlagAgent *Liste) //OK
{
    Liste->a_Elmt1=NULL;
    Liste->a_Elmtn=NULL;
    Liste->a_Taille=0;

    //Expérimental

    Liste->a_LongueurSegment=5;
    Liste->a_Ref=NULL;


}



void InsAgent(FlagAgent *Liste,unsigned int index) //OK
{
    unsigned int i=0;
    Agent *Pivot=NULL;
    Agent *NouvelAgent=NULL;

    if(index>Liste->a_Taille) // L'index peut etre égal à la taille lorsque l'on souhaite ajouter un élement
    {
        printf("### ERREUR:InsAgent: Index incorrect");
        exit(EXIT_FAILURE);
    }
    else
    {

        NouvelAgent=(Agent*)malloc(sizeof(Agent));
        InitAgent(NouvelAgent);
    }

    Pivot=Liste->a_Elmt1;

    for(i=0;i<index;i++) // On parcours les agens jusqu'à atteindre le i-ème en partant du début
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
        if(Pivot==NULL) //Si on ajoute à la fin
        {

            Liste->a_Elmtn->Suivant=NouvelAgent;
            NouvelAgent->Precedent=Liste->a_Elmtn;
            Liste->a_Elmtn=NouvelAgent;
        }
        else if(Pivot->Precedent==NULL)//Si on ajoute au début
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


    Liste->a_Taille++;

}


 void AjouterAgent0(FlagAgent *Liste) //OK
 {
    Agent *NouvelAgent=(Agent*)malloc(sizeof(Agent));
    InitAgent(NouvelAgent);
    if(Liste->a_Elmt1!=NULL)
    {


        Liste->a_Elmt1->Precedent=NouvelAgent;
        NouvelAgent->Suivant=Liste->a_Elmt1;
        Liste->a_Elmt1=NouvelAgent;



    }
    else
    {

        Liste->a_Elmt1=NouvelAgent;
        Liste->a_Elmtn=Liste->a_Elmt1;



    }

    Liste->a_Taille++;
 }


void AjouterAgentNP1(FlagAgent *Liste)
{
    Agent *NouvelAgent=(Agent*)malloc(sizeof(Agent));
    InitAgent(NouvelAgent);
    if(Liste->a_Elmt1!=NULL)
    {
        Liste->a_Elmtn->Suivant=NouvelAgent;
        NouvelAgent->Precedent=Liste->a_Elmtn;
        Liste->a_Elmtn=NouvelAgent;
    }
    else
    {
        Liste->a_Elmt1=NouvelAgent;
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    Liste->a_Taille++;
}

Agent *GetAgent(FlagAgent *Liste,unsigned int index) //OK
{
    if(Liste->a_Elmt1!=NULL)
    {
        if(index>=Liste->a_Taille)
        {
            printf("###ERREUR:GetAgent: Index incorrect###");
            exit(EXIT_FAILURE);
        }

        Agent *Pivot=Liste->a_Elmt1;
        int i=0;
        for(i=0;i<index;index++)
        {
            Pivot=Pivot->Suivant;
        }

        return Pivot;
    }
    else
    {
        return NULL;
    }


}





void SupAgent(FlagAgent *Liste,unsigned int index) //OK
{
    unsigned int i=0;
    Agent *Pivot=NULL;

    if(index>=Liste->a_Taille)
    {
        printf("### ERREUR:SupAgent: Index incorrect ####");
        exit(EXIT_FAILURE);
    }


    Pivot=Liste->a_Elmt1;

    for(i=0;i<index;i++) // On parcours les agents jusqu'à atteindre le i-ème en partant du début
    {
        Pivot=Pivot->Suivant;
    }

    free(Pivot->a_tNom);
    free(Pivot->a_tScore);
    if(Pivot->Suivant==NULL&&Pivot->Precedent==NULL) //Si il n y a qu'un seul élément
    {
        free(Pivot);
        Liste->a_Elmt1=NULL;
        Liste->a_Elmtn=NULL;
    }
    else if(Pivot->Precedent==NULL)//Si on supprime au début
    {
        Liste->a_Elmt1=Liste->a_Elmt1->Suivant;
        Liste->a_Elmt1->Precedent=NULL;
        free(Pivot);
    }
    else if(Pivot->Suivant==NULL)
    {
        Liste->a_Elmtn=Liste->a_Elmtn->Precedent;
        Liste->a_Elmtn->Suivant=NULL;
        free(Pivot);
    }
    else // Si on supprime au millieu ...
    {


        Pivot->Precedent->Suivant=Pivot->Suivant;
        Pivot->Suivant->Precedent=Pivot->Precedent;
        free(Pivot);
    }



    if(Liste->a_Taille>0)
    {
        Liste->a_Taille--; //Si la liste contient des éléments, on décremente la nombre d'élément, sinon on reste à 0
    }


}


void SetAgent(FlagAgent *Liste,unsigned int index,unsigned int ID,char Nom[],float Salaire) //OK
{
    Agent *Pivot=Liste->a_Elmt1;
    int i=0;

    if(index>=Liste->a_Taille)
    {
        printf("### ERREUR: index incorrect ###");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<index;i++)
    {
        Pivot=Pivot->Suivant;
    }

    Pivot->a_ID=ID;
    Pivot->a_tNom=(char*)malloc(strlen(Nom)*sizeof(char));
    strcpy(Pivot->a_tNom,Nom);
    Pivot->a_Salaire=(float)Salaire;


}





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


