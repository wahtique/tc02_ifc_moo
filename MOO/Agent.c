#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Critere.h"
#include "Agent.h"

void InitAgent(Agent *Membre) //OK
{
    Membre->a_ID=0;
    Membre->a_tScore=NULL;
    Membre->a_tNom=NULL;
    Membre->a_Salaire=0;
    Membre->a_DimScore=0;

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


    //Initialisation des critères



    Liste->a_Taille++;
}


void AjouterAgent0(FlagAgent *Liste)
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

    MajCritereAgent(Liste,0);
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
    MajCritereAgent(Liste,Liste->a_Taille-1);
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
        for(i=0;i<index;i++)
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

long unsigned int GetIndexAgent(FlagAgent *Liste, long unsigned int ID)
{
    int i, index = -1;
    for(i=0;i<Liste->a_Taille;i++)
    {
        index += (GetAgent(Liste, i)->a_ID == ID) * (GetAgent(Liste, i)->a_ID + 1);
    }
    if(index == -1)
    {
        return NULL;
    }
    else
    {
        return (long unsigned int)index;
    }
}


<<<<<<< HEAD
=======
Agent *GetAgentViaID(FlagAgent *Liste,unsigned int ID)
{
    int i=0;
    for(i=0;i<Liste->a_Taille;i++)
    {
        if(GetAgent(Liste,i)->a_ID==i)
        {
            return i;
        }
        else
        {
            printf("\n###AUCUN AGENT TROUVE AVEC CET ID###\n");
            return 0;
        }
    }
}


>>>>>>> 56217bc63fe19846c4ce8cbb1c3ac3fb61b4f2e3
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
        printf("### ERREUR:SupAgent: Index incorrect ###");
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
                free(Pivot->a_tScore[i]);
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
    float **Tmp=NULL;
    int i=0,j=0;
    float ID_temp=0.;
    Tmp=(float**)malloc((Liste->a_DimScore+1)*sizeof(float*));
    if(Tmp==NULL)
    {
        printf("###ERREUR: AjouterCritere: Erreur d'allocation ###");
        exit(EXIT_FAILURE);
    }
    if(Liste->a_DimScore==0)
    {
        Liste->a_tScoreSchem =(float **)malloc(sizeof(float*));
        *(Liste->a_tScoreSchem)=(float*)malloc(2*sizeof(float));
        Liste->a_tScoreSchem[0][0]=1; // Le 1er critère est le critère d'ID = 1 pour réserver la valeur 0
        Liste->a_tScoreSchem[0][1]=50; // 50 est la valeur par défaut
        ID_temp=1.;

    }
    else
    {


        for(i=0;i<Liste->a_DimScore;i++)
        {
            Tmp[i]=Liste->a_tScoreSchem[i];
        }

        free(Liste->a_tScoreSchem);
        Liste->a_tScoreSchem=Tmp;

        Liste->a_tScoreSchem[Liste->a_DimScore]=(float*)malloc(sizeof(float)*2);
        i=0;
        ID_temp=1.;

        while(i<=Liste->a_DimScore) //Pour s'assurer l'unicité de l'ID
        {
            if((int)ID_temp==(int)Liste->a_tScoreSchem[i][0])
            {
                ID_temp++;
                i=0;
            }
            i++;
        }

        Liste->a_tScoreSchem[Liste->a_DimScore][0]=ID_temp;
        Liste->a_tScoreSchem[Liste->a_DimScore][1]=50.;

    }
    Liste->a_DimScore++;

    Tmp=NULL;

    float **Tmp2=NULL;
    for(i=0;i<Liste->a_Taille;i++)
    {

        Tmp2=(float**)malloc(Liste->a_DimScore*sizeof(float*));

        if(Tmp2==NULL)
        {
            printf("ERREUR: ECHEC D'ALLOCATION");
            exit(EXIT_FAILURE);
        }


        for(j=0;j<Liste->a_DimScore;j++)
        {
            Tmp2[j]=(float*)malloc(2*sizeof(float));

            if(Tmp2[j]==NULL)
            {
                printf("ERREUR: ECHEC D'ALLOCATION");
                exit(EXIT_FAILURE);
            }

        }

        for(j=0;j<GetAgent(Liste,i)->a_DimScore;j++)
        {
            Tmp2[j][0]=Liste->a_tScoreSchem[j][0];
            Tmp2[j][1]=GetAgent(Liste,i)->a_tScore[RecupIndexCritere(Liste,Liste->a_tScoreSchem[j][0])][1];
        }

        Tmp2[Liste->a_DimScore-1][0]=ID_temp;
        Tmp2[Liste->a_DimScore-1][1]=50.;

        free(GetAgent(Liste,i)->a_tScore);

        GetAgent(Liste,i)->a_tScore=Tmp2;
        GetAgent(Liste,i)->a_DimScore++;
        Tmp2=NULL;

    }
<<<<<<< HEAD
=======

>>>>>>> 56217bc63fe19846c4ce8cbb1c3ac3fb61b4f2e3
}


