#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include "../simulation.h"
#include "LoadSimulation.h"

simulation* F_LoadAllSimulations(simulation*LoadTab,int *NbrSimusLoaded)
{
    DIR* rep = NULL;
    struct dirent* fichierLu = NULL;
    rep = opendir("./Simulations");
    seekdir(rep,2);

    char ID[20];
    int i=0;
    while((fichierLu = readdir(rep)) != NULL){
        strcpy(ID,fichierLu->d_name);
        ID[strlen(ID)-2]='\0';
        *NbrSimusLoaded += 1;
        printf("lol %d",*NbrSimusLoaded);
        //int ID = atoi(NomFichier);
        i++;
    }
    simulation *TabSimulation = NULL;
    TabSimulation = (simulation*)malloc(i*sizeof(simulation));
    rewinddir(rep);
    seekdir(rep,2);
    i=0;
    while((fichierLu = readdir(rep)) != NULL){
        strcpy(ID,fichierLu->d_name);
        ID[strlen(ID)-2]='\0';
        printf("Simulation : %s numero %d\n",ID,i);
        TabSimulation[i]=F_LoadSimulation(ID);
        printf("Simulation : %lu et %s\n",TabSimulation[i].a_ID,(TabSimulation[i].a_tNom));

        i++;
        //int ID = atoi(NomFichier);
    }
    *NbrSimusLoaded=i;

    closedir(rep);
    LoadTab = TabSimulation;
    return LoadTab;
}
