#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <panel.h>
#include <windows.h>
#include "Agent.h"
#include <string.h>

#include "Methode hongroise\runSimulation.h"
#include "simulation.h"
#include "LogoMOO.h"
#include "IHM.h"


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




int main()
{
    //Données

    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    Critere *TabCrits = NULL;
    int NbrCrits=0;
   // F_LoadTabCrits()
    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);

    //RechercherCrit(TabCrits);
    AfficherCritere(TabCrits,NbrCrits);


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

<<<<<<< .mine























=======

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

>>>>>>> .theirs

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

<<<<<<< .mine





=======

    return 0;
}

/*
>>>>>>> .theirs

int main() //Naej : Debut tableau de correspondance id /nom de critère{
    F_InitialiserDossiers();
    //simulation Simulation;
    //Simulation = (F_LoadSimulation("1"));
//    printf("\n%lu : %s\n",Simulation.a_ID,Simulation.a_tNom);
    //Simulation.a_tNom = "Test";
    printf("**** Project MOO **** \n Is the best project ever\n");
<<<<<<< .mine
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
=======











>>>>>>> .theirs
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
*/
    //F_EnregistrerSimulation(Simulation);
    //SuppSimulation(&Simulation,Simulation.a_NbrElements);
    return 0;
    }





<<<<<<< .mine


//principalement l'application de la methode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf
/*
int main() //Main de William
{
=======
    {






>>>>>>> .theirs
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
{
        purger(n, couts);
        etape1(n, couts);
        continuer = verifContinuer(n, couts);
        //printf("valeur de continuer : %d  \n", continuer);
        if(continuer == 1)
        {
            etape2(n, couts);
            etape3(n, couts);
        }



    }while(continuer == 1);


    //on affiche ce qu'il reste
            printf("out ! \n \n");
    for(i=0;i<5;i++)
    {

        for(j=0;j<5;j++)
        {
            printf("%f \t", couts[i][j].c);
        }

        printf("\n");

}

            printf("zeros encadres : \n ");
    for(i=0;i<n;i++)
    {

        for(j=0;j<5;j++)
{
            printf("%d \t", couts[i][j].encadre);
        }
        printf("\n");
    }

    return 0;
}
*/

*/

