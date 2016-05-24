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
//    char Salaire[30];
//    fgets(Salaire,30,fichier);

    printf("%s is named %s and is payed %.2f\n",ID,NomAgent,salaire);
    fclose(fichier);
    AjouterAgent0(Liste);

    char *NomAgentDyn=(char*)malloc(strlen(NomAgent)*sizeof(char));
    //Copie Lettre a lettre
   // NomAgentDyn[0]='A';
    //NomAgentDyn[1]='\0';
    SetAgent(Liste,0,atoi(ID),NomAgent,salaire);
}

