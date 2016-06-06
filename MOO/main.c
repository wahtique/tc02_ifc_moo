#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <panel.h>
#include <windows.h>
#include "Agent.h"
#include "Critere.h"
#include "Mission.h"
#include "simulation.h"
#include <string.h>
#include "Fichiers.h"
#include "simulation.h"
#include "Mission.h"
#include "Critere.h"
#include "Methode hongroise\runSimulation.h"
#include "LogoMOO.h"
#include "IHM.h"
#include "Appliquer simulation\appliquersim.h"


#define MENU_PRINCIPAL 0

#define GERER_DONNEES 1
#define EFFECUTER_SIMULATION 2

#define LISTE_AGENT 3
#define LISTE_CRITERE 4
#define LISTE_MISSIONS 5
#define LISTE_SIMULATION 6

#define FONCTION_AGENT 7
#define FONCTION_CRITERE 8
#define FONCTION_MISSIONS 9
#define FONCTION_SIMULATION 10

#define RECHERCHER_AGENT 11
#define AJOUTER_AGENT 12
#define AJOUTER_MISSION 13

int main()
{


    //Données
    F_InitialiserDossiers();
    FlagAgent *ListeAgent=(FlagAgent*)malloc(sizeof(FlagAgent));

    FlagMission *ListeMission=(FlagMission*)malloc(sizeof(FlagMission));

    InitFlagAgent(ListeAgent);
    InitFlagMission(ListeMission);

    Critere *TabCrits = NULL;
    int NbrCrits=0;

    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);


    F_LoadAllAgents(ListeAgent,NbrCrits);



    F_LoadAllMissions(ListeMission,NbrCrits);

    //AfficherCritere(TabCrits,NbrCrits);
    //RechercherCrit(TabCrits);
    //AfficherCritere(TabCrits,NbrCrits);

    //INITIALISATION

    system("title Modus Operandi Optimum");
    system("Mode Con COLS=180 LINES=60");

    initscr();

    start_color(); //active le mode couleur
    raw(); //à mettre quand
    cbreak(); //ne lis pas "entrée" Raw en moins nazi
    keypad(stdscr,TRUE);
    noecho(); //Pas d'entrée clavier
    curs_set(0);// 0 invisible 1 visible 2 MOTHERFUCKER

//Déclaration des fenêtres et pannels
    WINDOW *MyWins[20];
    WINDOW *MyPans[20];

    int i=0;
    for(i=0;i<3;i++)
    {
        MyWins[i]=newwin(0,0,0,0);
        MyPans[i]=new_panel(MyWins[i]);
    }
    for(i=3;i<7;i++) // Affichages des listes
    {
        MyWins[i]=newwin(LINES-5,COLS/3,5,0);
        MyPans[i]=new_panel(MyWins[i]);
        box(MyWins[i],0,0);
    }
    for(i=7;i<11;i++)
    {
        MyWins[i]=newwin(LINES-5,COLS/3,5,COLS-COLS/3);
        MyPans[i]=new_panel(MyWins[i]);
        box(MyWins[i],0,0);
    }

    MyWins[RECHERCHER_AGENT]=newwin(LINES-5,COLS/3,5,2*COLS/3);
    MyPans[RECHERCHER_AGENT]=new_panel(MyWins[RECHERCHER_AGENT]);

    MyWins[AJOUTER_AGENT]=newwin(LINES-5,2*COLS/3,5,COLS/3);
    MyPans[AJOUTER_AGENT]=new_panel(MyWins[AJOUTER_AGENT]);


    MyWins[AJOUTER_MISSION]=newwin(LINES-5,2*COLS/3,5,COLS/3);
    MyPans[AJOUTER_MISSION]=new_panel(MyWins[AJOUTER_MISSION]);


    mvwprintw(MyWins[3],2,2,"Liste d'agents:");
    mvwprintw(MyWins[4],2,2,"Liste de critères:");
    mvwprintw(MyWins[5],2,2,"Liste de missions:");
    mvwprintw(MyWins[6],2,2,"Liste de simulations:");

    mvwprintw(MyWins[7],2,2,"Rechercher Agent\n  Ajouter Agent\n  Modifier un Agent\n  Supprimer un Agent\n  Retour");
    mvwprintw(MyWins[8],2,2,"Ajouter un critère\n  Supprimer un critère\n  Modifier un critère\n  Retour");
    mvwprintw(MyWins[9],2,2,"Rechercher Mission\n  Ajouter Mission\n  Modifier une Mission\n  Supprimer une Mission\n  Retour");
    mvwprintw(MyWins[10],2,2,"Disponible prochainement");

    wAfficherListeAgent(MyWins[LISTE_AGENT],4,2,ListeAgent);
    wAfficherCritere(MyWins[LISTE_CRITERE],4,2,TabCrits,NbrCrits);
    wAfficherListeMission(MyWins[LISTE_MISSIONS],4,2,ListeMission);
    wAfficherSimulation(MyWins[LISTE_SIMULATION],4,2);



    top_panel(MyPans[0]);


    MenuPrincipal(MyWins,MyPans,ListeAgent,ListeMission);

    //clearok(Win,TRUE);
    //wrefresh(Win);
    clear();
    refresh();

    endwin();



    SupListe(ListeAgent);

    SupListeM(ListeMission);

    SuppTabCrits(TabCrits,&NbrCrits);





    return 0;

}

