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
#include "Mission.h"
//des includes pour debugguer, a supprimet plus tard
#include "Methode hongroise\cout.h"
#include "Methode hongroise\purger.h"
#include "Methode hongroise\verifContinuer.h"
#include "Methode hongroise\etape0.h"
#include "Methode hongroise\etape1.h"
#include "Methode hongroise\etape2.h"
#include "Methode hongroise\etape3.h"

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

/*
int main() //Naej : Simulations
{
    F_InitialiserDossiers();
    simulation Simulation;
    Simulation = (F_LoadSimulation("1"));
    Simulation.a_tNom = "Test";
    printf("**** Project MOO **** \n Is the best project ever\n");
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

    F_EnregistrerSimulation(Simulation);
    SuppSimulation(&Simulation,Simulation.a_NbrElements);
    return 0;
}

*/





//principalement l'application de la methode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf

int main() //Main de William
{

/*    //POUR CREER UNE SIMULATION
    simulation sim;
    sim = *AllocSimulation(&sim, 5);*/
    int n = 3;
    F_InitialiserDossiers();

    //init agents
    FlagAgent *ListeA=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(ListeA);

    //init missions
    FlagMission *ListeM=(FlagMission*)malloc(sizeof(FlagMission));
    InitFlagMission(ListeM);

    Critere *TabCrits = NULL;
    int NbrCrits=0;

    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);


    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};
    //printf("%2.2f",NouvelAgent.a_Salaire);
    //F_LoadAgent(ListeA,"1");
    F_LoadAllAgents(ListeA,NbrCrits);
    F_LoadAllMissions(ListeM,NbrCrits);

    printf("\n avant afficher liste agent \n");

    AfficherListeAgent(ListeA);
    int i;

    //creer une simulation

    simulation sim;
    sim = *AllocSimulation(& sim, n);
    sim.a_ID = 667;
    sim.a_tNom = "TEST";

    Mission truc;


    //listes d'agents et de missions

    Agent *taba = NULL;
    taba = (Agent*)malloc(sizeof(Agent)*n);
    taba[0]=*GetAgentByID(ListeA, 1);
    taba[1]=*GetAgentByID(ListeA, 12);
    taba[2]=*GetAgentByID(ListeA, 71);



    Mission *tabm = NULL;
    tabm = (Mission*)malloc(sizeof(Mission)*n);

    tabm[0]=*GetMission(ListeM, GetIndexMission(ListeM, 1));
    tabm[1]=*GetMission(ListeM, GetIndexMission(ListeM, 5));
    tabm[2]=*GetMission(ListeM, GetIndexMission(ListeM, 13));


    Agent a;
    a = *GetAgentMedian(ListeA);
/*    int index = GetIndexAgent(ListeA, 20);

    printf("test get by id : %d", index);*/

    runSimulation(n, &sim, taba, tabm, a);

    //on affiche le résultat final
    int m;
    for(m = 0; m < n; ++m)
    {
        printf("%d \t %d \n", sim.a_tAttributions[m][0], sim.a_tAttributions[m][1]);
    }
    /*
    for (i=0;i<ListeA->a_Taille;i++)
    {
        F_EnregistrerAgent(*GetAgent(ListeA,i),*ListeA);
    }*/
    //F_SupprimerAgent(6);
    // F_LoadAllAgents(ListeA);
    //AfficherListeAgent(ListeA);
    //printf("end\n");
    //DebugListe(ListeA);
    SupListe(ListeA);
    SuppTabCrits(TabCrits,&NbrCrits);


    return 0;
}



