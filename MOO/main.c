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

    AjouterAgent0(Liste);
    AjouterAgentNP1(Liste);
    AjouterAgent0(Liste);

    AfficherListeAgent(Liste);

    SupListe(Liste);


    return 0;
}

*/

 //INTERFACE GRAPHIQUE OK



//INTERFACE GRAPHIQUE OK



/*
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

    wAfficherListeAgent(MyWins[LISTE_AGENT],4,2,ListeAgent);
    wAfficherCritere(MyWins[LISTE_CRITERE],4,2,TabCrits,NbrCrits);
    wAfficherListeMission(MyWins[LISTE_MISSIONS],4,2,ListeMission);
    wAfficherSimulation(MyWins[LISTE_SIMULATION],4,2);



    top_panel(MyPans[0]);


    MenuPrincipal(MyWins,MyPans,ListeAgent);

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
*/

/*
int main() //Naej : Debut tableau de correspondance id /nom de critère{
    F_InitialiserDossiers();
    //simulation Simulation;
    //Simulation = (F_LoadSimulation("1"));
//    printf("\n%lu : %s\n",Simulation.a_ID,Simulation.a_tNom);
    //Simulation.a_tNom = "Test";
    printf("**** Project MOO **** \n Is the best project ever\n");
    int NbrSimus=0;
    simulation *TabSimus;
    TabSimus = (F_LoadAllSimulations(TabSimus,&NbrSimus));
    printf("Nbr Simus %d",NbrSimus);
    int i;
    for (i=0;i<NbrSimus;i++)
    {
        printf("\n%lu : %s\n",(TabSimus[i].a_ID),(TabSimus[i].a_tNom));
        SuppSimulation(&TabSimus[i],TabSimus[i].a_ID);
    }
/*
    printf("Entrez l'id de la simulation :");
    scanf("%lu",&(Simulation.a_ID));
    printf("Entrez le nom de la simulation :");
    char Nom[25];
    scanf("%s",Nom);
    Simulation.a_tNom = Nom;
    printf("Entrez le nombre d'elements de la simulation :");
    scanf("%lu",&(Simulation.a_NbrElements));
    Simulation = *AllocSimulation(&Simulation,(Simulation.a_NbrElements));
    int i;
    for (i=0;i<Simulation.a_NbrElements;i++)
    {
        printf("Mission %d sur %lu:",i+1,Simulation.a_NbrElements);
        scanf("%lu",&(Simulation.a_tAttributions[i][0]));
        printf("Agent :");
        scanf("%lu",&(Simulation.a_tAttributions[i][1]));
        printf("Cout :");
        scanf("%lf",&(Simulation.a_tCouts[i]));
    //    printf("%f",(Simulation.a_tCouts[i]));

    }

    //F_EnregistrerSimulation(Simulation);
    //SuppSimulation(&Simulation,Simulation.a_NbrElements);
    return 0;
    }
*/






//principalement l'application de la methode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf




int main() //Main de William
{

    //POUR CREER UNE SIMULATION
    //simulation sim;
    //sim = *AllocSimulation(&sim, 5);


    int n = 3;
    F_InitialiserDossiers();

    //init agents
    FlagAgent *ListeA=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(ListeA);
    printf("agents initialises \n");

    //init missions
    FlagMission *ListeM=(FlagMission*)malloc(sizeof(FlagMission));
    InitFlagMission(ListeM);
    printf("mission initialises \n");

    Critere *TabCrits = NULL;
    int NbrCrits=0;

    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);
    printf("criteres charges \n");


    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};
    //printf("%2.2f",NouvelAgent.a_Salaire);
    //F_LoadAgent(ListeA,"1");
    F_LoadAllAgents(ListeA,NbrCrits);
    printf("agents charges \n");
    F_LoadAllMissions(ListeM,NbrCrits);
    printf("missions chargees \n");

    printf("affichage des agents \n");
    AfficherListeAgent(ListeA);
    printf("fin affichage agents \n");


    //int i;

    //creer une simulation

    simulation sim;
    sim = *AllocSimulation(& sim, n);
    sim.a_ID = 667;
    sim.a_tNom = "TEST";

    printf("simulation test ok \n");


    //listes d'agents et de missions

    Agent *taba = NULL;
    taba = (Agent*)malloc(sizeof(Agent)*n);
    taba[0]=*GetAgentByID(ListeA, 1);
    taba[1]=*GetAgentByID(ListeA, 12);
    taba[2]=*GetAgentByID(ListeA, 71);

    printf("taba ok \n");

    Mission *tabm = NULL;
    tabm = (Mission*)malloc(sizeof(Mission)*n);

    tabm[0]=*GetMission(ListeM, GetIndexMission(ListeM, 1));
    tabm[1]=*GetMission(ListeM, GetIndexMission(ListeM, 5));
    tabm[2]=*GetMission(ListeM, GetIndexMission(ListeM, 13));

    printf("tabm ok \n");


    Agent a;
    a = *GetAgentMedian(ListeA);

    printf("agent median ok \n");
    runSimulation(n, &sim, taba, tabm, a);

    //on affiche le résultat final
    int m;
    for(m = 0; m < n; ++m)
    {
        printf("%d \t %d \n", sim.a_tAttributions[m][0], sim.a_tAttributions[m][1]);
        printf("\n");
    }

    int succes[3] = {1,1,1};

    appliquersim(sim, ListeA, ListeM, succes);

    //F_SupprimerAgent(6);
    // F_LoadAllAgents(ListeA);
    //AfficherListeAgent(ListeA);
    //printf("end\n");
    //DebugListe(ListeA);
    SupListe(ListeA);
    SuppTabCrits(TabCrits,&NbrCrits);
    return 0;
    }




