#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED


typedef struct Agent Agent;

struct Agent
{
    long unsigned int a_ID;
    char *a_tNom;
    float **a_tScore;
    float a_Salaire;
};

typedef struct FlagAgent FlagAgent;

struct FlagAgent
{
    Agent *a_Elmt1;
    Agent *a_Elmtn;

    long unsigned int a_Taille;
};


#endif // AGENT_H_INCLUDED
