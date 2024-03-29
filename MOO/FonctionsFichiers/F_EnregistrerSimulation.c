#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../simulation.h"

int F_EnregistrerSimulation(simulation Simulation)
{
    FILE* fichier = NULL;
    char CheminFichier[60]="./Simulations/";
    strcat(CheminFichier,Simulation.a_tNom);
    strcat(CheminFichier,".g");
    //printf("Fichier : %s\n",CheminFichier);
    fichier = fopen(CheminFichier,"w+");

    if (fichier != NULL)
    {
        //printf("fichier ouvert");
        fprintf(fichier,"Nom : %s\n",Simulation.a_tNom);

        fprintf(fichier,"Nombre d'agents : %d\n\n",Simulation.a_NbrElements);

        fprintf(fichier,"Mission | Agent | Cout \n");
        int i;
        for (i=0;i<Simulation.a_NbrElements;i++)
        {
            fprintf(fichier," %d | %d | %.2f \n",Simulation.a_tAttributions[i][0],Simulation.a_tAttributions[i][1],Simulation.a_tCouts[i]);
        }
    }
    fclose(fichier);

}

