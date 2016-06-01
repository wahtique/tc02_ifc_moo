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


int main() //Naej : Debut tableau de correspondance id /nom de critère
{
    Critere *TabCrits = NULL;
    int NbrCrits=0;

    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);

    printf("NbrCrits : %d\n",NbrCrits);
    int i;
    for (i=0;i<NbrCrits;i++)
    {
        printf("%lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
    }

    TabCrits = AjoutCritRef(TabCrits,&NbrCrits,60,"THE FORCE");
    for (i=0;i<NbrCrits;i++)
    {
        printf("Apres ajout : %lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
    }
    TabCrits = SupprimerCritRef(TabCrits,&NbrCrits,60);

    for (i=0;i<NbrCrits;i++)
    {
        printf("Apres suppr : %lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
    }
    F_EnregistrerTabCrits(TabCrits,&NbrCrits);



    SuppTabCrits(TabCrits,&NbrCrits);
    return 0;
}


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

