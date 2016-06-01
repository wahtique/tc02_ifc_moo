#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <panel.h>
#include <windows.h>
#include "Agent.h"
#include <string.h>
#define DEBUT 0
#define FIN 1
#include "Methode hongroise\runSimulation.h"
#include "simulation.h"
#include "LogoMOO.h"
#include "IHM.h"
#include "Fichiers.h"


/*
int main() // main de Tri0b
{
    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    //SetAgent(Liste,11,1,"Robin",777);


    AjouterAgent0(Liste);
    AjouterAgentNP1(Liste);
    AjouterCritere(Liste);
    AjouterCritere(Liste);
    AjouterAgentNP1(Liste);
    //AjouterAgent0(Liste);
    //SaisieScore(Liste);

    //printf("%f    %f",Liste->a_tScoreSchem[0][0],Liste->a_tScoreSchem[1][0]);
   // GetAgent(Liste,1);
    SaisieScore(Liste);
    //AfficherCritereAgent(Liste);

    ClasserAgent(Liste,1);
    //AfficherCritereAgent(Liste);
    //Désalocation de Liste
    printf("%f",GetAgentMedian(Liste)->a_tScore[1][1]);

    //Désalocation de Liste
/*
    AjouterAgent0(Liste);
    AjouterAgentNP1(Liste);
    AjouterAgent0(Liste);

    AfficherListeAgent(Liste);

    SupListe(Liste);


    return 0;
}
<<<<<<< HEAD
*/
 //INTERFACE GRAPHIQUE OK



//INTERFACE GRAPHIQUE OK



/*
int main()
{
    system("title Modus Operandi Optimum");
    system("cd C:/");
    system("cd");
    getch();
    //system("Mode Con COLS=180 LINES=60");

    WINDOW *Win=initscr();
    initscr();
    start_color(); //active le mode couleur
    raw(); //à mettre quand
    cbreak(); //ne lis pas "entrée" Raw en moins nazi
    keypad(stdscr,TRUE);
    noecho(); //Pas d'entrée clavier
    curs_set(0);// 0 invisible 1 visible 2 MOTHERFUCKER





    short *COLOR_LEL; //FAUT METTRE UN POINTEUR PARCEQUE SINON LEL
    init_color(COLOR_LEL,50,71,20);
    init_pair(1,COLOR_LEL,COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("Hi !!");
    attroff(COLOR_PAIR(1));

    MenuPrincipal();

    getch();


    endwin();
   return 0;
}*/


int main() //Naej : Missions
{
    F_InitialiserDossiers();
    FlagMission *Liste=(FlagMission*)malloc(sizeof(FlagMission));
    InitFlagMission(Liste);

    Critere *TabCrits = NULL;
    int NbrCrits=0;

    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);



    printf("**** Project MOO **** \n Is the best project ever\n");
  //    AjouterCritereM(Liste);
//    AjouterCritereM(Liste);
     F_LoadAllMissions(Liste,NbrCrits);
    printf("lol");

/*
   AjouterMission0(Liste);

    printf("Entrez l'id de la mission :");
     long unsigned int ID;
    scanf("%lu",&ID);
    printf("Entrez le nom de la mission :");
    char Nom[25];
    scanf("%s",Nom);
    printf("Entrez la duree de la mission :");
    float duree;
    scanf("%f",&duree);
    SetMission(Liste,0,ID,Nom,duree);
    AjouterCritereM(Liste);
    AjouterCritereM(Liste);
    AfficherCritereMission(Liste);
   /* printf("Nombre de crits : %lu\n",Liste->a_DimScore);
    AfficherListeMission(Liste);
 */ // F_EnregistrerMission(*GetMission(Liste,0),*Liste);

    //F_SupprimerAgent(6);
   // F_LoadAllAgents(Liste);
    //AfficherListeAgent(Liste);
    printf("end\n");
    //DebugListe(Liste);

    AfficherListeMission(Liste);

    SuppTabCrits(TabCrits,&NbrCrits);
    SupListeM(Liste);
    return 0;
}





/*

//principalement l'appmication de la methode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf

int main() //Main de William
{

    return 0;
}

*/

