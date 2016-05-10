#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#ifndef WIN32
    #include <sys/types.h>
#endif

int F_NewAgent()
{
    FILE* fichier = NULL;
    mkdir("./Agent");
    fichier = fopen("./Agent/1.g","a");

    fclose(fichier);
}
