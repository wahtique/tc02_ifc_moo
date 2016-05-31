#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Critere.h"
#include "Mission.h"

void InitMission(Mission *Membre)
{
    Membre->a_ID=0;
    Membre->a_tPonderation=NULL;
    Membre->a_tNom=NULL;
    Membre->a_Duree=0;
    Membre->a_DimPonderation=0;

    Membre->Suivant=NULL;
    Membre->Precedent=NULL;


}

void InitFlagMission(FlagMission *Liste)
{
    Liste->a_Elmt1=NULL;
    Liste->a_Elmtn=NULL;
    Liste->a_Taille=0;
    Liste->a_DimPonderation=0;
    Liste->a_tPonderationSchem=NULL;

}


void AjouterMissionNP1(FlagMission *Liste)
{
    Mission *NouvelleMission=(Mission*)malloc(sizeof(Mission));
    if(NouvelleMission==NULL)
    {
        printf("### ERREUR:InsMission: Allocation impossible ###");
        exit(EXIT_FAILURE);
    }
    InitAgent(NouvelleMission);
    if(Liste->a_Elmt1!=NULL)
    {
        Liste->a_Elmtn->Suivant=NouvelleMission;
        NouvelleMission->Precedent=Liste->a_Elmtn;
        Liste->a_Elmtn=NouvelleMission;
    }
    else
    {
        Liste->a_Elmt1=NouvelleMission;
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    Liste->a_Taille++;

    // -----------------  A REWORK --------------------------
    MajCritereAgent(Liste,Liste->a_Taille-1);


}

void AjouterNMissionNP1(FlagMission *Liste,unsigned int Qte)
{
    int i=0;
    for(i=0;i<Qte;i++)
    {
        AjouterMissionNP1(Liste);
    }
}


Mission *GetMission(FlagMission *Liste,unsigned int index)
{

    if(Liste->a_Elmt1!=NULL)
    {
        if(index>=Liste->a_Taille)
        {
            printf("###ERREUR:GetMission: Index incorrect###");
            exit(EXIT_FAILURE);
        }

        Mission *Pivot=Liste->a_Elmt1;
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

long unsigned int GetIndexMission(FlagMission *Liste, long unsigned int ID)
{
    int i, index = -1;
    for(i=0;i<Liste->a_Taille;i++)
    {
        index += (GetMission(Liste, i)->a_ID == ID) * (GetMission(Liste, i)->a_ID + 1);
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

Mission *GetMissionByIndex(FlagMission *Liste, long unsigned int ID)
{
    return GetMission(Liste, GetIndexMission(Liste, ID));
}

void SetMission(FlagMission *Liste,unsigned int index,long unsigned int ID,char Nom[],float Duree)
{
    Mission *Pivot=Liste->a_Elmt1;
    int i=0;

    if(index>=Liste->a_Taille)
    {
        printf("### ERREUR:SetMission index incorrect ###");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<index;i++)
    {
        Pivot=Pivot->Suivant;
    }

    Pivot->a_ID=ID;
    Pivot->a_tNom=(char*)malloc(strlen(Nom)*sizeof(char));
    strcpy(Pivot->a_tNom,Nom);

    if(Duree>0)
    {
        Pivot->a_Duree=(float)Duree;
    }
    else
    {
        printf("/!/ Impossible d attribuer une duree negative a une mission /!/\nLa mission n# %lu conserve sa duree de %.2f",Pivot->a_ID,Pivot->a_Duree);
    }

}


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
        free(Pivot->a_tNom);
        Pivot->a_tNom=NULL;
    }

    for(i=0;i<Liste->a_DimPonderation;i++)
    {
        if(Pivot->a_tPonderation)
        {
            if((Pivot->a_tPonderation)[i])
            {
                free(Pivot->a_tPonderation[i]);
                (Pivot->a_tPonderation)[i]=NULL;
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

void SupListeM  (FlagMission *Liste)
{
    int i=0,n=Liste->a_Taille;
    for(i=0;i<n;i++)
    {
        if(GetMission(Liste,0))
        {
            SupMission(Liste,0);
        }
    }

    for(i=0;i<Liste->a_DimPonderation;i++)
    {
        free(Liste->a_tPonderationSchem[i]);
        (Liste->a_tPonderationSchem)[i]=NULL;
    }

    free(Liste->a_tPonderationSchem);
    Liste->a_tPonderationSchem=NULL;


    if(Liste)
    {
        Liste=NULL;
    }

}


void AjouterCritereM(FlagMission *Liste)
{
    float **Tmp=NULL;
    int i=0,j=0;
    float ID_temp=0.;
    Tmp=(float**)malloc((Liste->a_DimPonderation+1)*sizeof(float*));
    if(Tmp==NULL)
    {
        printf("###ERREUR: AjouterCritere: Erreur d'allocation ###");
        exit(EXIT_FAILURE);
    }
    if(Liste->a_DimPonderation==0)
    {
        Liste->a_tPonderationSchem =(float **)malloc(sizeof(float*));
        *(Liste->a_tPonderationSchem)=(float*)malloc(2*sizeof(float));
        Liste->a_tPonderationSchem[0][0]=1; // Le 1er critère est le critère d'ID = 1 pour réserver la valeur 0
        Liste->a_tPonderationSchem[0][1]=50; // 50 est la valeur par défaut
    }
    else
    {

        for(i=0;i<Liste->a_DimPonderation;i++)
        {
            Tmp[i]=Liste->a_tPonderationSchem[i];
        }

        free(Liste->a_tPonderationSchem);
        Liste->a_tPonderationSchem=Tmp;

        Liste->a_tPonderationSchem[Liste->a_DimPonderation]=(float*)malloc(sizeof(float)*2);
        i=0;
        ID_temp=1;
        while(i<=Liste->a_DimPonderation) //Pour s'assurer l'unicité de l'ID
        {
            if((int)ID_temp==(int)Liste->a_tPonderationSchem[i][0])
            {
                ID_temp++;
                i=0;
            }
            i++;
        }

        Liste->a_tPonderationSchem[Liste->a_DimPonderation][0]=ID_temp;
        Liste->a_tPonderationSchem[Liste->a_DimPonderation][1]=50.;

    }
    Liste->a_DimPonderation++;

    Tmp=NULL;

    float **Tmp2=NULL;
    for(i=0;i<Liste->a_Taille;i++)
    {

        Tmp2=(float**)malloc(Liste->a_DimPonderation*sizeof(float*));

        if(Tmp2==NULL)
        {
            printf("ERREUR: ECHEC D'ALLOCATION");
            exit(EXIT_FAILURE);
        }


        for(j=0;j<Liste->a_DimPonderation;j++)
        {
            Tmp2[j]=(float*)malloc(2*sizeof(float));

            if(Tmp2[j]==NULL)
            {
                printf("ERREUR: ECHEC D'ALLOCATION");
                exit(EXIT_FAILURE);
            }

        }

        for(j=0;j<GetMission(Liste,i)->a_DimPonderation;j++)
        {
            Tmp2[j][0]=Liste->a_tPonderationSchem[j][0];
            Tmp2[j][1]=GetMission(Liste,i)->a_tPonderation[RecupIndexCritere(Liste,Liste->a_tPonderationSchem[j][0])][1];
        }

        Tmp2[Liste->a_DimPonderation-1][0]=ID_temp;
        Tmp2[Liste->a_DimPonderation-1][1]=50.;

        free(GetMission(Liste,i)->a_tPonderation);

        GetMission(Liste,i)->a_tPonderation=Tmp2;
        GetMission(Liste,i)->a_DimPonderation++;
        Tmp2=NULL;

    }
}



void SupCritereM(FlagMission* Liste,unsigned int IDCritere)
{
    float **Temp=NULL;
    Temp=(float**)malloc((Liste->a_DimPonderation-1)*sizeof(float*));
    int i=0,j=0,k=0;

    for(i=0;i<Liste->a_DimPonderation;i++)
    {
        if((int)Liste->a_tPonderationSchem[i][0]!=IDCritere)
        {
            //printf("TEST: %.0f   i  %d \n",(Liste->a_tPonderationSchem[i][0]),j);
            Temp[j]=Liste->a_tPonderationSchem[j];
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


    free(Liste->a_tPonderationSchem);
    Liste->a_tPonderationSchem=Temp;
    Liste->a_DimPonderation--;

    float**Tmp2=NULL;
    int IndexIgnore=0;
    for(i=0;i<Liste->a_Taille;i++) //On parcours toutes les missions
    {
        k=0;
        IndexIgnore=0;
        Tmp2=(float**)malloc(Liste->a_DimPonderation*sizeof(float*));
        for(j=0;j<Liste->a_DimPonderation;j++)
        {
            Tmp2[j]=(float*)malloc(2*sizeof(float));
        }

        for(j=0;j<GetMission(Liste,i)->a_DimPonderation;j++) // On recherche l'index du critère à ne pas sauvegarder
        {
            if((int)GetMission(Liste,i)->a_tPonderation[j][0]==IDCritere)
            {
                IndexIgnore=j;
            }
        }
        if(IndexIgnore==0)
        {
            printf("###ERREUR: SupCritere: Critere inexistant###");
            exit(EXIT_FAILURE);
        }

        for(j=0;j<GetMission(Liste,i)->a_DimPonderation;j++)
        {
            if(j!=IndexIgnore) //Si ce n'est pas le critère supprimé
            {
                Tmp2[k][0]=GetMission(Liste,i)->a_tPonderation[j][0];
                Tmp2[k][1]=GetMission(Liste,i)->a_tPonderation[j][1];
                k++;
            }
        }
        free(GetMission(Liste,i)->a_tPonderation);
        GetMission(Liste,i)->a_tPonderation=Tmp2;
        GetMission(Liste,i)->a_DimPonderation--;
        Tmp2=NULL;
    }
}
int RecupIndexCritereM(FlagMission *Liste,float ID)
{
    int i=0;

    for(i=0;i<Liste->a_DimPonderation;i++)
    {
        if((int)Liste->a_tPonderationSchem[i][0]==(int)ID)
        {
            return i;
        }
    }
    if(i==Liste->a_DimPonderation)
    {
        printf("Erreur index");
        return -1;
    }
}

void MajCritereMission(FlagMission *Liste,unsigned int indexMission)
{
    if(Liste->a_DimPonderation>0)
    {
        int i=0,j=0;

        GetMission(Liste,indexMission)->a_tPonderation=(float**)malloc(Liste->a_DimPonderation*sizeof(float*));
        for(i=0;i<Liste->a_DimPonderation;i++)
        {
            GetMission(Liste,indexMission)->a_tPonderation[i]=(float*)malloc(2*sizeof(float));
            GetMission(Liste,indexMission)->a_tPonderation[i][0]=Liste->a_tPonderationSchem[i][0];
            GetMission(Liste,indexMission)->a_tPonderation[i][1]=Liste->a_tPonderationSchem[i][1];
        }
        GetMission(Liste,indexMission)->a_DimPonderation=Liste->a_DimPonderation;
    }


}

void SaisieScoreM(FlagMission *Liste)
{
    int i=0,j=0;
    char Clear=0;
    printf("Veuillez saisir les pondérations des missions une a une:\n\n");
    for(i=0;i<Liste->a_Taille;i++)
    {
        printf("Mission %s   n# %d",GetMission(Liste,i)->a_tNom,i+1);
        for(j=0;j<Liste->a_DimPonderation;j++)
        {
            printf("\nScore du critere ID: %.f:  ",GetMission(Liste,i)->a_tPonderation[j][0]);
            scanf("%f",&(GetMission(Liste,i)->a_tPonderation[j][1]));
            while((Clear=getchar())!=EOF&&Clear!='\n'&&Clear!='\0');
        }
        printf("\n\n\n");
    }

}


void AfficherListeMission(FlagMission *Liste)
{
    if(Liste->a_Elmt1!=NULL)
    {
        int i=0;
        Mission *Pivot=Liste->a_Elmt1;
        for(i=0;i<Liste->a_Taille;i++)
        {

            printf("Mission %d: Nom: %s  Duree: %5.0f\n",Pivot->a_ID,Pivot->a_tNom==NULL?'\0':Pivot->a_tNom,Pivot->a_Duree);
            Pivot=Pivot->Suivant;

        }
    }
    else
    {
        printf("Pas de missions dans cette liste\n");
    }

}


void AfficherCritereM(Critere *ListeCritere,long unsigned int TailleDuTableau)
{
    int i=0;
    for(i=0;i<TailleDuTableau;i++)
    {
        printf("%s   n°: %d\n",ListeCritere[i].a_tNom,ListeCritere[i].a_ID);
    }
}

void AfficherCritereMission(FlagMission *Liste)
{
    int i=0,j=0;
    for(i=0;i<Liste->a_Taille;i++)
    {

        printf("Agent n: %d: \n",i);
        for(j=0;j<Liste->a_DimPonderation;j++)
        {
            printf("ID: %f   Score: %f\n",GetMission(Liste,i)->a_tPonderation[j][0],GetMission(Liste,i)->a_tPonderation[j][1]);
        }
    }
    printf("\n");
}

