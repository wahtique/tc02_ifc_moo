#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <panel.h>
#include <wchar.h>
#include "IHM.h"
#include <windows.h>
#include "Agent.h"
#include "LogoMOO.h"
#include <string.h>
#include "simulation.h"
#include "Fichiers.h"
#include "Appliquer simulation/appliquersim.h"



#include "Methode hongroise/purger.h"
#include "Methode hongroise/verifContinuer.h"
#include "Methode hongroise/etape0.h"
#include "Methode hongroise/etape1.h"
#include "Methode hongroise/etape2.h"
#include "Methode hongroise/etape3.h"
#include "Methode hongroise/creer_matrice_couts.h"



#define MAXLINES 60
#define MAXCOLS 180


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
#define AJOUTER_AGENT 12
#define AJOUTER_MISSION 13
#define SUPPRIMER_AGENT 14
#define MODIFIER_AGENT 15
#define SUPPRIMER_MISSION 16
#define RESULTAT_SIMULATION 17

void AfficherCentrer(WINDOW *Win,int y,int x,const char*Txt)
{
    if((x-(int)strlen(Txt)/2)>=0&&x+(int)strlen(Txt)/2<=COLS)
    {
        mvwprintw(Win,y,x-strlen(Txt)/2,Txt);
    }
    else if((x-(int)strlen(Txt)/2)<0)
    {
        mvwprintw(Win,y,0,Txt);
    }
    else if((x+(int)strlen(Txt)/2)>COLS)
    {
        mvwprintw(Win,y,COLS-(int)strlen(Txt),Txt);
    }

}



void AfficherCadre()
{
    int i=0,j=0;
    for(i=0;i<=LINES;i++)
    {
        mvprintw(i,0,"|");
        mvprintw(i,COLS-1,"|");
    }
    for(j=0;j<=180;j++)
    {
        mvprintw(0,j,"-");
        mvprintw(LINES-1,j,"-");
    }
}



void MenuPrincipal(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste,FlagMission *ListeM)
{
    int Key=0;
    int Curseur=0;
    int Reponse=0;
    char Saisie[30];



    Agent *AgentSimu=NULL;;
    Mission *MissionSimu=NULL;
    Agent Median;



    simulation MaSimulation;
    int NombreSimu=0;

    do
    {
        init_pair(3,COLOR_RED,COLOR_BLACK);
        wattron(Tab[0],A_BOLD);
        wattron(Tab[0],COLOR_PAIR(3));
        AfficherAsciiArt(Tab[0],"MOOTEXTE.txt",20,37);
        wattroff(Tab[0],COLOR_PAIR(3));
        wattroff(Tab[0],A_BOLD);

        AfficherAsciiArt(Tab[0],"MOOTEXTE2.txt",20,48);
        init_pair(4,COLOR_BLUE,COLOR_BLACK);
        wattron(Tab[0],A_BOLD);
        wattron(Tab[0],COLOR_PAIR(4));
        AfficherAsciiArt(Tab[0],"VacheRealiste.txt",2,COLS-COLS/3);
        wattroff(Tab[0],COLOR_PAIR(4));

        AfficherCadre();
        AfficherCentrer(Tab[0],2*LINES/3,COLS/2,"Gérer les données");
        AfficherCentrer(Tab[0],2*LINES/3+1,COLS/2,"Effectuer une simulation");
        AfficherCentrer(Tab[0],2*LINES/3+2,COLS/2,"Quitter");
        wattroff(Tab[0],A_BOLD);


        switch(Curseur)
        {
        case 0:

            init_pair(1,COLOR_BLACK,COLOR_WHITE);
            wattron(Tab[0],COLOR_PAIR(1));
            AfficherCentrer(Tab[0],2*LINES/3,COLS/2,"Gérer les données");
            wattroff(Tab[0],COLOR_PAIR(1));
            break;
        case 1:
            init_pair(1,COLOR_BLACK,COLOR_WHITE);
            wattron(Tab[0],COLOR_PAIR(1));
            AfficherCentrer(Tab[0],2*LINES/3+1,COLS/2,"Effectuer une simulation");
            wattroff(Tab[0],COLOR_PAIR(1));
            break;
        case 2:
            init_pair(1,COLOR_BLACK,COLOR_WHITE);
            wattron(Tab[0],COLOR_PAIR(1));
            AfficherCentrer(Tab[0],2*LINES/3+2,COLS/2,"Quitter");
            wattroff(Tab[0],COLOR_PAIR(1));
            break;
        }

        if((Key==13||Key==459)&&Curseur==0)
        {
            GererDonne(Tab,Pan,Liste,ListeM);
        }

        if((Key==13||Key==459)&&Curseur==1)
        {
            echo();
            curs_set(1);
            wrefresh(Tab[EFFECUTER_SIMULATION]);

            top_panel(Pan[EFFECUTER_SIMULATION]);
            wmove(Tab[EFFECUTER_SIMULATION],0,0);
            wprintw(Tab[EFFECUTER_SIMULATION],"Selection des parametres pour une simulation : \n");
            wprintw(Tab[EFFECUTER_SIMULATION],"Combien de missions de voulez vous effectuer ? (Nombre de missions = Nombre d'agents)\n");
            wrefresh(Tab[EFFECUTER_SIMULATION]);
            wscanw(Tab[EFFECUTER_SIMULATION],"%d",&NombreSimu);

            //tableau d'agents pour la simulation
            AgentSimu=(Agent*)malloc(sizeof(Agent)*NombreSimu);
            int ida, unique, q, c;

            for(c = 0; c<NombreSimu;c++)
            {
                wprintw(Tab[EFFECUTER_SIMULATION],"ID de l'agent n %d :\n", c + 1);
                wscanw(Tab[EFFECUTER_SIMULATION],"%d",&ida);
                AgentSimu[c] = *GetAgentByID(Liste, ida);
            }

            //tableau de missions pour la simulation
            MissionSimu=(Mission*)malloc(NombreSimu*sizeof(Mission));
            int idm, indexm;

            for(c = 0; c<NombreSimu ; c++)
            {
                wprintw(Tab[EFFECUTER_SIMULATION],"ID de la mission n %d :\n", c + 1);


                wscanw(Tab[EFFECUTER_SIMULATION],"%d",&idm);
                indexm = GetIndexMission(ListeM, idm);
                MissionSimu[c] = *GetMission(ListeM, indexm);

            }


            //initialisation de la simulation
            MaSimulation=*AllocSimulation(&MaSimulation,NombreSimu);

            //on crée l'agent median
            Median=*(GetAgentMedian(Liste));

            runSimulation(NombreSimu,&MaSimulation,AgentSimu,MissionSimu,Median);
            wclear(Tab[EFFECUTER_SIMULATION]);
            update_panels();
            doupdate();

            mvwprintw(Tab[EFFECUTER_SIMULATION],0,0,"Resultat : \n");
            for(c = 0; c<NombreSimu;c++)
            {
                mvwprintw(Tab[EFFECUTER_SIMULATION],2+c,2,"Mission: %d \t Agent: %d \t \n", MaSimulation.a_tAttributions[c][0], MaSimulation.a_tAttributions[c][1]);
            }


            update_panels();
            doupdate();

            wprintw(Tab[EFFECUTER_SIMULATION],"Appuyez sur une touche pour continuer ...\n\n");
            wrefresh(Tab[EFFECUTER_SIMULATION]);
            getch();
            wclear(Tab[EFFECUTER_SIMULATION]);

            //wprintw(Tab[EFFECUTER_SIMULATION],"Voulez vous appliquer la simulation ? (y/n)\n");
            //wrefresh(Tab[EFFECUTER_SIMULATION]);
            //Reponse=getch();


            //wprintw("%d",MaSimulation.a_NbrElements);
            MaSimulation.a_NbrElements=NombreSimu;
            update_panels();
            doupdate();
            wChoixBinaire(Tab[EFFECUTER_SIMULATION],2,2,"Voulez vous appliquer la simulation ?","Oui","Non",&Reponse);

            if(Reponse==0)
            {
                int Succes[NombreSimu];
                for(c=0;c<NombreSimu;c++)
                {
                    wprintw(Tab[EFFECUTER_SIMULATION],"L'agent %d a t-il réussi la mission %d ?   ?",MaSimulation.a_tAttributions[c][1],MaSimulation.a_tAttributions[c][0]);

                    wChoixBinaire(Tab[EFFECUTER_SIMULATION],5+3*c,2,"","Oui","Non",&Reponse);

                    if(Reponse==0)
                    {
                        Succes[c]=1;
                    }
                    else
                    {
                        Succes[c]=0;
                    }
                }


                appliquersim(&MaSimulation,Liste,ListeM,Succes);
                wclear(Tab[EFFECUTER_SIMULATION]);

                wChoixBinaire(Tab[EFFECUTER_SIMULATION],2,2,"La simulation a été effectué: Voulez vous l'enregistrer ?","Oui","Non",&Reponse);
                curs_set(1);
                echo();
                if(Reponse==0)
                {
                    wprintw(Tab[EFFECUTER_SIMULATION],"Nom de la simulation:\n");
                    wgetnstr(Tab[EFFECUTER_SIMULATION],Saisie,20);
                    MaSimulation.a_tNom=(char*)malloc((strlen(Saisie)+1)*sizeof(char));
                    MaSimulation.a_tNom=Saisie;
                    F_EnregistrerSimulation(MaSimulation);

                    wprintw(Tab[EFFECUTER_SIMULATION],"\nLa simulation a été effectué et enregistré:\nAppuyez sur une touche pour continuer...");
                    wrefresh(Tab[EFFECUTER_SIMULATION]);

                }

                wAfficherSimulation(Tab[LISTE_SIMULATION],5,2);
                curs_set(0);
                noecho();

                wrefresh(Tab[EFFECUTER_SIMULATION]);
                getch();

            }
            else
            {
                //rien
            }


            noecho();
            curs_set(0);
            wclear(Tab[EFFECUTER_SIMULATION]);

            top_panel(Pan[MENU_PRINCIPAL]);



        }

        update_panels();
        doupdate();
        refresh();
        Key=CurseurVertical(&Curseur,3);

        wrefresh(Tab[MENU_PRINCIPAL]);
    }while(((Key!=13&&Key!=459)||Curseur!=2)&&Key!=27&&Key!=8);


}

