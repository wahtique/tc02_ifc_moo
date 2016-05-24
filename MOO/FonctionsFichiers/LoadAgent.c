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

    printf("%s is named %s",ID,NomAgent);
    fclose(fichier);
}
