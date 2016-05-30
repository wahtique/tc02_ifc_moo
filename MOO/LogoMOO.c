#include <curses.h>
#include <stdlib.h>


void AfficherAsciiArt(char Chemin[],int y,int x)
{
    FILE *fichier=NULL;
    fichier = fopen(Chemin,"r");
    while (!feof(fichier) && fichier!=NULL)
    {
        char Ligne[100];
        fgets(Ligne,100,fichier);
       // printf("%s",Ligne);



        mvprintw(y,x,"%s",Ligne);
        y++;
    }
    fclose(fichier);
}
