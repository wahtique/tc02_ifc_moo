#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"


int main() // main de Tri0b
{

    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    AjouterAgentNP1(Liste);
    AjouterAgentNP1(Liste);
    //SetAgent(Liste,0,1,"Robin",47000);
    //printf("%p",Liste->a_Elmt1);
    DebugListe(Liste);


    //printf("%d",Liste->a_Taille);

    //DebugListe(Liste);
    //AfficherListeAgent(Liste);
    //printf("%f",Liste->a_Elmt1->a_Salaire);

    //AfficherListeAgent(Liste->a_Elmt1);

    free(Liste);

    return 0;
}



/*

int main() //Main de Naej
{
    printf("**** Project MOO **** \n Is the best project ever");
    Agent NouvelAgent = {1,NULL,NULL,0.5};
    printf("%2.2f",NouvelAgent.a_Salaire);
    F_NewAgent();

    return 0;
}
*/


/*

int main() //Main de Willy
{

    return 0;
}


*/
