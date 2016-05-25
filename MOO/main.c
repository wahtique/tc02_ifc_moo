#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"
#include "MemManager.h"
#include <string.h>
#define DEBUT 0
#define FIN 1
#include "Fichiers.h"
#include "runSimulation.h"

typedef unsigned short byte;


/*
int main() // main de Tri0b
{

    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    AjouterNAgent(Liste,3,DEBUT);
    AjouterNAgent0(Liste,5);
    AjouterNAgentNP1(Liste,4);
    SetAgent(Liste,11,1,"Robin",777);






    DebugListe(Liste);
    AjouterCritere(Liste);
    AjouterCritere(Liste);

    printf("%.0f %.2f\n",Liste->a_tScoreSchem[0][0],Liste->a_tScoreSchem[0][1]);
    printf("%.0f %.2f",Liste->a_tScoreSchem[1][0],Liste->a_tScoreSchem[1][1]);
    //Désalocation de Liste
    SupListe(Liste);




    return 0;
}



*/

/*int main() //Main de Naej
{
    F_InitialiserDossiers();
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);



    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};
    //printf("%2.2f",NouvelAgent.a_Salaire);


/*
   AjouterAgentNP1(Liste);

    printf("Entrez l'id de l'agent :");
     long unsigned int ID;
    scanf("%lu",&ID);
    printf("Entrez le nom de l'agent :");
    char Nom[25];
    scanf("%s",Nom);
    printf("Entrez le salaire de l'agent :");
    float salaire;
    scanf("%f",&salaire);
    SetAgent(Liste,0,ID,Nom,salaire);
    AjouterCritere(Liste);
    printf("Nombre de crits : %lu\n",Liste->a_DimScore);
    AfficherListeAgent(Liste);
    F_EnregistrerAgent(*GetAgent(Liste,0),*Liste);
/*
    //F_SupprimerAgent(6);
    F_LoadAllAgents(Liste);
    AfficherListeAgent(Liste);
    printf("end\n");
    //DebugListe(Liste);
    SupListe(Liste);
    return 0;
}
*/



//principalement l'appmication d ela méthode hongroise :
//http://optimisons.free.fr/Cours%20M%C3%A9thode%20Hongroise.pdf

int main() //Main de William
{
    int n = 3, i, j;
    Agent agts[n]; 
    Mission m[n];

    float a[2][3] = {{1, 2, 3}, {90, 10, 10}}, b[2][3] = {{1, 2, 3}, {10, 90, 10}}, c[2]3] = {{1, 2, 3}, {10, 10, 90}};


    for(i=0;i<n;i++)
    {
        agts[i].a_ID = i;
        agts[i].a_Salaire = 10;
    }

    agts[0].a_tScore=&a;
    agts[1].a_tScore=&b;
    agts[2].a_tScore=&c;



    return 0;
}



