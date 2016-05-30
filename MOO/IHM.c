#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <panel.h>
#include <windows.h>

#include "LogoMOO.h"
#define MAXLINES 60
#define MAXCOLS 180
void AfficherCentrer(int y,int x,const char*Txt)
{
    if((x-(int)strlen(Txt)/2)>=0&&x+(int)strlen(Txt)/2<=COLS)
    {
        mvprintw(y,x-strlen(Txt)/2,Txt);
    }
    else if((x-(int)strlen(Txt)/2)<0)
    {
        mvprintw(y,0,Txt);
    }
    else if((x+(int)strlen(Txt)/2)>COLS)
    {
        mvprintw(y,COLS-(int)strlen(Txt),Txt);
    }

}



void AfficherCadre()
{
    int i=0,j=0;
    for(i=0;i<=LINES;i++)
    {
        mvprintw(i,0,"|");
        mvprintw(i,COLS-1,"|");
    }
    for(j=0;j<=180;j++)
    {
        mvprintw(0,j,"-");
        mvprintw(LINES-1,j,"-");
    }
}



void MenuPrincipal()
{


    int Key=0;
    int Curseur=0;
    do
    {
    AfficherAsciiArt("logo.txt",2,2);
    AfficherCadre();
    AfficherCentrer(2*LINES/3,COLS/2,"Gérer les données");
    AfficherCentrer(2*LINES/3+1,COLS/2,"Éffectuer une simulation");
    AfficherCentrer(2*LINES/3+2,COLS/2,"Quitter");



    switch(Curseur)
    {
    case 0:
        init_pair(1,COLOR_BLACK,COLOR_WHITE);
        attron(COLOR_PAIR(1));
        AfficherCentrer(2*LINES/3,COLS/2,"Gérer les données");
        attroff(COLOR_PAIR(1));
        break;
    case 1:
        init_pair(1,COLOR_BLACK,COLOR_WHITE);
        attron(COLOR_PAIR(1));
        AfficherCentrer(2*LINES/3+1,COLS/2,"Éffectuer une simulation");
        attroff(COLOR_PAIR(1));
        break;
    case 2:
        init_pair(1,COLOR_BLACK,COLOR_WHITE);
        attron(COLOR_PAIR(1));
        AfficherCentrer(2*LINES/3+2,COLS/2,"Quitter");
        attroff(COLOR_PAIR(1));
        break;
    }
    Key=getch();
    if(Key==KEY_UP)
    {
        Curseur--;
        Curseur =(Curseur+3)%3;
    }
    if(Key==KEY_DOWN)
    {
        Curseur++;
        Curseur=(Curseur+3)%3;
    }
    //printf("%u   %u\n",Curseur,SelectionVerticale(&Curseur,3));
    refresh();
    }while(Key!=13);


}


void InitWindow()
{
    initscr();
    system("title Modus Operandi Optimum");
    system("Mode Con COLS=180 LINES=60");

}
