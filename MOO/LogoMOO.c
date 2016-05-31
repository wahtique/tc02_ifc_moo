#include <curses.h>
#include <stdlib.h>


void AfficherAsciiArt(char Chemin[],int y,int x)
{
    FILE *fichier=NULL;
    fichier = fopen(Chemin,"r");
    if(fichier!=NULL)
    {
        while (!feof(fichier) && fichier!=NULL)
        {
            char Ligne[COLS];
            fgets(Ligne,COLS,fichier);


            mvprintw(y,x,"%s",Ligne);
            y++;
        }
        fclose(fichier);
    }

}
