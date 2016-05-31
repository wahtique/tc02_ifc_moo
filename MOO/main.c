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
#include "Methode hongroise\runSimulation.h"
#include "simulation.h"
#include "LogoMOO.h"
#include "IHM.h"
/*
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

    //SaisieScore(Liste);
    AfficherCritereAgent(Liste);
    //printf("%f    %f",Liste->a_tScoreSchem[0][0],Liste->a_tScoreSchem[1][0]);
   // GetAgent(Liste,1);


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





int main()
{

    system("title Modus Operandi Optimum");
    system("Mode Con COLS=180 LINES=60");
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
}

/*
int main() //Naej : Debut tableau de correspondance id /nom de critère
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

/*
        //Ajout de critère
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

