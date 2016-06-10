#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

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
        ID_temp=1;

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
            else
            {
                i++;
            }
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
            Tmp2[j][1]=GetMission(Liste,i)->a_tPonderation[RecupIndexCritereM(Liste,Liste->a_tPonderationSchem[j][0])][1];
        }

        Tmp2[Liste->a_DimPonderation-1][0]=ID_temp;
        Tmp2[Liste->a_DimPonderation-1][1]=50.;

        free(GetMission(Liste,i)->a_tPonderation);

        GetMission(Liste,i)->a_tPonderation=Tmp2;
        GetMission(Liste,i)->a_DimPonderation++;
        Tmp2=NULL;

    }
}
