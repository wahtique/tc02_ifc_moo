#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED


typedef struct Agent Agent;
typedef struct FlagAgent FlagAgent;

void InitAgent(Agent* Membre); //Initialise tous les membres d'un agent
void InitFlagAgent(FlagAgent *Liste); // Initialise tous les membres d'un FlagAgent

void InsAgent(FlagAgent* Liste,unsigned int index); //Insère d'un agent JUSTE AVANT l'élément i
void AjouterAgent0(FlagAgent *Liste); // Ajout d'un agent au début
void AjouterAgentNP1(FlagAgent *Liste); //Ajout d'un agent à la fin

void AjouterAgent(FlagAgent *Liste,unsigned int CodePosition); // Fonction redondante avec les deux précedentes, permet une autre façon de coder
void AjouterNAgent0(FlagAgent *Liste,unsigned int Qte); //Ajoute Qte Agents au début de la liste
void AjouterNAgentNP1(FlagAgent *Liste,unsigned int Qte); //Ajoute Qte Agents à la fin de la liste
void InsNAgent(FlagAgent *Liste,unsigned int Qte,unsigned int index); //Insere Qte agents à partir de la position index

Agent *GetAgent(FlagAgent *Liste,unsigned int index);
void SetAgent(FlagAgent *Liste,unsigned int index,unsigned int ID,char Nom[],float Salaire);

void SupAgent(FlagAgent *Liste,unsigned int index); //Supprime le i-ème agent
void SupListe(FlagAgent *Liste);


void AjouterCritere(FlagAgent *Liste);



//Affichage

void AfficherListeAgent(FlagAgent *Liste);

// Fonctions de debug

void DebugListe(FlagAgent *Liste);



struct Agent
{
    long unsigned int a_ID;
    char *a_tNom;
    float **a_tScore; // Tableau 2D de dimension nx2
    float a_Salaire;

    Agent *Suivant;
    Agent *Precedent;

};


struct FlagAgent
{
    Agent *a_Elmt1;
    Agent *a_Elmtn;

    float **a_tScoreSchem; // Modèle de score, permet de générer un squellete de tableau de score de façon indépendante du nombres d'agents dans la liste

    long unsigned int a_Taille;
    long unsigned int a_DimScore;


};


#endif // AGENT_H_INCLUDED
