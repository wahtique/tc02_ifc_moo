#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <panel.h>
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

        if(Key==13&&Curseur==0)
        {
            GererDonne(Tab,Pan,Liste,ListeM);
        }

        if(Key==13&&Curseur==1)
        {
            echo();
            curs_set(1);

            top_panel(Pan[EFFECUTER_SIMULATION]);
            wmove(Tab[EFFECUTER_SIMULATION],0,0);
            wprintw(Tab[EFFECUTER_SIMULATION],"Selection des parametres pour une simulation : \n");
            wprintw(Tab[EFFECUTER_SIMULATION],"Combien de missions de voulez vous effectuer ? (Nombre de missions = Nombre d'agents)\n");
            wrefresh(Tab[EFFECUTER_SIMULATION]);
            wscanw(Tab[EFFECUTER_SIMULATION],"%d",&NombreSimu);

            //tableau d'agents pour la simulation
            AgentSimu=(Agent*)malloc(sizeof(Agent)*NombreSimu);
            int ida, unique, q;
            for(int c = 0; c<NombreSimu;c++)
            {
                wprintw(Tab[EFFECUTER_SIMULATION],"ID de l'agent n %d :\n", c + 1);
                wscanw(Tab[EFFECUTER_SIMULATION],"%d",&ida);
                AgentSimu[c] = *GetAgentByID(Liste, ida);
            }

            //tableau de missions pour la simulation
            MissionSimu=(Mission*)malloc(NombreSimu*sizeof(Mission));
            int idm, indexm;
            int c;
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
                mvwprintw(Tab[EFFECUTER_SIMULATION],2+c,2,"Mission: %d \t Agent: %d \t Cout: %f \n", MaSimulation.a_tAttributions[c][0], MaSimulation.a_tAttributions[c][1], MaSimulation.a_tCouts[c]);
            }


            update_panels();
            doupdate();

            wprintw(Tab[EFFECUTER_SIMULATION],"Appuyez sur une touche pour continuer ...\n\n");
            wrefresh(Tab[EFFECUTER_SIMULATION]);
            getch();
            wclear(Tab[EFFECUTER_SIMULATION]);

            wprintw(Tab[EFFECUTER_SIMULATION],"Voulez vous appliquer la simulation ? (y/n)\n");
            wrefresh(Tab[EFFECUTER_SIMULATION]);
            Reponse=getch();


            //wprintw("%d",MaSimulation.a_NbrElements);
            MaSimulation.a_NbrElements=NombreSimu;


            if(Reponse=='y')
            {
                int Succes[NombreSimu];
                for(c=0;c<NombreSimu;c++)
                {
                    wprintw(Tab[EFFECUTER_SIMULATION],"L'agent %d a t-il réussi la mission %d ? (y/n)    ?",MaSimulation.a_tAttributions[c][1],MaSimulation.a_tAttributions[c][0]);
                    wrefresh(Tab[EFFECUTER_SIMULATION]);
                    Reponse=getch();
                    if(Reponse=='y')
                    {
                        Succes[c]=1;
                    }
                    else
                    {
                        Succes[c]=0;
                    }
                }


                appliquersim(&MaSimulation,Liste,ListeM,Succes);


            }
            else
            {
                //rien
            }


            noecho();
            curs_set(0);

            top_panel(Pan[MENU_PRINCIPAL]);



        }

        update_panels();
        doupdate();
        refresh();
        Key=CurseurVertical(&Curseur,3);
    }while((Key!=13||Curseur!=2)&&Key!=27);


}

