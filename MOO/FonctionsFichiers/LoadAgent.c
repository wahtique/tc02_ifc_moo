#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
#include <sys/types.h>
#endif
#include "../Agent.h"

/*
=======
#include "rechercherBalise.h"

>>>>>>> 6db81c034c99c0b004bf5c1a8daa480ea791105d
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

        fclose(fichier);


        char *NomAgentDyn=(char*)malloc(strlen(NomAgent)*sizeof(char));
        int i;
        for (i=0;i<strlen(NomAgent);i++)
        {
            NomAgentDyn[i]=NomAgent[i];
        }
        if (errorMsg == 1){
            if (atoi(ID)){
                AjouterAgent0(Liste);
                //printf("%s s'appelle %s et est paye %.2f\n",ID,NomAgent,salaire);
                SetAgent(Liste,0,atoi(ID),NomAgentDyn,salaire);
            } else {
                errorMsg = -3; //Erreur de nommage fichier
            }
        }
    } else {
        errorMsg = -1; //erreur d'ouverture fichier
    }
    return errorMsg;
}
*/
