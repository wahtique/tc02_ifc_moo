#include <curses.h>
#include <stdlib.h>


void AfficherLogo()
{
    FILE *fichier=NULL;
    fichier = fopen("logo.txt","r");
    int i=5;
    start_color();
    init_pair(2,COLOR_RED,COLOR_BLACK);
    attron(COLOR_PAIR(2));
    while (!feof(fichier) && fichier!=NULL)
    {
        char Ligne[20];
        fgets(Ligne,20,fichier);
       // printf("%s",Ligne);



        mvprintw(i,10,"%s",Ligne);
        i++;
    }
    attroff(COLOR_PAIR(2));
    fclose(fichier);
}
