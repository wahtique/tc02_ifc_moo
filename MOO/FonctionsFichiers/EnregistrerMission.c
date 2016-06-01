#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif
#include "../Mission.h"

int F_EnregistrerMission(Mission mission,FlagMission liste)
{
    FILE* fichier = NULL;
    char CheminFichier[10]="./Mission/";
    char MissionID[10];
    itoa(mission.a_ID,MissionID,10);
    strcat(CheminFichier,MissionID);
    strcat(CheminFichier,".g");
    printf("Fichier : %s\n",CheminFichier);
    fichier = fopen(CheminFichier,"w+");

    if (fichier != NULL)
    {

        fprintf(fichier,"ID : %lu\n",mission.a_ID);

        fprintf(fichier,"Nom : %s\n",mission.a_tNom);

        fprintf(fichier,"Duree : %.2f\n",mission.a_Duree);

/*
       long unsigned int i;
       printf("Nbr de crits : %lu\n",liste.a_DimPonderation);
        AfficherCritereMission(&liste);
        for (i=0;i<liste.a_DimPonderation;i++){
            printf("%f : %f\n",mission.a_tPonderation[i][0],mission.a_tPonderation[i][1]);
            fprintf(fichier,"%.0f : %.2f\n",mission.a_tPonderation[i][0],mission.a_tPonderation[i][1]);
        }
*/
        fclose(fichier);
        return 0;
    }else{
        return -1;
    }
}