void GererDonne(WINDOW*Tab[],PANEL *Pan[],FlagAgent *Liste,FlagMission *ListeM)
{

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

        if((Key==13||Key==KEY_RIGHT)&&Curseur==0) //Agents
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


                if(Key2==13&&Curseur2==0)
                {
                    wRechercherAgent(Tab,Pan,Liste);
                }

                if(Key2==13&&Curseur2==1)
                {
                    wAjouterAgent(Tab,Pan,Liste);

                }



            }while((Key2!=13||Curseur2!=4)&&Key2!=KEY_LEFT);
            mvwprintw(Tab[7],2,2,"Rechercher Agent\n  Ajouter Agent\n  Modifier un Agent\n  Supprimer un Agent\n  Retour");
            box(Tab[7],0,0);
            update_panels();
            doupdate();

        }

        if((Key==13||Key==KEY_RIGHT)&&Curseur==1) //Critère
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

        if(((Key==13||Key==KEY_RIGHT)&&Curseur==2)) //Missions
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


            }while((Key2!=13||Curseur2!=4)&&Key2!=KEY_LEFT);
            mvwprintw(Tab[9],2,2,"Rechercher Mission\n  Ajouter Mission\n  Modifier une Mission\n  Supprimer une Mission\n  Retour");
            box(Tab[9],0,0);
            update_panels();
            doupdate();
        }

        if(((Key==13||Key==KEY_RIGHT)&&Curseur==3)) //Simulation
        {

        }


        update_panels();
        doupdate();
        Key=CurseurVertical(&Curseur,5);


    }while((Key!=13||Curseur!=4)&&Key!=KEY_F(1)&&Key!=27);
    update_panels();
    doupdate();


    top_panel(Pan[0]);
    update_panels();
    doupdate();
    //MenuPrincipal();


}

