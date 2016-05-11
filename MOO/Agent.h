#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED


typedef struct Agent Agent;
typedef struct FlagAgent FlagAgent;

void InitAgent(Agent* Membre); //Initialise tous les membres d'un agent
void InitFlagAgent(FlagAgent *Liste); // Initialise tous les membres d'un FlagAgent

void InsAgent(FlagAgent* Liste,unsigned int index); //Insère d'un agent JUSTE AVANT l'élément i
void AjouterAgent0(FlagAgent *Liste); // Ajout d'un agent au début
void AjouterAgentNP1(FlagAgent *Liste); //Ajout d'un agent à la fin
Agent *GetAgent(FlagAgent *Liste,unsigned int index);

void SupAgent(FlagAgent *Liste,unsigned int index); //Supprime le i-ème agent
void SetAgent(FlagAgent *Liste,unsigned int index,unsigned int ID,char Nom[],float Salaire);



//Affichage

void AfficherListeAgent(FlagAgent *Liste);

// Fonctions de debug

void DebugListe(FlagAgent *Liste);


struct Agent
{
    long unsigned int a_ID;
    char *a_tNom;
    float **a_tScore;
    float a_Salaire;

    Agent *Suivant;
    Agent *Precedent;

};


struct FlagAgent
{
    Agent *a_Elmt1;
    Agent *a_Elmtn;

    long unsigned int a_Taille;

    //Experimental

    unsigned short int a_LongueurSegment;
    Agent *a_Ref;

};


#endif // AGENT_H_INCLUDED
