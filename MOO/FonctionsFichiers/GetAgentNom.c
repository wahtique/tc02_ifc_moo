#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

int F_GetAgentNom(int ID)
{
    FILE* fichier = NULL;
    char NomFichier[25]="./Agent/",strID[10];
    itoa(ID,strID,10);
    strcat(NomFichier,strID);
    strcat(NomFichier,".g");
    fichier = fopen(NomFichier,"r");


    //fscanf(fichier,"ID : %d",&ID);
    //int stock;
    //while (fgetc(fichier) != '\n');
    //char Balise[10]="Nom : ";
    //fscanf(fichier,Balise);
    F_RechercheBalise(fichier,"Nom :");

    char NomAgent[25];
    fgets(NomAgent,25,fichier);
    printf("%s",NomAgent);
    fclose(fichier);
}
