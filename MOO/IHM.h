#ifndef IHM_H_INCLUDED
#define IHM_H_INCLUDED
#include <panel.h>
#include <wchar.h>
#include "Mission.h"
#include "Agent.h"
#include "Fichiers.h"
#include "simulation.h"


#include "Methode hongroise/purger.h"
#include "Methode hongroise/verifContinuer.h"
#include "Methode hongroise/etape0.h"
#include "Methode hongroise/etape1.h"
#include "Methode hongroise/etape2.h"
#include "Methode hongroise/etape3.h"
#include "Methode hongroise/creer_matrice_couts.h"


void AfficherCentrer(WINDOW*,int,int,const char*);
void AfficherCadre(void);
void MenuPrincipal(WINDOW*Tab[],PANEL *Pan[],FlagAgent *Liste,FlagMission *ListeM);
void GererDonne(WINDOW*Tab[],PANEL *PAN[],FlagAgent *Liste,FlagMission *ListeM);
int CurseurVertical(int *Curseur,unsigned int NombreItem);


void wRechercherAgent(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste);
void wAjouterAgent(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste);
void wSupAgent(WINDOW *Tab[],PANEL *PAN[],FlagAgent *Liste);


void SaisieFormulaire(WINDOW *Win,int *Txt,int *Item);

//Fonction d'affichage Agent

void wAfficherListeAgent(WINDOW *Win,int y,int x,FlagAgent *Liste);
void wAfficherCritereAgent(WINDOW *Win,int y,int x,FlagAgent *Liste);
void wSaisieScoreAgent(WINDOW *Win,int y,int x,Agent *Membre);

void wAfficherListeMission(WINDOW *Win,int y,int x,FlagMission *Liste);
void wAfficherSimulation(WINDOW *Win,int y,int x);
void wModifierAgent(WINDOW *Win[],PANEL *Pan[],FlagAgent *Liste);
void wSaisieScoreMission(WINDOW *Win,int y,int x,Mission *Membre);
void wAjouterMission(WINDOW *Tab[],PANEL *Pan[],FlagMission *Liste);
void wSupMission(WINDOW *Tab[],PANEL *Pan[],FlagMission *Liste);

void wSupCrit(WINDOW *Tab[],PANEL *Pan[],Critere *TabCrits,int *NbrCrits,FlagAgent *ListeA,FlagMission *ListeM);


void wrunSimulation(WINDOW *Tab[],PANEL *Pan[],int n,simulation *sim,Agent agts[n], Mission m[n],Agent med);
void wAfficherResulatSimulation(WINDOW *Win[],PANEL *Pan[],int y, int x,char *,FlagAgent*,FlagMission*);


void wChoixBinaire(WINDOW *Win,int y,int x,const wchar_t *Question,const wchar_t*Choix1,const wchar_t*Choix2,int *Reponse);

#endif // IHM_H_INCLUDED
