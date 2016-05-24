#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include "../Agent.h"
#include "LoadAgent.h"

int F_LoadAllAgents(FlagAgent *Liste)
{
    DIR* rep = NULL;
    struct dirent* fichierLu = NULL;
    rep = opendir("./Agent");
    if (rep == NULL){
        mkdir("./Agent");
        rep = opendir("./Agent");
    }
    seekdir(rep,2);
    char ID[10];
    while((fichierLu = readdir(rep)) != NULL){
        strcpy(ID,fichierLu->d_name);
        ID[strlen(ID)-2]='\0';
        F_LoadAgent(Liste,ID);
        //int ID = atoi(NomFichier);
        //Faire Appel à la fction LoadAgent
    }
    closedir(rep);
    return 0;
}
