#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
#include "Critere.h"

typedef struct Agent Agent;
typedef struct FlagAgent FlagAgent;

void InitAgent(Agent* Membre); //Initialise tous les membres d'un agent
void InitFlagAgent(FlagAgent *Liste); // Initialise tous les membres d'un FlagAgent

void InsAgent(FlagAgent* Liste,unsigned int index); //Ins�re d'un agent JUSTE AVANT l'�l�ment i
void AjouterAgent0(FlagAgent *Liste); // Ajout d'un agent au d�but
void AjouterAgentNP1(FlagAgent *Liste); //Ajout d'un agent � la fin

void AjouterAgent(FlagAgent *Liste,unsigned int CodePosition); // Fonction redondante avec les deux pr�cedentes, permet une autre fa�on de coder
void AjouterNAgent0(FlagAgent *Liste,unsigned int Qte); //Ajoute Qte Agents au d�but de la liste
void AjouterNAgentNP1(FlagAgent *Liste,unsigned int Qte); //Ajoute Qte Agents � la fin de la liste
void InsNAgent(FlagAgent *Liste,unsigned int Qte,unsigned int index); //Insere Qte agents � partir de la position index


Agent *GetAgent(FlagAgent *Liste,unsigned int index); //OK
Agent *GetAgentViaID(FlagAgent *Liste,unsigned int ID);


void SetAgent(FlagAgent *Liste,unsigned int index,long unsigned int ID,char Nom[],float Salaire);


void SupAgent(FlagAgent *Liste,unsigned int index); //Supprime le i-�me agent
void SupListe(FlagAgent *Liste); //OK


void AjouterCritere(FlagAgent *Liste); //OK
void SupCritere(FlagAgent *Liste,unsigned int idcritere);
void MajCritereAgent(FlagAgent *Liste,unsigned int indexAgent);
void SaisieScore(FlagAgent *Liste);
int RecupIndexCritere(FlagAgent *Liste,float ID);






//Affichage

void AfficherListeAgent(FlagAgent *Liste); //OK
void AfficherCritere(Critere *ListeCritere,long unsigned int TailleDuTableau); //OK


// Fonctions de debug

void DebugListe(FlagAgent *Liste);


struct Agent
{
    long unsigned int a_ID;
    char *a_tNom;
    float **a_tScore; // Tableau 2D de dimension nx2
    unsigned int a_DimScore;
    float a_Salaire;

    Agent *Suivant;
    Agent *Precedent;
};


struct FlagAgent
{
    Agent *a_Elmt1;
    Agent *a_Elmtn;

    float **a_tScoreSchem; // Mod�le de score, permet de g�n�rer un squellete de tableau de score de fa�on ind�pendante du nombres d'agents dans la liste
    long unsigned int a_Taille;
    long unsigned int a_DimScore;

};


#endif // AGENT_H_INCLUDED
