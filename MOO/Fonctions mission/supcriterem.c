#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

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