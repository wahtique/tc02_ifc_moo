#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include "../Agent.h"

int F_LoadAgent(FlagAgent *Liste,char ID[])
{
    FILE* fichier = NULL;
    char NomFichier[] = "./Agent/";
    strcat(NomFichier,ID);
    strcat(NomFichier,".g");
    fichier = fopen(NomFichier,"r");

    F_RechercheBalise(fichier,"Nom : ");
    char NomAgent[30];
    fgets(NomAgent,30,fichier);

    F_RechercheBalise(fichier,"Salaire : ");
    float salaire;
    fscanf(fichier,"%f",&salaire);

    //printf("%s s'appelle %s et est paye %.2f\n",ID,NomAgent,salaire);
    fclose(fichier);
    AjouterAgent0(Liste);

    char *NomAgentDyn=(char*)malloc(strlen(NomAgent)*sizeof(char));
    int i;
    for (i=0;i<strlen(NomAgent);i++)
    {
        NomAgentDyn[i]=NomAgent[i];
    }
    SetAgent(Liste,0,atoi(ID),NomAgentDyn,salaire);
}

