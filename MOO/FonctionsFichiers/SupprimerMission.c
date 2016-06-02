#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F_SupprimerMission(unsigned long int ID)
{
    char strID[10];
    itoa(ID,strID,10);
    char NomFichier[20] = "./Mission/";
    strcat(NomFichier,strID);
    strcat(NomFichier,".g");
    remove(NomFichier);
}
