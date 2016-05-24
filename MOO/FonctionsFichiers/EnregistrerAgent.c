#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include "../Agent.h"

int F_EnregistrerAgent(Agent agent,FlagAgent liste)
{
    DIR* rep = NULL;
    rep = opendir("./Agent");
    if (rep == NULL){
        mkdir("./Agent");
    }
    closedir(rep);


    FILE* fichier = NULL;
    char CheminFichier[10]="./Agent/";
    char AgentID[10];
    itoa((int)agent.a_ID,AgentID,10);
    strcat(CheminFichier,AgentID);
    strcat(CheminFichier,".g");
    printf("Fichier : %s\n",CheminFichier);
    fichier = fopen(CheminFichier,"w+");
    printf("ID : %lu",agent.a_ID);
    fprintf(fichier,"ID : %lu\n",agent.a_ID);
    printf("Nom : %s\n",agent.a_tNom);
    fprintf(fichier,"Nom : %s\n",agent.a_tNom);
    fprintf(fichier,"Salaire : %f\n",agent.a_Salaire);


    long unsigned int i;
    for (i=0;i<=liste.a_DimScore-1;i++){
        fprintf(fichier,"%.0f : %f",agent.a_tScore[i][0],agent.a_tScore[i][1]);
    }
    fclose(fichier);
    return 0;
}
