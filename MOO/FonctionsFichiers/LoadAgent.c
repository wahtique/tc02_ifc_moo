#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

int F_LoadAgent()
{
    FILE* fichier = NULL;
    fichier = fopen("./Agent/1.g","r");
    fscanf(fichier,"Nom : ");
    char NomAgent[25];
    fgets(NomAgent,25,fichier);
    printf("%s",NomAgent);
    fclose(fichier);
}
