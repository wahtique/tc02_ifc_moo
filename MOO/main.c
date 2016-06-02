#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <panel.h>
#include <windows.h>
#include "Agent.h"
#include <string.h>
#include "Critere.h"

#include "Fichiers.h"
#include "Methode hongroise\runSimulation.h"
#include "simulation.h"
#include "LogoMOO.h"
#include "IHM.h"
#define DEBUT 0
#define FIN 1


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

<<<<<<< HEAD
    ClasserAgent(Liste,1);
    //AfficherCritereAgent(Liste);
    //Désalocation de Liste
    printf("%f",GetAgentMedian(Liste)->a_tScore[1][1]);
=======

    //Désalocation de Liste
/*
    AjouterAgent0(Liste);
    AjouterAgentNP1(Liste);
    AjouterAgent0(Liste);

    AfficherListeAgent(Liste);
>>>>>>> e2883b47c2c29d2b29049c2b771823c8f524380d

    SupListe(Liste);


    return 0;
}
<<<<<<< HEAD
*/

 //INTERFACE GRAPHIQUE OK



//INTERFACE GRAPHIQUE OK




int main()
{
    //Données

    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    Critere *TabCrits = NULL;
    int NbrCrits=0;
   // F_LoadTabCrits()
    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);

    //RechercherCrit();
    AfficherCritere(TabCrits,NbrCrits);
    /*

    AjouterNAgent0(Liste,4);
    SetAgent(Liste,0,51,"Robin",10000);
    SetAgent(Liste,1,151,"Willy",10000);
    SetAgent(Liste,2,42,"Naej",10000);
    AjouterCritere(Liste);
    AjouterCritere(Liste);

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

    WINDOW *MyWins[12];
    WINDOW *MyPans[12];


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

    MyWins[RECHERCHER_AGENT]=newwin(LINES-5,2*COLS/3,5,COLS/3);
    MyPans[RECHERCHER_AGENT]=new_panel(MyWins[RECHERCHER_AGENT]);


    mvwprintw(MyWins[3],2,2,"Liste d'agents:");
    mvwprintw(MyWins[4],2,2,"Liste de critères:");
    mvwprintw(MyWins[5],2,2,"Liste de missions:");
    mvwprintw(MyWins[6],2,2,"Liste de simulations:");

    mvwprintw(MyWins[7],2,2,"Rechercher Agent\n  Ajouter Agent\n  Modifier un Agent\n  Supprimer un Agent\n  Retour");
    mvwprintw(MyWins[8],2,2,"Ajouter un critère\n  Supprimer un critère\n  Modifier un critère\n  Retour");
    mvwprintw(MyWins[9],2,2,"Rechercher Mission\n  Ajouter Mission\n  Modifier une Mission\n  Supprimer une Mission\n  Retour");
    mvwprintw(MyWins[10],2,2,"???");

    wAfficherListeAgent(MyWins[3],4,2,Liste);
    wAfficherCritereAgent(MyWins[4],4,2,Liste);





    top_panel(MyPans[0]);



    MenuPrincipal(MyWins,MyPans,Liste);

    //clearok(Win,TRUE);
    //wrefresh(Win);
    clear();
    refresh();

    endwin();
    */
    return 0;
}



/*
int main() //Naej : Debut tableau de correspondance id /nom de critère
{
    Critere *TabCrits = NULL;
    int NbrCrits=0;
    char Nom[10];
    printf("%p\n",TabCrits);
    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);
    printf("%p    %d\n",TabCrits,NbrCrits);
/*
    //Premier remplissage du tableau
    NbrCrits = 1;
    TabCrits = (Critere*)malloc(sizeof(Critere)*NbrCrits);
    if (TabCrits == NULL)
    {
        printf("VOUS AVEZ LA MEMOIRE PLEINE, EXECUTION IMPOSSIBLE");
        exit(1);
    }
    TabCrits[0].a_tNom = "test";
    TabCrits[0].a_ID =22;
  */  /*int i;
    for (i=0;i<NbrCrits;i++)
    {
        printf("%lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
    }


<<<<<<< HEAD

        //Ajout de critère
    NbrCrits++;
    printf("crits : %d\n",NbrCrits);
    Critere *TempTab = NULL;
    TempTab = malloc(sizeof(Critere)*NbrCrits);
    if (TempTab == NULL)
=======
   // TabCrits = AjoutCritRef(TabCrits,&NbrCrits,50,"totaulogie");
    for (i=0;i<NbrCrits;i++)
>>>>>>> e2883b47c2c29d2b29049c2b771823c8f524380d
    {
        printf("%lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
    }
   TabCrits = SupprimerCritRef(TabCrits,&NbrCrits,22);
    for (i=0;i<NbrCrits;i++)
    {
        printf("%lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
    }
<<<<<<< HEAD
    free(TabCrits);
    TabCrits = TempTab;

    NbrCrits++;
    AjoutCritRef(TabCrits,NbrCrits,50,"totaulogie");
=======
    F_EnregistrerTabCrits(TabCrits,&NbrCrits);




    int i;
    for (i=0;i<NbrCrits;i++)

    {
        printf("%lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
    }
    free(TabCrits);
    return 0;
}

*/
/*
int main() //Main de Naej
{
    F_InitialiserDossiers();
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);



    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};
    //printf("%2.2f",NouvelAgent.a_Salaire);



   AjouterAgent0(Liste);

    printf("Entrez l'id de l'agent :");
     long unsigned int ID;
    scanf("%lu",&ID);
    printf("Entrez le nom de l'agent :");
    char Nom[25];
    scanf("%s",Nom);
    printf("Entrez le salaire de l'agent :");
    float salaire;
    scanf("%f",&salaire);
    SetAgent(Liste,0,ID,Nom,salaire);
    AjouterCritere(Liste);
    AjouterCritere(Liste);
    AfficherCritereAgent(Liste);
    printf("Nombre de crits : %lu\n",Liste->a_DimScore);
    AfficherListeAgent(Liste);
    F_EnregistrerAgent(*GetAgent(Liste,0),*Liste);

    //F_SupprimerAgent(6);
   // F_LoadAllAgents(Liste);
    //AfficherListeAgent(Liste);
    printf("end\n");
    //DebugListe(Liste);
    SupListe(Liste);
    return 0;
}
*/
/*

//principalement l'appmication de la methode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf

int main() //Main de William
{

    return 0;
}

*/

