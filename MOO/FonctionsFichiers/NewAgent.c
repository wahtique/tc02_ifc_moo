#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

int F_NewAgent(char Nom[])
{
    FILE* fichier = NULL;
    mkdir("./Agent");
    fichier = fopen("./Agent/1.g","w+");
    fprintf(fichier,"Nom : %s",Nom);
    fclose(fichier);
}
