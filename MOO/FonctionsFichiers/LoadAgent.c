#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
#include <sys/types.h>
#endif
#include "../Agent.h"
#include "rechercherBalise.h"

int F_LoadAgent(FlagAgent *Liste,char ID[])
{
    int errorMsg = 1;
    FILE* fichier = NULL;
    char NomFichier[] = "./Agent/";
    strcat(NomFichier,ID);
    strcat(NomFichier,".g");
    fichier = fopen(NomFichier,"r");
    if (fichier != NULL){
        char NomAgent[30];
        if (F_RechercheBalise(fichier,"Nom : ")){
            fgets(NomAgent,30,fichier);
        } else {
            errorMsg = -2; //Erreur formatage
        }

        float salaire;
        if (F_RechercheBalise(fichier,"Salaire : ")){
            if(fscanf(fichier,"%f",&salaire)==0){
                errorMsg =-2;
            }
        } else {
            errorMsg =-2; //Erreur formatage
        }


        NomAgent[strlen(NomAgent)-1]='\0';
        char *NomAgentDyn=(char*)malloc((strlen(NomAgent)+1)*sizeof(char));
        int i;
        strcpy(NomAgentDyn,NomAgent);
        if (errorMsg == 1){
            if (atoi(ID)){
                AjouterAgent0(Liste);
                //printf("%s s'appelle %s et est paye %.2f\n",ID,NomAgent,salaire);
                SetAgent(Liste,0,atoi(ID),NomAgentDyn,salaire);
            } else {
                errorMsg = -3; //Erreur de nommage fichier
            }
        }
        if (errorMsg == 1){
            float IDcrit,ScoreCrit;
            Agent *agent =GetAgent(Liste,0);
            i=0;
            while (!feof(fichier) && i<Liste->a_DimScore)
            {
                fgetc(fichier);
                fscanf(fichier,"%f : %f",&IDcrit,&ScoreCrit);
                printf("%f : %f\n",IDcrit,ScoreCrit);
                agent->a_tScore[i][0]=IDcrit;
                agent->a_tScore[i][1]=ScoreCrit;
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

