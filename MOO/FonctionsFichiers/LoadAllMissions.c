#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include "../Mission.h"
#include "LoadMission.h"

int F_LoadAllMissions(FlagMission *Liste,int NbrCrits)
{
    int i;
    for (i=0;i<NbrCrits;i++)
    {
        AjouterCritereM(Liste);
    }
    DIR* rep = NULL;
    struct dirent* fichierLu = NULL;
    rep = opendir("./Mission");
    seekdir(rep,2);
    char ID[10];
    while((fichierLu = readdir(rep)) != NULL){
        strcpy(ID,fichierLu->d_name);
        ID[strlen(ID)-2]='\0';
        F_LoadMission(Liste,ID);
        //int ID = atoi(NomFichier);
        //Faire Appel à la fction LoadMission
    }
    closedir(rep);
    return 0;
}