void SupCritere(FlagAgent* Liste,unsigned int IDCritere) //OK A priori à Check
{
    float **Temp=NULL;
    Temp=(float**)malloc((Liste->a_DimScore-1)*sizeof(float*));
    int i=0,j=0,k=0;

    for(i=0;i<Liste->a_DimScore;i++)
    {
        if((int)Liste->a_tScoreSchem[i][0]!=IDCritere)
        {
            //printf("TEST: %.0f   i  %d \n",(Liste->a_tScoreSchem[i][0]),j);
            Temp[j]=Liste->a_tScoreSchem[j];
            j++;
        }
    }

    if(IDCritere==0)
    {
        printf("\n###ATTENTION:SupCritere: L'ID 0 n'est pas un critère###\n");
    }

    if(j==0)
    {
        printf("\n###ERREUR: L'ID de critère n'est pas valide ###");
        exit(EXIT_FAILURE);
    }


    free(Liste->a_tScoreSchem);
    Liste->a_tScoreSchem=Temp;
    Liste->a_DimScore--;

    float**Tmp2=NULL;
    int IndexIgnore=0;
    for(i=0;i<Liste->a_Taille;i++) //On parcours tous les agents
    {
        k=0;
        IndexIgnore=0;
        Tmp2=(float**)malloc(Liste->a_DimScore*sizeof(float*));
        for(j=0;j<Liste->a_DimScore;j++)
        {
            Tmp2[j]=(float*)malloc(2*sizeof(float));
        }

        for(j=0;j<GetAgent(Liste,i)->a_DimScore;j++) // On recherche l'index du critère à ne pas sauvegarder
        {
            if((int)GetAgent(Liste,i)->a_tScore[j][0]==IDCritere)
            {
                IndexIgnore=j;
            }
        }
        if(IndexIgnore==0)
        {
            printf("###ERREUR: SupCritere: Critere inexistant###");
            exit(EXIT_FAILURE);
        }

        for(j=0;j<GetAgent(Liste,i)->a_DimScore;j++)
        {
            if(j!=IndexIgnore) //Si ce n'est pas le critère supprimé
            {
                Tmp2[k][0]=GetAgent(Liste,i)->a_tScore[j][0];
                Tmp2[k][1]=GetAgent(Liste,i)->a_tScore[j][1];
                k++;
            }
        }
        free(GetAgent(Liste,i)->a_tScore);
        GetAgent(Liste,i)->a_tScore=Tmp2;
        GetAgent(Liste,i)->a_DimScore--;
        Tmp2=NULL;
    }
<<<<<<< HEAD
=======

>>>>>>> 56217bc63fe19846c4ce8cbb1c3ac3fb61b4f2e3
}

int RecupIndexCritere(FlagAgent *Liste,float ID)
{
    int i=0;

    for(i=0;i<Liste->a_DimScore;i++)
    {
        if((int)Liste->a_tScoreSchem[i][0]==(int)ID)
        {
            return i;
        }
    }
    if(i==Liste->a_DimScore)
    {
        printf("Erreur index");
        return -1;
    }
}

void MajCritereAgent(FlagAgent *Liste,unsigned int indexAgent)
{
    if(Liste->a_DimScore>0)
    {
        int i=0;

        GetAgent(Liste,indexAgent)->a_tScore=(float**)malloc(Liste->a_DimScore*sizeof(float*));
        for(i=0;i<Liste->a_DimScore;i++)
        {
            GetAgent(Liste,indexAgent)->a_tScore[i]=(float*)malloc(2*sizeof(float));
            GetAgent(Liste,indexAgent)->a_tScore[i][0]=Liste->a_tScoreSchem[i][0];
            GetAgent(Liste,indexAgent)->a_tScore[i][1]=Liste->a_tScoreSchem[i][1];
        }
        GetAgent(Liste,indexAgent)->a_DimScore=Liste->a_DimScore;
    }
<<<<<<< HEAD
=======

>>>>>>> 56217bc63fe19846c4ce8cbb1c3ac3fb61b4f2e3
}

void SaisieScore(FlagAgent *Liste)
{
    int i=0,j=0;
    char Clear=0;
    printf("Veuillez saisir les scores des agents un a un:\n\n");
    for(i=0;i<Liste->a_Taille;i++)
    {
        printf("Agent %s   n# %d",GetAgent(Liste,i)->a_tNom,i+1);
        for(j=0;j<Liste->a_DimScore;j++)
        {
            printf("\nScore du critere ID: %.f:  ",GetAgent(Liste,i)->a_tScore[j][0]);
            scanf("%f",&(GetAgent(Liste,i)->a_tScore[j][1]));
            while((Clear=getchar())!=EOF&&Clear!='\n'&&Clear!='\0');
        }
        printf("\n\n\n");
    }
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


void AfficherCritere(Critere *ListeCritere,long unsigned int TailleDuTableau)
{
    int i=0;
    for(i=0;i<TailleDuTableau;i++)
    {
        printf("%s   n°: %d\n",ListeCritere[i].a_tNom,ListeCritere[i].a_ID);
    }
}

void AfficherCritereAgent(FlagAgent *Liste)
{
    int i=0,j=0;
    for(i=0;i<Liste->a_Taille;i++)
    {

        printf("Agent n: %d: \n",i);
        for(j=0;j<Liste->a_DimScore;j++)
        {
            printf("ID: %f   Score: %f\n",GetAgent(Liste,i)->a_tScore[j][0],GetAgent(Liste,i)->a_tScore[j][1]);
        }
    }
    printf("\n");
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







