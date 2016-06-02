#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
#include <sys/types.h>
#endif
#include "../simulation.h"
#include "rechercherBalise.h"

simulation F_LoadSimulation(char ID[])
{
    int errorMsg = 1;
    FILE* fichier = NULL;
    char NomFichier[] = "./Simulations/";
    strcat(NomFichier,ID);
    strcat(NomFichier,".g");
    fichier = fopen(NomFichier,"r");
    simulation Simulation;

    Simulation.a_ID=atoi(ID);

    if (fichier != NULL){
        int NbrElements=0;
        if (F_RechercheBalise(fichier,"Nombre d'agents : ")){
            fscanf(fichier,"%d",&NbrElements);
            Simulation.a_NbrElements=NbrElements;
            Simulation = *AllocSimulation(&Simulation,(Simulation.a_NbrElements));
            char Nom[20];
            if (F_RechercheBalise(fichier,"Nom : ")){
                fgets(Nom,20,fichier);
                //char * NomDyn=NULL;
                //NomDyn =(char*)malloc(strlen(Nom)*sizeof(char));

                //strcpy(NomDyn,Nom);
//printf("yolo :%s",NomDyn);
                Simulation.a_tNom= (char*)malloc(sizeof(char)*strlen(Nom));

              //  Simulation.a_tNom = Nom;
              strcpy(Simulation.a_tNom,Nom);

            }

            if (F_RechercheBalise(fichier,"Mission | Agent | Cout \n")){
                int i;
                for (i=0;i<NbrElements;i++)
                {
                    fscanf(fichier," %d | %d | %lf\n",&(Simulation.a_tAttributions[i][0]),&(Simulation.a_tAttributions[i][1]),&(Simulation.a_tCouts[i]));
                    //printf(" %d | %d | %.2lf \n",Simulation.a_tAttributions[i][0],Simulation.a_tAttributions[i][1],Simulation.a_tCouts[i]);
                }
            }
        }
    }
    return Simulation;
}
