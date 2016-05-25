#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"
#include "MemManager.h"
//<<<<<<< HEAD

//=======

#include <string.h>
#define DEBUT 0
#define FIN 1

typedef unsigned short byte;



int main() // main de Tri0b
{
    int n=5;
    n=n+1;
    int Tab[n];



    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);
    /*
    AjouterNAgent(Liste,3,DEBUT);
    AjouterNAgent0(Liste,5);
    AjouterNAgentNP1(Liste,4);
    */
    AjouterAgent0(Liste);
    AjouterAgent0(Liste);
    AjouterAgent0(Liste);
    AjouterAgent0(Liste);

    //SetAgent(Liste,11,1,"Robin",777);




    AfficherListeAgent(Liste);
    AjouterCritere(Liste);
    AjouterCritere(Liste);
    AjouterCritere(Liste);
    SupCritere(Liste,1);
    printf("%.0f %.2f\n",Liste->a_tScoreSchem[0][0],Liste->a_tScoreSchem[0][1]);
    printf("%.0f %.2f\n",Liste->a_tScoreSchem[1][0],Liste->a_tScoreSchem[1][1]);
    //printf("%.0f %.2f\n",Liste->a_tScoreSchem[2][0],Liste->a_tScoreSchem[2][1]);



    //Désalocation de Liste
    SupListe(Liste);

    AfficherListeAgent(Liste);


    return 0;
}



/*

int main() //Main de Naej
{
    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};

    //printf("%2.2f",NouvelAgent.a_Salaire);
    printf("Entrez le nom de l'agent :");
    char NomAgent[25];
    gets(NomAgent);
    F_NewAgent(NomAgent);
    //F_LoadAgent();
    F_GetAgentNom(1);
    return 0;
}



/*

int main() //Main de Willy
{

    return 0;
}
*/


