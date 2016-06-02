#ifndef IHM_H_INCLUDED
#define IHM_H_INCLUDED
#include <panel.h>
#include "Mission.h"
#include "Agent.h"
#include "Fichiers.h"
#include "simulation.h"


void AfficherCentrer(WINDOW*,int,int,const char*);
void AfficherCadre(void);
void MenuPrincipal(WINDOW*Tab[],PANEL *Pan[],FlagAgent *Liste);
void GererDonne(WINDOW*Tab[],PANEL *PAN[],FlagAgent *Liste);
int CurseurVertical(int *Curseur,unsigned int NombreItem);


void RechercherAgent(WINDOW *Tab[],PANEL *Pan[],FlagAgent *Liste);



//Fonction d'affichage Agent

void wAfficherListeAgent(WINDOW *Win,int y,int x,FlagAgent *Liste);
void wAfficherCritereAgent(WINDOW *Win,int y,int x,FlagAgent *Liste);


void wAfficherListeMission(WINDOW *Win,int y,int x,FlagMission *Liste);
void wAfficherSimulation(WINDOW *Win,int y,int x);

#endif // IHM_H_INCLUDED