void GererDonne(WINDOW*Tab[],PANEL *Pan[],FlagAgent *Liste,FlagMission *ListeM)
{
    Critere *TabCrit=NULL;
    int NbrCritere=0;

    TabCrit=F_LoadTabCrits(TabCrit,&NbrCritere);


    wattron(Tab[1],COLOR_PAIR(4));
    AfficherAsciiArt(Tab[1],"VacheRealiste.txt",1,COLS/2-25);
    wattroff(Tab[1],COLOR_PAIR(4));

    int Key=0;
    int Curseur=0;


    //Variables des sous menus
    int Curseur2=0;
    int Key2=0;


    top_panel(Pan[1]);

    init_pair(1,COLOR_BLACK,COLOR_WHITE);
    wattron(Tab[1],COLOR_PAIR(1));
    mvwprintw(Tab[1],4,2,"Gérer les données:");
    wattroff(Tab[1],COLOR_PAIR(1));
    do
    {
        mvwprintw(Tab[1],4,COLS-COLS/3,"Fonctions:");
        AfficherCentrer(Tab[1],2*LINES/3,COLS/2,"Agents");
        AfficherCentrer(Tab[1],2*LINES/3+2,COLS/2,"Critères");
        AfficherCentrer(Tab[1],2*LINES/3+4,COLS/2,"Missions");
        AfficherCentrer(Tab[1],2*LINES/3+6,COLS/2,"Simulation");
        AfficherCentrer(Tab[1],2*LINES/3+8,COLS/2,"Retour");
        wattron(Tab[1],COLOR_PAIR(1));
        switch(Curseur)
        {
        case 0:
            AfficherCentrer(Tab[1],2*LINES/3,COLS/2,"Agents");
            top_panel(Pan[3]);
            top_panel(Pan[7]);
            box(Tab[7],0,0);
            break;
        case 1:
            AfficherCentrer(Tab[1],2*LINES/3+2,COLS/2,"Critères");
            top_panel(Pan[4]);
            top_panel(Pan[8]);
            box(Tab[8],0,0);
            break;
        case 2:
            AfficherCentrer(Tab[1],2*LINES/3+4,COLS/2,"Missions");
            top_panel(Pan[5]);
            top_panel(Pan[9]);
            box(Tab[9],0,0);
            break;
        case 3:
            AfficherCentrer(Tab[1],2*LINES/3+6,COLS/2,"Simulation");
            top_panel(Pan[6]);
            top_panel(Pan[10]);
            box(Tab[10],0,0);
            break;
        case 4:
            wattroff(Tab[1],COLOR_PAIR(1));
            mvwprintw(Tab[1],4,COLS-COLS/3,"          ");
            wattron(Tab[1],COLOR_PAIR(1));
            AfficherCentrer(Tab[1],2*LINES/3+8,COLS/2,"Retour");
            top_panel(Pan[1]);
            break;
        }
        wattroff(Tab[1],COLOR_PAIR(1));

        //Choix

        if(((Key==13||Key==459)||Key==KEY_RIGHT)&&Curseur==0) //Agents
        {
            Key2=0;
            Curseur2=0;
            do
            {
                mvwprintw(Tab[7],2,2,"Rechercher Agent\n  Ajouter Agent\n  Modifier un Agent\n  Supprimer un Agent\n  Retour");
                wattron(Tab[7],COLOR_PAIR(1));
                switch(Curseur2)
                {
                case 0:
                    mvwprintw(Tab[7],2,2,"Rechercher Agent");
                    break;
                case 1:
                    mvwprintw(Tab[7],3,2,"Ajouter Agent");
                    break;
                case 2:
                    mvwprintw(Tab[7],4,2,"Modifier un Angent");
                    break;
                case 3:
                    mvwprintw(Tab[7],5,2,"Supprimer un Agent");
                    break;
                case 4:
                    mvwprintw(Tab[7],6,2,"Retour");
                    break;
                }
                wattroff(Tab[7],COLOR_PAIR(1));
                box(Tab[7],0,0);
                update_panels();
                doupdate();
                Key2=CurseurVertical(&Curseur2,5);


                if((Key2==13||Key2==459)&&Curseur2==0)
                {
                    resize_window(Tab[LISTE_AGENT],getmaxy(Tab[LISTE_AGENT]),2*COLS/3);
                    wAfficherListeAgent(Tab[LISTE_AGENT],2,2,Liste);


                    //wclear(Tab[LISTE_AGENT]);
                    top_panel(Pan[LISTE_AGENT]);
                    box(Tab[LISTE_AGENT],0,0);
                    update_panels();
                    doupdate();
                    wRechercherAgent(Tab,Pan,Liste);
                }

                if((Key2==13||Key2==459)&&Curseur2==1)
                {
                    wAjouterAgent(Tab,Pan,Liste);

                }

                if((Key2==13||Key2==459)&&Curseur2==2)
                {

                    wModifierAgent(Tab,Pan,Liste);
                }

                if((Key2==13||Key2==459)&&Curseur2==3)
                {

                    wSupAgent(Tab,Pan,Liste);
                }





            }while(((Key2!=13&&Key2!=459)||Curseur2!=4)&&Key2!=KEY_LEFT);
            mvwprintw(Tab[7],2,2,"Rechercher Agent\n  Ajouter Agent\n  Modifier un Agent\n  Supprimer un Agent\n  Retour");
            box(Tab[7],0,0);
            update_panels();
            doupdate();

        }

        if(((Key==13||Key==459)||Key==KEY_RIGHT)&&Curseur==1) //Critère
        {
            Key2=0;
            Curseur2=0;
            do
            {
                mvwprintw(Tab[8],2,2,"Ajouter un critère\n  Supprimer un critère\n  Modifier un critère\n  Retour");
                wattron(Tab[8],COLOR_PAIR(1));
                switch(Curseur2)
                {
                case 0:
                    mvwprintw(Tab[8],2,2,"Ajouter un critère");
                    break;
                case 1:
                    mvwprintw(Tab[8],3,2,"Supprimer un critère");
                    break;
                case 2:
                    mvwprintw(Tab[8],4,2,"Modifier un critère");
                    break;
                case 3:
                    mvwprintw(Tab[8],5,2,"Retour");
                    break;
                }
                wattroff(Tab[8],COLOR_PAIR(1));
                box(Tab[8],0,0);
                update_panels();
                doupdate();
                Key2=CurseurVertical(&Curseur2,4);

            }while((Key2!=13||Curseur2!=3)&&Key2!=KEY_LEFT);
            mvwprintw(Tab[8],2,2,"Ajouter un critère\n  Supprimer un critère\n  Modifier un critère\n  Retour");
            box(Tab[8],0,0);
            update_panels();
            doupdate();
        }

        if((((Key==13||Key==459)||Key==KEY_RIGHT)&&Curseur==2)) //Missions
        {
            Key2=0;
            Curseur2=0;
            do
            {
                mvwprintw(Tab[9],2,2,"Rechercher Mission\n  Ajouter Mission\n  Modifier une Mission\n  Supprimer une Mission\n  Retour");
                wattron(Tab[9],COLOR_PAIR(1));
                switch(Curseur2)
                {
                case 0:
                    mvwprintw(Tab[9],2,2,"Rechercher Mission");
                    break;
                case 1:
                    mvwprintw(Tab[9],3,2,"Ajouter Mission");
                    break;
                case 2:
                    mvwprintw(Tab[9],4,2,"Modifier une Mission");
                    break;
                case 3:
                    mvwprintw(Tab[9],5,2,"Supprimer une Mission");
                    break;
                case 4:
                    mvwprintw(Tab[9],6,2,"Retour");
                    break;
                }
                wattroff(Tab[9],COLOR_PAIR(1));
                box(Tab[9],0,0);
                update_panels();
                doupdate();
                Key2=CurseurVertical(&Curseur2,5);

                if(Key2==13 && Curseur2==1)
                {
                    wAjouterMission(Tab,Pan,ListeM);
                }

                if((Key2==13||Key2==459)&&Curseur2==3)
                {
                    wSupMission(Tab,Pan,ListeM);
                }

            }while(((Key2!=13&&Key2!=459)||Curseur2!=4)&&Key2!=KEY_LEFT);
            mvwprintw(Tab[9],2,2,"Rechercher Mission\n  Ajouter Mission\n  Modifier une Mission\n  Supprimer une Mission\n  Retour");
            box(Tab[9],0,0);
            update_panels();
            doupdate();
        }

        if(((Key==13||Key==KEY_RIGHT)&&Curseur==3)) //Simulation
        {

        }

        if(Key==KEY_LEFT&&Curseur==0) // Agrandissement des données
        {

            init_pair(9,COLOR_CYAN,COLOR_BLACK);
            resize_window(Tab[LISTE_AGENT],getmaxy(Tab[LISTE_AGENT]),2*COLS/3);
            wclear(Tab[LISTE_AGENT]);
            ClasserAgent(Liste,1);
            wAfficherListeAgent(Tab[LISTE_AGENT],2,2,Liste);
            wAfficherCritereAgent(Tab[LISTE_AGENT],2,50,Liste);
            box(Tab[LISTE_AGENT],0,0);
            update_panels();
            doupdate();
            Key=0;
            Curseur=0;
            do
            {
                switch(Curseur)
                {
                case 0:
                    wclear(Tab[LISTE_AGENT]);
                    ClasserAgent(Liste,Curseur+1);
                    wAfficherListeAgent(Tab[LISTE_AGENT],2,2,Liste);
                    wAfficherCritereAgent(Tab[LISTE_AGENT],2,50,Liste);
                    wattron(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    wattron(Tab[LISTE_AGENT],A_BOLD);
                    mvwprintw(Tab[LISTE_AGENT],LINES-8,2,"Trié selon critère: %s",TabCrit[Curseur].a_tNom);
                    wattroff(Tab[LISTE_AGENT],A_BOLD);
                    wattroff(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    break;
                case 1:
                    wclear(Tab[LISTE_AGENT]);
                    ClasserAgent(Liste,Curseur+1);
                    wAfficherListeAgent(Tab[LISTE_AGENT],2,2,Liste);
                    wAfficherCritereAgent(Tab[LISTE_AGENT],2,50,Liste);
                    wattron(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    wattron(Tab[LISTE_AGENT],A_BOLD);
                    mvwprintw(Tab[LISTE_AGENT],LINES-8,2,"Trié selon critère: %s",TabCrit[Curseur].a_tNom);
                    wattroff(Tab[LISTE_AGENT],A_BOLD);
                    wattroff(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    break;
                case 2:
                    wclear(Tab[LISTE_AGENT]);
                    ClasserAgent(Liste,Curseur+1);
                    wAfficherListeAgent(Tab[LISTE_AGENT],2,2,Liste);
                    wAfficherCritereAgent(Tab[LISTE_AGENT],2,50,Liste);
                    wattron(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    wattron(Tab[LISTE_AGENT],A_BOLD);
                    mvwprintw(Tab[LISTE_AGENT],LINES-8,2,"Trié selon critère: %s",TabCrit[Curseur].a_tNom);
                    wattroff(Tab[LISTE_AGENT],A_BOLD);
                    wattroff(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    break;
                case 3:
                    wclear(Tab[LISTE_AGENT]);
                    ClasserSalaire(Liste);
                    wAfficherListeAgent(Tab[LISTE_AGENT],2,2,Liste);
                    wAfficherCritereAgent(Tab[LISTE_AGENT],2,50,Liste);
                    wattron(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    wattron(Tab[LISTE_AGENT],A_BOLD);
                    mvwprintw(Tab[LISTE_AGENT],LINES-8,2,"Trié par salaire");
                    wattroff(Tab[LISTE_AGENT],A_BOLD);
                    wattroff(Tab[LISTE_AGENT],COLOR_PAIR(9));
                    break;
                }
                update_panels();
                doupdate();



                Key=CurseurVertical(&Curseur,1+NbrCritere);
            }while(Key!=KEY_RIGHT);

            wclear(Tab[LISTE_AGENT]);
            resize_window(Tab[LISTE_AGENT],getmaxy(Tab[LISTE_AGENT]),COLS/3);
            wAfficherListeAgent(Tab[LISTE_AGENT],3,3,Liste);
            wrefresh(Tab[LISTE_AGENT]);
            box(Tab[LISTE_AGENT],0,0);
            update_panels();
            doupdate();
            top_panel(Pan[GERER_DONNEES]);
            top_panel(Pan[FONCTION_AGENT]);
            top_panel(Pan[LISTE_AGENT]);

        }



        update_panels();
        doupdate();
        Key=CurseurVertical(&Curseur,5);


    }while(((Key!=13&&Key!=459)||Curseur!=4)&&Key!=KEY_F(1)&&Key!=27&&Key!=8);
    update_panels();
    doupdate();


    top_panel(Pan[0]);
    update_panels();
    doupdate();

    SuppTabCrits(TabCrit,&NbrCritere);
}

void wRechercherAgent(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste)
{
    int Key=0;
    int Curseur=0;
    int Txt[30];
    Txt[29]='\0';
    int Item=-1;
    int i=0;
    int EstTrouve=0;
    top_panel(Pan[RECHERCHER_AGENT]);
    mvwprintw(Tab[RECHERCHER_AGENT],2,2,"Rechercher Agent par son ID\n\n  ID: ");
    box(Tab[RECHERCHER_AGENT],0,0);

    SaisieFormulaire(Tab[RECHERCHER_AGENT],Txt,&Item);
    if(Item==-1)
    {
        for(i=0;i<Liste->a_Taille;i++)
        {
            if(atoi(Txt)==(int)(GetAgent(Liste,i)->a_ID))
            {
                mvwprintw(Tab[RECHERCHER_AGENT],6,2,"Agent: %s  \n  Salaire: %.2f",GetAgent(Liste,i)->a_tNom,GetAgent(Liste,i)->a_Salaire);
                box(Tab[RECHERCHER_AGENT],0,0);
                EstTrouve=1;
            }
        }

        if(EstTrouve==0)
        {
            mvwprintw(Tab[RECHERCHER_AGENT],6,2,"Pas d'agents trouvé à cet ID");
        }
        mvprintw(Tab[RECHERCHER_AGENT],7,2,"Appuiyez sur une touche pour continuer ...");
        wrefresh(Tab[RECHERCHER_AGENT]);
        getch();

    }

    /*
    mvwprintw(Tab[RECHERCHER_AGENT],4,7,"           ");
    wmove(Tab[RECHERCHER_AGENT],4,7);
    wgetnstr(Tab[RECHERCHER_AGENT],Txt,10);
    wmove(Tab[RECHERCHER_AGENT],0,0);
    */

    wclear(Tab[RECHERCHER_AGENT]);


    box(Tab[RECHERCHER_AGENT],0,0);
    hide_panel(Pan[RECHERCHER_AGENT]);
    resize_window(Tab[LISTE_AGENT],getmaxy(Tab[LISTE_AGENT]),COLS/3);
    box(Tab[LISTE_AGENT],0,0);
    update_panels();
    doupdate();

}




int CurseurVertical(int *Curseur,unsigned int NombreItem)
{
    int Key=getch();
    if(Key==KEY_UP)
    {
        (*Curseur)--;
        (*Curseur) =((*Curseur)+NombreItem)%NombreItem;
    }
    if(Key==KEY_DOWN)
    {
        (*Curseur)++;
        (*Curseur)=((*Curseur)+NombreItem)%NombreItem;
    }
    return Key;
}



void wAfficherCritereAgent(WINDOW *Win,int y,int x,FlagAgent *Liste)
{
    int NbrCrits=0;
    Critere *TabCrits=NULL;
    TabCrits = F_LoadTabCrits(TabCrits,&NbrCrits);
    int i=0,j=0;
    wmove(Win,y,x);

    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(6,COLOR_YELLOW,COLOR_BLACK);
    init_pair(7,COLOR_GREEN,COLOR_BLACK);

    for(i=0;i<Liste->a_Taille;i++)
    {

        //wprintw(Win,"Agent n: %d: \n",i);
        //wprintw(Win,"(Critère/Score):");
        for(j=0;j<Liste->a_DimScore;j++)
        {
            //wprintw(Win,"   |Critère: %8s     Score: %2.f |",TabCrits[j].a_tNom,GetAgent(Liste,i)->a_tScore[j][1]);

            wprintw(Win,"  (");
            wattron(Win,A_BOLD);
            wprintw(Win,"%s",TabCrits[j].a_tNom);
            wattroff(Win,A_BOLD);
            wprintw(Win,"/");
            wattron(Win,A_BOLD);
            if(GetAgent(Liste,i)->a_tScore[j][1]<33)
            {
                wattron(Win,COLOR_PAIR(2));
                wprintw(Win,"%3.f",GetAgent(Liste,i)->a_tScore[j][1]);
                wattroff(Win,COLOR_PAIR(2));
            }
            else if(GetAgent(Liste,i)->a_tScore[j][1]>66)
            {
                wattron(Win,COLOR_PAIR(7));
                wprintw(Win,"%3.f",GetAgent(Liste,i)->a_tScore[j][1]);
                wattroff(Win,COLOR_PAIR(7));
            }
            else
            {
                wattron(Win,COLOR_PAIR(6));
                wprintw(Win,"%3.f",GetAgent(Liste,i)->a_tScore[j][1]);
                wattroff(Win,COLOR_PAIR(6));
            }
            wattroff(Win,A_BOLD);
            wprintw(Win,")  ");

            //wprintw(Win,"  (%s/%3.f)  ",TabCrits[j].a_tNom,GetAgent(Liste,i)->a_tScore[j][1]);
            box(Win,0,0);
        }
        wmove(Win,y+i+1,x);
        box(Win,0,0);
    }

    SuppTabCrits(TabCrits,&NbrCrits);
}



void wAfficherListeAgent(WINDOW*Win,int y,int x,FlagAgent *Liste)
{
    wclear(Win);
    wmove(Win,y,x);

    if(Liste->a_Elmt1!=NULL)
    {
        int i=0;
        Agent *Pivot=Liste->a_Elmt1;
        for(i=0;i<Liste->a_Taille;i++)
        {
            mvwprintw(Win,y+i,x,"Agent %2d: Nom: %15s  Salaire: %7.2f",Pivot->a_ID,Pivot->a_tNom==NULL?'\0':Pivot->a_tNom,Pivot->a_Salaire);
            box(Win,0,0);
            Pivot=Pivot->Suivant;
        }
    }
    else
    {
        wprintw(Win,"Pas d'agents dans cette liste\n");
    }
}


void wAfficherCritere(WINDOW *Win,int y,int x,Critere *ListeCritere,long unsigned int TailleDuTableau)
{
    int i=0;

    for(i=0;i<TailleDuTableau;i++)
    {
       mvwprintw(Win,y+i,x,"ID critère: %5lu  Critère: %20s",ListeCritere[i].a_ID,ListeCritere[i].a_tNom);
    }
}


void wAjouterAgent(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste)
{
    wclear(Tab[AJOUTER_AGENT]);
    AjouterAgentNP1(Liste);
    //printf("====  %d  =====",Liste->a_Elmtn->a_ID);
    int NbrCritere;
    Critere *TabCrit=NULL;
    TabCrit=F_LoadTabCrits(TabCrit,&NbrCritere);

    char Txt[30];
    char *NomDyn=NULL;
    int i=0;
    int Reponse=0;

    top_panel(Pan[AJOUTER_AGENT]);

    mvwprintw(Tab[AJOUTER_AGENT],2,2,"Ajouter un agent:");
    mvwprintw(Tab[AJOUTER_AGENT],4,2,"Nom: ");
    curs_set(1);
    echo();

    update_panels();
    doupdate();
    wgetnstr(Tab[AJOUTER_AGENT],Txt,30);
    NomDyn=(char*)malloc(sizeof(char)*(strlen(Txt)+1));
    strcpy(NomDyn,Txt);
    Liste->a_Elmtn->a_tNom=NomDyn;


    mvwprintw(Tab[AJOUTER_AGENT],6,2,"Salaire: ");
    update_panels();
    doupdate();
    strcpy(Txt,"");
    wgetnstr(Tab[AJOUTER_AGENT],Txt,10);
    Liste->a_Elmtn->a_Salaire=(float)atof(Txt);

    wSaisieScoreAgent(Tab[AJOUTER_AGENT],8,2,Liste->a_Elmtn);
    wAfficherListeAgent(Tab[LISTE_AGENT],4,2,Liste);

    wChoixBinaire(Tab[AJOUTER_AGENT],getcury(Tab[AJOUTER_AGENT])+3,2,"Valider ?","Oui","Non",&Reponse);
    update_panels();
    doupdate();


    if(Reponse==0)
    {
        F_EnregistrerAgent(*(Liste->a_Elmtn),*Liste);
    }
    else
    {
        SupAgent(Liste,Liste->a_Taille-1);
    }
    box(Tab[AJOUTER_AGENT],0,0);
    wAfficherListeAgent(Tab[LISTE_AGENT],4,2,Liste);



    curs_set(0);
    noecho();
    hide_panel(Pan[AJOUTER_AGENT]);
    SuppTabCrits(TabCrit,&NbrCritere);

}

void wAjouterMission(WINDOW *Tab[],PANEL *Pan[],FlagMission *Liste)
{
    wclear(Tab[AJOUTER_MISSION]);

    char Txt[10];
    char *NomDyn=NULL;
    int i=0;
    int Reponse=0;
    AjouterMissionNP1(Liste);
    top_panel(Pan[AJOUTER_MISSION]);

    mvwprintw(Tab[AJOUTER_MISSION],2,2,"Ajouter une mission:");
    mvwprintw(Tab[AJOUTER_MISSION],4,2,"Nom: ");
    curs_set(1);
    echo();

    update_panels();
    doupdate();
    wgetnstr(Tab[AJOUTER_MISSION],Txt,10);
    NomDyn=(char*)malloc(sizeof(char)*(strlen(Txt)+1));
    strcpy(NomDyn,Txt);
    Liste->a_Elmtn->a_tNom=NomDyn;


    mvwprintw(Tab[AJOUTER_MISSION],6,2,"Duree: ");
    update_panels();
    doupdate();
    strcpy(Txt,"");
    wgetnstr(Tab[AJOUTER_MISSION],Txt,10);
    Liste->a_Elmtn->a_Duree=(double)atof(Txt);

    wSaisieScoreMission(Tab[AJOUTER_MISSION],8,2,Liste->a_Elmtn);
    wAfficherListeMission(Tab[LISTE_MISSIONS],4,2,Liste);



    wChoixBinaire(Tab[AJOUTER_MISSION],getcury(Tab[AJOUTER_MISSION])+2,2,"Valider ?","Oui","Non",&Reponse);
    wclear(Tab[LISTE_MISSIONS]);

    if(Reponse==0)
    {
        F_EnregistrerMission(*(Liste->a_Elmtn),*Liste);
    }
    else
    {
        SupMission(Liste,Liste->a_Taille-1);
    }
    box(Tab[AJOUTER_AGENT],0,0);
    wAfficherListeMission(Tab[LISTE_MISSIONS],4,2,Liste);
    box(Tab[LISTE_MISSIONS],0,0);


    curs_set(0);
    noecho();
    hide_panel(Pan[AJOUTER_MISSION]);

}


void wSaisieScoreAgent(WINDOW *Win,int y,int x,Agent *Membre)
{

    int j=0;
    char Clear=0;

    Critere *TabCrit=NULL;
    int NbrCrit=0;
    TabCrit=F_LoadTabCrits(TabCrit,&NbrCrit);


    mvwprintw(Win,y,x,"Veuillez saisir les scores de l'agent un a un:");

    wprintw(Win,"  \nAgent %s   ",Membre->a_tNom);
    for(j=0;j<Membre->a_DimScore;j++)
    {
        //wprintw(Win,"  \nScore du critere ID: %.f:  ",Membre->a_tScore[j][0]);
        wprintw(Win,"  \nScore du critère: %s:  ",TabCrit[j].a_tNom);
        wscanw(Win,"%f",&(Membre->a_tScore[j][1]));
       // while((Clear=getch())!=EOF&&Clear!='\n'&&Clear!='\0');
    }

    SuppTabCrits(TabCrit,&NbrCrit);

}

void wSaisieScoreMission(WINDOW *Win,int y,int x,Mission *Membre)
{
    Critere *TabCrit=NULL;
    int NbrCrit=0;
    TabCrit=F_LoadTabCrits(TabCrit,&NbrCrit);

    int j=0;
    char Clear=0;
    mvwprintw(Win,y,x,"Veuillez saisir les ponderations une a une:");

    wprintw(Win,"  \nMission %s   ",Membre->a_tNom);
    for(j=0;j<Membre->a_DimPonderation;j++)
    {
        //wprintw(Win,"  \nPonderation du critere ID: %.f:  ",Membre->a_tPonderation[j][0]);
        wprintw(Win,"  \nPonderation du critere: %s:  ",TabCrit[j].a_tNom);
        wscanw(Win,"%f",&(Membre->a_tPonderation[j][1]));
       // while((Clear=getch())!=EOF&&Clear!='\n'&&Clear!='\0');
    }

    SuppTabCrits(TabCrit,&NbrCrit);

}


void wAfficherListeMission(WINDOW *Win,int y,int x,FlagMission *Liste)
{
    if(Liste->a_Elmt1!=NULL)
    {
        int i=0;
        Mission *Pivot=Liste->a_Elmt1;
        for(i=0;i<Liste->a_Taille;i++)
        {

            mvwprintw(Win,y+i,x,"Mission %d: Nom: %8s  Duree: %3.0f",Pivot->a_ID,Pivot->a_tNom==NULL?'\0':Pivot->a_tNom,Pivot->a_Duree);
            Pivot=Pivot->Suivant;
        }
    }
    else
    {
        printf("Pas de missions dans cette liste\n");
    }
    box(Win,0,0);
}



void wAfficherSimulation(WINDOW *Win,int y,int x)
{
    int NbrSimus=0;
    simulation *TabSimus=NULL;
    TabSimus = (F_LoadAllSimulations(TabSimus,&NbrSimus));

    wclear(Win);
    mvwprintw(Win,0,0,"Liste des simulations");

    int i;
    for (i=0;i<NbrSimus;i++)
    {
        mvwprintw(Win,y+i,x,"Simulation : %8s",(TabSimus[i].a_tNom));
        box(Win,0,0);
        //SuppSimulation(&(TabSimus[i]),TabSimus[i].a_NbrElements);
    }
}

void SaisieFormulaire(WINDOW *Win,int *Txt,int *Item)
{
    wmove(Win,4,4);
    update_panels();
    keypad(Win,TRUE);

    doupdate();
    noecho();
    curs_set(1);
    int PosCurseur=0;
    int x=getcurx(Win)+2;
    int y=getcury(Win);
    int c=0;


    wmove(Win,y,x);

    if(*Item==-1)
    {
        PosCurseur=0;
    }


    wrefresh(Win);
    while(c!=13&&c!=459)
    {

        c=wgetch(Win);
        if(c==KEY_RIGHT)
        {
            if(PosCurseur<strlen(Txt))
            {
                printf("\a");
                PosCurseur++;
                wmove(Win,y,x+PosCurseur);
            }

        }
        else if(c==KEY_LEFT)
        {
            if(PosCurseur>0)
            {
                PosCurseur--;
                wmove(Win,y,x+PosCurseur);
            }
            else
            {
                *Item=1;
                break;
            }
        }
        else if(c==KEY_UP)
        {
            *Item=2;
            break;
        }
        else if(c==KEY_DOWN)
        {
            *Item=5;
            break;
        }
        else if(c==27) //Echap
        {
            *Item=8;
            break;
        }
        else if(c==8&&PosCurseur>0) //Backspace
        {
            Txt[PosCurseur-1]='\0';
            PosCurseur--;
            mvwprintw(Win,8,4,"%d",PosCurseur);
            mvwprintw(Win,y,x+PosCurseur+1," ");
            wmove(Win,y,PosCurseur+x+1);
           // wmove(Win,getcury(Win),x+PosCurseur+3);
        }
        else if(('A'<=c&&c<='Z')||('a'<=c&&c<='z')||('0'<=c&&c<='9')||c==32)
        {
            //printf("%d  %c",PosCurseur,c);
            Txt[PosCurseur]=c;
            PosCurseur++;
            mvwprintw(Win,y,x+PosCurseur,"%c",c);
            wmove(Win,y,x+PosCurseur+1);
        }
        else
        {
            wmove(Win,y,x);
        }
        //printf("\a Bla ");
        update_panels();
        doupdate();
        wrefresh(Win);

       // while((esc=wgetch(Win))!=EOF&&esc!='\n');
        flushinp();

    }
    wclear(Win);
    //mvwprintw(Win,5,5,"%s",Txt);

    char *Test;
    int g=0,h=0;
    Txt[20]='\0';

    while(Txt[h]!='\0');
    {
        h++;
    }

    Test=(char*)malloc(h*sizeof(char));
    for(g=0;h;g++)
    {
        Test[g]=Txt[g];
    }

    printf("%s",Test);
    wrefresh(Win);
    getch();

}


void wChoixBinaire(WINDOW *Win,int y,int x,const wchar_t *Question,const wchar_t *Choix1,const wchar_t *Choix2,int *Reponse)
{

    mvwprintw(Win,y,x,"%s",Question);
    int CurseurBinaire=0;
    int Key=0;

    init_pair(1,COLOR_BLACK,COLOR_WHITE);
    do
    {

        mvwprintw(Win,y+1,x,"%s",Choix1);
        mvwprintw(Win,y+1,x+strlen(Choix1)+2,"/ %s",Choix2);



        if(Key==KEY_RIGHT||Key==KEY_LEFT)
        {
            CurseurBinaire=1-CurseurBinaire;
        }

        wattron(Win,COLOR_PAIR(1));

        switch(CurseurBinaire)
        {
        case 0:
            mvwprintw(Win,y+1,x,"%s",Choix1);
            break;
        case 1:
            mvwprintw(Win,y+1,x+strlen(Choix1)+4,"%s",Choix2);
            break;
        }
        wattroff(Win,COLOR_PAIR(1));



        wrefresh(Win);
        update_panels();
        doupdate();
        Key=getch();
        wprintw(Win,"\n");

        if((Key==13||Key==479)&&CurseurBinaire==0)
        {
            *Reponse=0;
        }
        else if((Key==13||Key==479)&&CurseurBinaire==1)
        {
            *Reponse=1;
        }


    }while(Key!=13&&Key!=279);


}

void wSupAgent(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste)
{
    long unsigned int ID=0;
    int y=getcury(Tab[SUPPRIMER_AGENT]);
    int x=getcurx(Tab[SUPPRIMER_AGENT]);
    int Reponse=0;
    int i=0;
    top_panel(Pan[SUPPRIMER_AGENT]);
    wclear(Tab[SUPPRIMER_AGENT]);
    box(Tab[SUPPRIMER_AGENT],0,0);
    mvwprintw(Tab[SUPPRIMER_AGENT],2,2,"Entrez l'index de l'agent à supprimer: ");
    curs_set(1);
    echo();
    update_panels();
    doupdate();
    wscanw(Tab[SUPPRIMER_AGENT],"%lu",&ID);
    curs_set(0);
    noecho();
    wChoixBinaire(Tab[SUPPRIMER_AGENT],getcury(Tab[SUPPRIMER_AGENT])+2,x+2,"Êtes vous surs de vouloir supprimer l'agent  ?","Oui","Non",&Reponse);


    if(Reponse==0)
    {
        for(i=0;i<Liste->a_Taille;i++)
        {
            if(GetAgent(Liste,i)->a_ID==ID)
            {
                SupAgent(Liste,i);
            }
        }
        wAfficherListeAgent(Tab[LISTE_AGENT],3,2,Liste);
        wrefresh(Tab[LISTE_AGENT]);
        F_SupprimerAgent(ID);
    }
    else
    {
        //Rien
    }
    hide_panel(Pan[SUPPRIMER_AGENT]);
    top_panel(Pan[FONCTION_AGENT]);
}



void wModifierAgent(WINDOW *Tab[],PANEL * Pan[],FlagAgent *Liste)
{
    int NbrCritere=0;
    Critere *TabCrit=NULL;

    TabCrit=F_LoadTabCrits(TabCrit,&NbrCritere);

    top_panel(Pan[MODIFIER_AGENT]);
    wclear(Tab[MODIFIER_AGENT]);
    int Reponse=0;
    int ID;
    char *TxtDyn=NULL;
    char Txt[30];
    int i=0;

    int y=getcury(Tab[MODIFIER_AGENT]);
    int x=getcurx(Tab[MODIFIER_AGENT])+2;
    mvwprintw(Tab[MODIFIER_AGENT],2,x,"Entrez l'ID de l'agent à modifier: ");
    box(Tab[MODIFIER_AGENT],0,0);
    echo();
    curs_set(1);
    update_panels();
    doupdate();
    wscanw(Tab[MODIFIER_AGENT],"%d",&ID);

    wChoixBinaire(Tab[MODIFIER_AGENT],4,2,"Voulez vous changer le nom ?","Oui","Non",&Reponse);

    if(Reponse==0)
    {
        wmove(Tab[MODIFIER_AGENT],getcury(Tab[MODIFIER_AGENT])+2,x);
        wprintw(Tab[MODIFIER_AGENT],"Saississez le nom:  ");
        wgetnstr(Tab[MODIFIER_AGENT],Txt,30);
        TxtDyn=(char*)malloc((strlen(Txt)+1)*sizeof(char));
        strcpy(TxtDyn,Txt);
        GetAgentByID(Liste,ID)->a_tNom=TxtDyn;
    }
    else
    {
        //Rien
    }

    wChoixBinaire(Tab[MODIFIER_AGENT],4,2,"Voulez vous changer son salaire ?","Oui","Non",&Reponse);

    if(Reponse==0)
    {
        wmove(Tab[MODIFIER_AGENT],getcury(Tab[MODIFIER_AGENT])+8,x);
        wprintw(Tab[MODIFIER_AGENT],"Saississez le salaire:  ");
        wscanw(Tab[MODIFIER_AGENT],"%f",&(GetAgentByID(Liste,ID)->a_Salaire));
    }


    wChoixBinaire(Tab[MODIFIER_AGENT],getcury(Tab[MODIFIER_AGENT])+2,x,"Voulez vous changer un score ?","Oui","Non",&Reponse);

    if(Reponse==0)
    {
        for(i=0;i<Liste->a_DimScore;i++)
        {
            mvwprintw(Tab[MODIFIER_AGENT],getcury(Tab[MODIFIER_AGENT])+2,x,"Voulez vous changer le critère: %s ?",TabCrit[i].a_tNom);
            wChoixBinaire(Tab[MODIFIER_AGENT],getcury(Tab[MODIFIER_AGENT])+2,x,"","Oui","Non",&Reponse);

            if(Reponse==0)
            {
                wmove(Tab[MODIFIER_AGENT],getcury(Tab[MODIFIER_AGENT])+1,x);
                wscanw(Tab[MODIFIER_AGENT],"%f",&(GetAgentByID(Liste,ID)->a_tScore[i][1]));
            }

        }
    }
    wclear(Tab[MODIFIER_AGENT]);
    box(Tab[MODIFIER_AGENT],0,0);
    mvwprintw(Tab[MODIFIER_AGENT],2,4,"Agent: %s   Salaire: %5.2f",GetAgentByID(Liste,ID)->a_tNom,GetAgentByID(Liste,ID)->a_Salaire);
    for(i=0;i<Liste->a_DimScore;i++)
    {
        wprintw(Tab[MODIFIER_AGENT]," (%s/%.f) ",TabCrit[i].a_tNom,GetAgentByID(Liste,ID)->a_tScore[i][1]);
    }

    wChoixBinaire(Tab[MODIFIER_AGENT],getcury(Tab[MODIFIER_AGENT])+2,x,"Voulez vous appliquer ces modifications ?","Oui","Non",&Reponse);

    if(Reponse==0)
    {
        F_EnregistrerAgent(*GetAgentByID(Liste,ID),*Liste);
    }


    hide_panel(Pan[MODIFIER_AGENT]);
    wAfficherListeAgent(Tab[LISTE_AGENT],3,2,Liste);
    SuppTabCrits(TabCrit,&NbrCritere);

}


void wSupMission(WINDOW *Tab[],PANEL *Pan[],FlagMission *Liste)
{
    long unsigned int ID=0;
    int y=getcury(Tab[SUPPRIMER_MISSION]);
    int x=getcurx(Tab[SUPPRIMER_MISSION]);
    int Reponse=0;
    int i=0;
    top_panel(Pan[SUPPRIMER_MISSION]);
    wclear(Tab[SUPPRIMER_MISSION]);
    box(Tab[SUPPRIMER_MISSION],0,0);
    mvwprintw(Tab[SUPPRIMER_MISSION],2,2,"Entrez l'index de la mission à supprimer: ");
    curs_set(1);
    echo();
    update_panels();
    doupdate();
    wscanw(Tab[SUPPRIMER_MISSION],"%lu",&ID);
    curs_set(0);
    noecho();
    wChoixBinaire(Tab[SUPPRIMER_MISSION],getcury(Tab[SUPPRIMER_MISSION])+2,x+2,"Êtes vous surs de vouloir supprimer la mission  ?","Oui","Non",&Reponse);


    if(Reponse==0)
    {
        for(i=0;i<Liste->a_Taille;i++)
        {
            if(GetMission(Liste,i)->a_ID==ID)
            {
                SupMission(Liste,i);
            }
        }
        wclear(Tab[LISTE_MISSIONS]);
        mvwprintw(Tab[LISTE_MISSIONS],2,2,"Liste des missions:");
        wAfficherListeMission(Tab[LISTE_MISSIONS],4,2,Liste);
        wrefresh(Tab[LISTE_MISSIONS]);
        F_SupprimerMission(ID);
    }
    else
    {
        //Rien
    }
    hide_panel(Pan[SUPPRIMER_MISSION]);
    top_panel(Pan[FONCTION_MISSIONS]);
    wrefresh(Tab[LISTE_MISSIONS]);

}

void wAfficherResulatSimulation(WINDOW *Tab[],PANEL *Pan[],int y, int x,char *NomSimu)
{
    simulation *MesSimulation=NULL;
    int NbrSimu=0;
    MesSimulation=F_LoadAllSimulations(MesSimulation,&NbrSimu);
    int i=0;

    top_panel(Pan[RESULTAT_SIMULATION]);
    box(Tab[RESULTAT_SIMULATION],0,0);

    for(i=0;i<NbrSimu;i++)
    {
        if(!strcmp(NomSimu,MesSimulation[i].a_tNom))
        {
            mvwprintw(Tab[RESULTAT_SIMULATION],y,x,"Simulation: %s",NomSimu);
        }
    }

    for(i=0;i<MesSimulation[i].a_NbrElements;i++)
    {
        mvwprintw(Tab[RESULTAT_SIMULATION],y+2+i,x,"%lu    %lu      %f",MesSimulation[i].a_tAttributions[0][0],MesSimulation[i].a_tAttributions[0][1],MesSimulation[i].a_tCouts);
    }



}


