#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"


void AjouterAgentNP1(FlagAgent *Liste) //OK
{
    Agent *NouvelAgent=(Agent*)malloc(sizeof(Agent));
    if(NouvelAgent==NULL)
    {
        printf("### ERREUR:InsAgent: Allocation impossible ###");
        exit(EXIT_FAILURE);
    }
    InitAgent(NouvelAgent);
    if(Liste->a_Elmt1!=NULL)
    {
        Liste->a_Elmtn->Suivant=NouvelAgent;
        NouvelAgent->Precedent=Liste->a_Elmtn;
        Liste->a_Elmtn=NouvelAgent;
    }
    else
    {
        Liste->a_Elmt1=NouvelAgent;
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    Liste->a_Taille++;
    MajCritereAgent(Liste,Liste->a_Taille-1);
}
