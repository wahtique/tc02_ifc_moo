#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED


typedef struct Agent Agent;
typedef struct FlagAgent FlagAgent;

void InsAgent(FlagAgent* Liste,unsigned int index);
void AjouterAgent0(FlagAgent Liste);
void AjouterAgentNP1(FlagAgent Liste);

void InitAgent(Agent* Membre);
void InitFlagAgent(FlagAgent *Liste);

struct Agent
{
    long unsigned int a_ID;
    char *a_tNom;
    float **a_tScore;
    float a_Salaire;
//<<<<<<< HEAD

    Agent *Suivant;
    Agent *Precedent;


//=======
//>>>>>>> f5fac770b290e0bec51a36b84416cc8ba60dc12d
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