void wRechercherAgent(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste)
{
    int Key=0;
    int Curseur=0;
    char Txt[10];

    int i=0;
    int EstTrouve=0;
    top_panel(Pan[RECHERCHER_AGENT]);
    mvwprintw(Tab[RECHERCHER_AGENT],2,2,"Rechercher Agent par son ID\n\n  ID: ");
    box(Tab[RECHERCHER_AGENT],0,0);
    curs_set(1);
    echo();
    mvwprintw(Tab[RECHERCHER_AGENT],4,7,"           ");
    wmove(Tab[RECHERCHER_AGENT],4,7);
    wgetnstr(Tab[RECHERCHER_AGENT],Txt,10);
    wmove(Tab[RECHERCHER_AGENT],0,0);

    curs_set(0);
    noecho();


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

    update_panels();
    doupdate();
    wclear(Tab[RECHERCHER_AGENT]);
    getch();

    box(Tab[RECHERCHER_AGENT],0,0);
    hide_panel(Pan[RECHERCHER_AGENT]);
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

void InitWindow()
{
    initscr();
    system("title Modus Operandi Optimum");
    system("Mode Con COLS=180 LINES=60");

}

void wAfficherCritereAgent(WINDOW *Win,int y,int x,FlagAgent *Liste)
{
    int i=0,j=0;
    wmove(Win,y,x);
    for(i=0;i<Liste->a_Taille;i++)
    {

        wprintw(Win,"Agent n: %d: \n",i);
        for(j=0;j<Liste->a_DimScore;j++)
        {

            wprintw(Win,"  ID: %4.f   Score: %8.f\n",GetAgent(Liste,i)->a_tScore[j][0],GetAgent(Liste,i)->a_tScore[j][1]);
            box(Win,0,0);
        }
        wprintw(Win,"  ");
        box(Win,0,0);
    }

}



void wAfficherListeAgent(WINDOW*Win,int y,int x,FlagAgent *Liste)
{
    wmove(Win,y,x);
    if(Liste->a_Elmt1!=NULL)
    {
        int i=0;
        Agent *Pivot=Liste->a_Elmt1;
        for(i=0;i<Liste->a_Taille;i++)
        {

            wprintw(Win,"Agent %4d: Nom: %8s  Salaire: %5.2f\n  ",Pivot->a_ID,Pivot->a_tNom==NULL?'\0':Pivot->a_tNom,Pivot->a_Salaire);
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

    char Txt[10];
    char *NomDyn=NULL;
    int i=0;
    AjouterAgentNP1(Liste);
    top_panel(Pan[AJOUTER_AGENT]);

    mvwprintw(Tab[AJOUTER_AGENT],2,2,"Ajouter un agent:");
    mvwprintw(Tab[AJOUTER_AGENT],4,2,"Nom: ");
    curs_set(1);
    echo();

    update_panels();
    doupdate();
    wgetnstr(Tab[AJOUTER_AGENT],Txt,10);
    NomDyn=(char*)malloc(sizeof(char)*strlen(Txt));
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

    wprintw(Tab[AJOUTER_AGENT],"\n\n  Valider ? (y/n)  ");
    update_panels();
    doupdate();
    i=0;
    do
    {
        i=wgetch(Tab[AJOUTER_AGENT]);

    }while(i!='y'&&i!='n');

    if(i=='y')
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

}

void wAjouterMission(WINDOW *Tab[],PANEL *Pan[],FlagMission *Liste)
{
    wclear(Tab[AJOUTER_MISSION]);

    char Txt[10];
    char *NomDyn=NULL;
    int i=0;
    AjouterMissionNP1(Liste);
    top_panel(Pan[AJOUTER_MISSION]);

    mvwprintw(Tab[AJOUTER_MISSION],2,2,"Ajouter une mission:");
    mvwprintw(Tab[AJOUTER_MISSION],4,2,"Nom: ");
    curs_set(1);
    echo();

    update_panels();
    doupdate();
    wgetnstr(Tab[AJOUTER_MISSION],Txt,10);
    NomDyn=(char*)malloc(sizeof(char)*strlen(Txt));
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

    wprintw(Tab[AJOUTER_MISSION],"\n\n  Valider ? (y/n)  ");
    update_panels();
    doupdate();
    i=0;
    do
    {
        i=wgetch(Tab[AJOUTER_MISSION]);

    }while(i!='y'&&i!='n');

    if(i=='y')
    {
        F_EnregistrerMission(*(Liste->a_Elmtn),*Liste);
    }
    else
    {
        SupMission(Liste,Liste->a_Taille-1);
    }
    box(Tab[AJOUTER_AGENT],0,0);
    wAfficherListeMission(Tab[LISTE_AGENT],4,2,Liste);


    curs_set(0);
    noecho();
    hide_panel(Pan[AJOUTER_MISSION]);

}


void wSaisieScoreAgent(WINDOW *Win,int y,int x,Agent *Membre)
{

    int j=0;
    char Clear=0;
    mvwprintw(Win,y,x,"Veuillez saisir les scores de l'agent un a un:");

    wprintw(Win,"  \nAgent %s   ",Membre->a_tNom);
    for(j=0;j<Membre->a_DimScore;j++)
    {
        wprintw(Win,"  \nScore du critere ID: %.f:  ",Membre->a_tScore[j][0]);
        wscanw(Win,"%f",&(Membre->a_tScore[j][1]));
       // while((Clear=getch())!=EOF&&Clear!='\n'&&Clear!='\0');
    }

}

void wSaisieScoreMission(WINDOW *Win,int y,int x,Mission *Membre)
{

    int j=0;
    char Clear=0;
    mvwprintw(Win,y,x,"Veuillez saisir les ponderations une a une:");

    wprintw(Win,"  \nMission %s   ",Membre->a_tNom);
    for(j=0;j<Membre->a_DimPonderation;j++)
    {
        wprintw(Win,"  \nPonderation du critere ID: %.f:  ",Membre->a_tPonderation[j][0]);
        wscanw(Win,"%f",&(Membre->a_tPonderation[j][1]));
       // while((Clear=getch())!=EOF&&Clear!='\n'&&Clear!='\0');
    }

}


void wAfficherListeMission(WINDOW *Win,int y,int x,FlagMission *Liste)
{
    if(Liste->a_Elmt1!=NULL)
    {
        int i=0;
        Mission *Pivot=Liste->a_Elmt1;
        for(i=0;i<Liste->a_Taille;i++)
        {

            mvwprintw(Win,y+i,x,"Mission %d: Nom: %s  Duree: %5.0f",Pivot->a_ID,Pivot->a_tNom==NULL?'\0':Pivot->a_tNom,Pivot->a_Duree);
            Pivot=Pivot->Suivant;
        }
    }
    else
    {
        printf("Pas de missions dans cette liste\n");
    }

}


void wAfficherSimulation(WINDOW *Win,int y,int x)
{
    int NbrSimus=0;
    simulation *TabSimus;
    TabSimus = (F_LoadAllSimulations(TabSimus,&NbrSimus));
    printf("Nbr Simus %d",NbrSimus);
    int i;
    for (i=0;i<NbrSimus;i++)
    {
        mvwprintw(Win,y+i,x,"Simulation n#: %5.lu      Nom: %s",(TabSimus[i].a_ID),(TabSimus[i].a_tNom));
        box(Win,0,0);
        SuppSimulation(&(TabSimus[i]),TabSimus[i].a_NbrElements);
    }
}
