#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Agent.h"
#include "MemManager.h"
#include <string.h>
#define DEBUT 0
#define FIN 1
#include <panel.h>
#include "Fichiers.h"



#include "Fichiers.h"

#include "Methode hongroise\runSimulation.h"
#include "simulation.h"





#include "Methode hongroise\runSimulation.h"
#include "simulation.h"
#include "LogoMOO.h"
#include "IHM.h"






int main() // main de Tri0b
{
    int n=5;
    n=n+1;
    int Tab[n];



    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    //SetAgent(Liste,11,1,"Robin",777);


    AjouterAgent0(Liste);
    AjouterAgentNP1(Liste);
    AjouterCritere(Liste);
    AjouterCritere(Liste);
    AjouterCritere(Liste);
    AjouterAgent0(Liste);
    AjouterAgentNP1(Liste);
    AjouterCritere(Liste);

    SaisieScore(Liste);
    AfficherCritereAgent(Liste);
    //printf("%f    %f",Liste->a_tScoreSchem[0][0],Liste->a_tScoreSchem[1][0]);
   // GetAgent(Liste,1);


    //D�salocation de Liste

    SupListe(Liste);


    return 0;
}


/* //INTERFACE GRAPHIQUE OK
=======
/*
>>>>>>> 5d7eb93917232212543d77962c5af73dade64550
int main()
{

    system("title Modus Operandi Optimum");
    system("Mode 180,60");
     WINDOW *Win=initscr();
    initscr();
    start_color(); //active le mode couleur
    raw(); //� mettre quand
    cbreak(); //ne lis pas "entr�e" Raw en moins nazi
    keypad(stdscr,TRUE);
    noecho(); //Pas d'entr�e clavier
    curs_set(0);// 0 invisible 1 visible 2 MOTHERFUCKER


    /*
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
}

<<<<<<< HEAD
*/
/*
=======


>>>>>>> 5d7eb93917232212543d77962c5af73dade64550
int main() //Main de Naej
{
    F_InitialiserDossiers();
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);



    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};
    //printf("%2.2f",NouvelAgent.a_Salaire);



   AjouterAgentNP1(Liste);

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
    printf("Nombre de crits : %lu\n",Liste->a_DimScore);
    AfficherListeAgent(Liste);
    F_EnregistrerAgent(*GetAgent(Liste,0),*Liste);

    F_SupprimerAgent(6);
    F_LoadAllAgents(Liste);
    AfficherListeAgent(Liste);
    printf("end\n");
    //DebugListe(Liste);
    SupListe(Liste);
    return 0;
}
*/

/*

//principalement l'appmication d ela méthode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf

int main() //Main de William
{
<<<<<<< HEAD

    //des agents et missions pour tester
    int n = 3, i;
=======
    int n = 3, i, j;
>>>>>>> 4ac559775227828a80fddc716c4f2db3059f3a71
    Agent agts[n];
    Mission m[n];

    float a[2][3] = {{1, 2, 3}, {90, 10, 10}};
    float b[2][3] = {{1, 2, 3}, {10, 90, 10}};
    float c[2][3] = {{1, 2, 3}, {10, 10, 90}};


    for(i=0;i<n;i++)
    {
        agts[i].a_ID = i;
        agts[i].a_Salaire = 10;

        m[i].a_ID = i;
        m[i].nb_crit = 3;
        m[i].a_duree = 10;

    }

    agts[0].a_tScore=&a;
    agts[1].a_tScore=&b;
    agts[2].a_tScore=&c;

    //l'agent médians

    Agent med;
    med.a_ID = 0;
    float sm[2][3] = {{1,2,3},{50,50,50}};
    med.a_tScore = sm;

    //les missions

    double p1[2][3]= {{1,2,3}, {0.5, 1, 0.5}};
    double p2[2][3]= {{1,2,3}, {0.5, 0.5, 1}};
    double p3[2][3]= {{1,2,3}, {1, 0.5, 0.5}};
    m[0].a_tPonderationsr=&p1;
    m[1].a_tPonderationsr=&p2;
    m[2].a_tPonderationsr=&p3;

    //on déclare la simulation

    simulation sim;

    sim.a_ID = 67;

    int att[2][n] = {{0, 0, 0}, {0, 0, 0}};

    sim.a_tAttributions = &att;

    runSimulation(n, sim, agts, m, med);

    return 0;
}

*/

