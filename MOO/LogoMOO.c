#include <stdio.h>
#include <stdlib.h>
//#include <pdcurse>

void AfficherLogo()
{
    FILE *fichier=NULL;
    fichier = fopen("logo.txt","r");
    while (!feof(fichier) && fichier!=NULL){
        char Ligne[20];
        fgets(Ligne,20,fichier);
        printf("%s",Ligne);
        //mvprintw(2,2,"%s",Ligne);
    }
    fclose(fichier);
}
