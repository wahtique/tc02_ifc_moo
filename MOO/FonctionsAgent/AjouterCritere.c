#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

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
            else
            {
                i++;
            }

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
}
