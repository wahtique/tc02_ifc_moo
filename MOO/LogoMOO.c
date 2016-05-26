#include <stdio.h>
#include <stdlib.h>
//#include <pdcurse>

void AfficherLogo()
{
    FILE *fichier=NULL;
    fichier = fopen("logo.txt","r");
    //int i
    while (!feof(fichier) && fichier!=NULL){
        char Ligne[20];
        fgets(Ligne,20,fichier);
        printf("%s",Ligne);
        //mvprintw(2,i,"%s",Ligne);
        //i++;
    }
    fclose(fichier);
}
