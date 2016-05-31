#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <panel.h>
#include <windows.h>
#include "Agent.h"
#include <string.h>
#include "Fichiers.h"
#include "Methode hongroise\runSimulation.h"
#include "simulation.h"
#include "LogoMOO.h"
#include "IHM.h"
#define DEBUT 0
#define FIN 1


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
    //D�salocation de Liste
    printf("%f",GetAgentMedian(Liste)->a_tScore[1][1]);

    SupListe(Liste);


    return 0;
}
*/
 //INTERFACE GRAPHIQUE OK



/* //INTERFACE GRAPHIQUE OK
*/


int main()
{
    system("title Modus Operandi Optimum");
    system("Mode Con COLS=180 LINES=60");

    WINDOW *Win=initscr();
    initscr();
    start_color(); //active le mode couleur
    raw(); //� mettre quand
    cbreak(); //ne lis pas "entr�e" Raw en moins nazi
    keypad(stdscr,TRUE);
    noecho(); //Pas d'entr�e clavier
    curs_set(0);// 0 invisible 1 visible 2 MOTHERFUCKER

    MenuPrincipal();

    getch();


    endwin();
    return 0;
}



/*

int main() //Naej : Debut tableau de correspondance id /nom de crit�re
{
    Critere *TabCrits = NULL;
    int NbrCrits=0;

    //Premier remplissage du tableau
    NbrCrits = 1;
    TabCrits = malloc(sizeof(Critere)*NbrCrits);
    if (TabCrits == NULL)
    {
        printf("VOUS AVEZ LA MEMOIRE PLEINE, EXECUTION IMPOSSIBLE");
        exit(1);
    }
    TabCrits[0].a_tNom = "test";
    TabCrits[0].a_ID =22;
    {
        int i;
        for (i=0;i<NbrCrits;i++)
        {
            printf("%lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
        }
    }



        //Ajout de crit�re
    NbrCrits++;
    printf("crits : %d\n",NbrCrits);
    Critere *TempTab = NULL;
    TempTab = malloc(sizeof(Critere)*NbrCrits);
    if (TempTab == NULL)
    {
        printf("VOUS AVEZ LA MEMOIRE PLEINE, EXECUTION IMPOSSIBLE");
        exit(1);
    }
    TempTab[NbrCrits-1].a_ID = 3;
    TempTab[NbrCrits-1].a_tNom = "lol";
    TempTab[0]=TabCrits[0];

    {
        int i;
        for (i=0;i<NbrCrits;i++)
        {
            printf("%lu : %s\n",TempTab[i].a_ID,TempTab[i].a_tNom);
        }
    }
    free(TabCrits);
    TabCrits = TempTab;

    NbrCrits++;
    AjoutCritRef(TabCrits,NbrCrits,50,"totaulogie");
    {
        int i;
        for (i=0;i<NbrCrits;i++)
        {
            printf("%lu : %s\n",TabCrits[i].a_ID,TabCrits[i].a_tNom);
        }
    }
    free(TabCrits);
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
<<<<<<< HEAD


    //des agents et missions pour tester
    int n = 3, i;

    int n = 3, i, j;

=======

>>>>>>> 92530dbe478de2bb8feb36f7f21cdb325b27c391
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

    //on declare la simulation

    simulation sim;

    sim.a_ID = 67;

    int att[2][n] = {{0, 0, 0}, {0, 0, 0}};

    sim.a_tAttributions = &att;

    runSimulation(n, sim, agts, m, med);

    return 0;
}

*/

