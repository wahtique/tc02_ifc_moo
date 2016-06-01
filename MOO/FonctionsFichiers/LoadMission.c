#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
#include <sys/types.h>
#endif
#include "../Mission.h"
#include "rechercherBalise.h"

int F_LoadMission(FlagMission *Liste,char ID[])
{
    int errorMsg = 1;
    FILE* fichier = NULL;
    char NomFichier[] = "./Mission/";
    strcat(NomFichier,ID);
    strcat(NomFichier,".g");
    fichier = fopen(NomFichier,"r");
    if (fichier != NULL){
        char NomMission[30];
        if (F_RechercheBalise(fichier,"Nom : ")){
            fgets(NomMission,30,fichier);
   //         printf("Nom :%s",NomMission);
        } else {
            errorMsg = -2; //Erreur formatage
        }

        float Duree ;
        if (F_RechercheBalise(fichier,"Duree : ")){
            if(fscanf(fichier,"%f",&Duree)==0){
                errorMsg =-2;
            }
        } else {
            errorMsg =-2; //Erreur formatage
        }
 //       printf("Duree : %f",Duree);


        char *NomMissionDyn=(char*)malloc(strlen(NomMission)*sizeof(char));
        int i;
        strcpy(NomMissionDyn,NomMission);
        if (errorMsg == 1){
            if (atoi(ID)){
                AjouterMission0(Liste);
                //printf("%s s'appelle %s et est paye %.2f\n",ID,NomMission,salaire);
                SetMission(Liste,0,atoi(ID),NomMissionDyn,Duree);
            } else {
                errorMsg = -3; //Erreur de nommage fichier
            }
        }
        if (errorMsg == 1){
            float IDcrit,PonderationCrit;
            Mission *mission =GetMission(Liste,0);
            i=0;
            while (!feof(fichier) && i<Liste->a_DimPonderation)
            {
                fgetc(fichier);
                fscanf(fichier,"%f : %f",&IDcrit,&PonderationCrit);
                printf("%f : %f\n",IDcrit,PonderationCrit);
                mission->a_tPonderation[i][0]=IDcrit;
                mission->a_tPonderation[i][1]=PonderationCrit;
                i++;
            }
            printf("end\n");
        }

        fclose(fichier);
    } else {
        errorMsg = -1; //erreur d'ouverture fichier
    }
    return errorMsg;
}
