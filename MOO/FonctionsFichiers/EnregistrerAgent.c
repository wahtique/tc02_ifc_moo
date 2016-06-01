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
    FILE* fichier = NULL;
    char CheminFichier[10]="./Agent/";
    char AgentID[10];
    itoa(agent.a_ID,AgentID,10);
    strcat(CheminFichier,AgentID);
    strcat(CheminFichier,".g");
    printf("Fichier : %s\n",CheminFichier);
    fichier = fopen(CheminFichier,"w+");

    if (fichier != NULL)
    {

        fprintf(fichier,"ID : %lu\n",agent.a_ID);

        fprintf(fichier,"Nom : %s\n",agent.a_tNom);

        fprintf(fichier,"Salaire : %.2f\n",agent.a_Salaire);


       long unsigned int i;
       printf("Nbr de crits : %lu\n",liste.a_DimScore);
        AfficherCritereAgent(&liste);
        for (i=0;i<liste.a_DimScore;i++){
            printf("%f : %f\n",agent.a_tScore[i][0],agent.a_tScore[i][1]);
            fprintf(fichier,"%.0f : %.2f\n",agent.a_tScore[i][0],agent.a_tScore[i][1]);
        }

        fclose(fichier);
        return 0;
    }else{
        return -1;
    }
}
