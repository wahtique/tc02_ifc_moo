#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "AjoutCritRef.h"

Critere* F_LoadTabCrits(Critere *TabCritsRef,int *NbrCrits)
{
    FILE* fichier = NULL;
    fichier = fopen("TabCrits.g","r");
    if (fichier != NULL)
    {
        fscanf(fichier,"Nombre de criteres : %d\n",NbrCrits);
       // printf("Il y a %d crits\n",*NbrCrits);

        Critere *TempTab = NULL;
        TempTab = (Critere*)malloc((*NbrCrits)*sizeof(Critere));
        if (TempTab ==NULL)
        {
            exit(1);
        }
        free(TabCritsRef);

        TabCritsRef = TempTab;

        int i=0;
        char Nom[20];//Plus tard compter le nombre de char du nom et l'allouer dynamiquement
        long unsigned int ID;
        for (i=0;i<*NbrCrits;i++)
        {
         //   printf("%d sur %d\n",i+1,*NbrCrits);
            fscanf(fichier,"%lu : ",&ID);
            fgets(Nom,20,fichier);
   //         printf("Lu : %lu : %s , taille : %d",ID,Nom,strlen(Nom));
            TabCritsRef[i].a_tNom = (char*)malloc(sizeof(char)*strlen(Nom));
            strcpy(TabCritsRef[i].a_tNom,Nom);
            TabCritsRef[i].a_ID = ID;
     //       printf("Enregistre : %lu : %s\n",TabCritsRef[i].a_ID,TabCritsRef[i].a_tNom);
        }
    }
    //printf("%p    %d\n",TabCritsRef,*NbrCrits);
   /* int i;
    for (i=0;i<*NbrCrits;i++)
    {
        printf("%lu : %s\n",TabCritsRef[i].a_ID,TabCritsRef[i].a_tNom);
    }
*/

    fclose(fichier);

    return TabCritsRef;
}
