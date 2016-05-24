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
    Liste->a_DimScore=0;
    Liste->a_tScoreSchem=NULL;

}



void InsAgent(FlagAgent *Liste,unsigned int index) //OK
{
    unsigned int i=0;
    Agent *Pivot=NULL;
    Agent *NouvelAgent=NULL;
    if(index>Liste->a_Taille) // L'index peut etre égal à la taille lorsque l'on souhaite ajouter un élement
    {
        printf("### ERREUR:InsAgent: Index incorrect###");
        exit(EXIT_FAILURE);
    }
    else
    {
        NouvelAgent=(Agent*)malloc(sizeof(Agent));
        if(NouvelAgent==NULL) // Si l'allocation échoue
        {
            printf("### ERREUR:InsAgent: Allocation impossible ###");
            exit(EXIT_FAILURE);
        }
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


void AjouterAgentNP1(FlagAgent *Liste) //OK
{
    Agent *NouvelAgent=(Agent*)malloc(sizeof(Agent));
    if(NouvelAgent==NULL)
    {
        printf("### ERREUR:InsAgent: Allocation impossible ###");
        exit(EXIT_FAILURE);
    }
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

void AjouterNAgent(FlagAgent *Liste,unsigned int Qte,unsigned int CodePosition)
{
    int i=0;
    if(CodePosition==0)
    {
        for(i=0;i<Qte;i++)
        {
            AjouterAgent0(Liste);
        }
    }
    else if(CodePosition==1)
    {
        for(i=0;i<Qte;i++)
        {
            AjouterAgentNP1(Liste);
        }
    }
}

void AjouterNAgent0(FlagAgent *Liste,unsigned int Qte)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        AjouterAgent0(Liste);
    }
}

void AjouterNAgentNP1(FlagAgent *Liste,unsigned int Qte)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        AjouterAgentNP1(Liste);
    }
}

void InsNAgent(FlagAgent *Liste,unsigned int Qte,unsigned int index)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        InsAgent(Liste,index);
    }
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
    if(Pivot->a_tNom)
    {
        free(Pivot->a_tNom);
        Pivot->a_tNom=NULL;
    }


    for(i=0;i<Liste->a_DimScore;i++)
    {
        if(Pivot->a_tScore)
        {
            if((Pivot->a_tScore)[i])
            {
                free((Pivot->a_tScore)[i]);
                (Pivot->a_tScore)[i]=NULL;
            }
        }

    }


    if(Pivot->a_tScore)
    {
        free(Pivot->a_tScore);
        Pivot->a_tScore=NULL;
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

void SupListe(FlagAgent *Liste)
{
    int i=0,n=Liste->a_Taille;
    for(i=0;i<n;i++)
    {
        if(GetAgent(Liste,0))
        {
            SupAgent(Liste,0);
        }
    }


    for(i=0;i<Liste->a_DimScore;i++)
    {
        free(Liste->a_tScoreSchem[i]);
        (Liste->a_tScoreSchem)[i]=NULL;
    }
    free(Liste->a_tScoreSchem);
    Liste->a_tScoreSchem=NULL;



    if(Liste)
    {
        Liste=NULL;
    }


}


void AjouterCritere(FlagAgent *Liste)
{

    if(Liste->a_DimScore==0)
    {
        Liste->a_tScoreSchem =(float **)malloc(sizeof(float*));
        *(Liste->a_tScoreSchem)=(float*)malloc(2*sizeof(float));
        Liste->a_tScoreSchem[0][0]=1; // Le 1er critère est le critère d'ID = 1 pour réserver la valeur 0
        Liste->a_tScoreSchem[0][1]=50; // 50 est la valeur par défaut

    }
    else
    {
        Liste->a_tScoreSchem=(float **)realloc(Liste->a_tScoreSchem,(Liste->a_DimScore+1)*sizeof(float*));
        if(Liste->a_tScoreSchem==NULL)
        {
            exit(EXIT_FAILURE);
        }

        *(Liste->a_tScoreSchem)=(float*)realloc(*(Liste->a_tScoreSchem),2*sizeof(float));
        if(*Liste->a_tScoreSchem==NULL)
        {
            exit(EXIT_FAILURE);
        }
        *(Liste->a_tScoreSchem+1)=(float*)realloc(*(Liste->a_tScoreSchem+1),2*sizeof(float));
        *(Liste->a_tScoreSchem+1)=(float*)realloc(*(Liste->a_tScoreSchem+1),2*sizeof(float));
        if(*(Liste->a_tScoreSchem+1)==NULL)
        {
            exit(EXIT_FAILURE);
        }
        Liste->a_tScoreSchem[Liste->a_DimScore][0]=Liste->a_DimScore+1;
        Liste->a_tScoreSchem[Liste->a_DimScore][1]=50;
    }
    Liste->a_DimScore++;
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







