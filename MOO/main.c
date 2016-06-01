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


int main() //Naej : Simulations
{
    F_InitialiserDossiers();
    simulation Simulation;


    printf("**** Project MOO **** \n Is the best project ever\n");

    printf("Entrez l'id de la simulation :");
    scanf("%lu",&(Simulation.a_ID));
    printf("Entrez le nom de la simulation :");
    char Nom[25];
    scanf("%s",Nom);
    Simulation.a_tNom = Nom;
    printf("Entrez le nombre d'elements de la simulation :");
    int Nbr;
    scanf("%lu",&Nbr);
    (Simulation.a_NbrElements)=Nbr;
    Simulation.a_tAttributions=NULL;
    Simulation.a_tAttributions=(int **)malloc(sizeof(int *)*Simulation.a_NbrElements*2);
    Simulation.a_tCouts = NULL;
    Simulation.a_tCouts = (double*)malloc(sizeof(double)*Simulation.a_NbrElements);
    int i;
    for (i=0;i<Simulation.a_NbrElements;i++)
    {
        Simulation.a_tAttributions[i]=(int *)malloc(sizeof(int)*2);
    }
    for (i=0;i<Simulation.a_NbrElements;i++)
    {
        printf("Mission %d sur %lu:",i+1,Simulation.a_NbrElements);
        scanf("%d",&(Simulation.a_tAttributions[i][0]));
        printf("Agent :");
        scanf("%d",&(Simulation.a_tAttributions[i][1]));
        printf("Cout :");

        scanf("%lf",&(Simulation.a_tCouts[i]));
    //    printf("%f",(Simulation.a_tCouts[i]));

    }
    F_EnregistrerSimulation(Simulation);
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

