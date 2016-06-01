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
    //D�salocation de Liste
    printf("%f",GetAgentMedian(Liste)->a_tScore[1][1]);

    //D�salocation de Liste
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
    raw(); //� mettre quand
    cbreak(); //ne lis pas "entr�e" Raw en moins nazi
    keypad(stdscr,TRUE);
    noecho(); //Pas d'entr�e clavier
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
int main() //Naej : Debut tableau de correspondance id /nom de crit�re
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


//principalement l'application de la methode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf

int main() //Main de William
{
    double harcode[5][5] = {{17, 15, 9, 5, 12},
                            {16, 16, 10, 5, 10},
                            {12, 15, 14, 11, 5},
                            {4, 8, 14, 17, 13},
                            {13, 9, 8, 12, 17}};

    Cout couts[5][5];
    //Cout couts0[5][5];
    int i, j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            couts[i][j].c = harcode[i][j];
            couts[i][j].barre = 0;
            couts[i][j].encadre = 0;
            couts[i][j].trait = 0;
            //couts0[i][j].c = harcode[i][j];
            printf("%f \t", couts[i][j].c);
        }

        printf("\n");
    }
    int n = 5, continuer = 1;
    etape0(n, couts);
    printf("tableau r�duit : \n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%f \t", couts[i][j].c);
        }

        printf("\n");
    }

    do
    {
        purger(n, couts);
        printf("\n on commence etape 1");
        etape1(n, couts);
        continuer = verifContinuer(n, couts);
        printf("valeur de continuer : %d  \n", continuer);
        if(continuer == 1)
        {
            etape2(n, couts);
            etape3(n, couts);
        }

    }while(continuer == 1);

    //on affiche ce qu'il reste
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%f \t", couts[i][j].c);
        }

        printf("\n");
    }

    return 0;
}


