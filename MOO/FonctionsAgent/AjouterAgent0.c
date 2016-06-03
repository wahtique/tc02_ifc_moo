#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void AjouterAgent0(FlagAgent *Liste)
 {
     int i=0;
     int ID_temp=1;

    Agent *NouvelAgent=(Agent*)malloc(sizeof(Agent));
    InitAgent(NouvelAgent);
    if(Liste->a_Elmt1!=NULL)
    {
        Liste->a_Elmt1->Precedent=NouvelAgent;
        NouvelAgent->Suivant=Liste->a_Elmt1;
        Liste->a_Elmt1=NouvelAgent;

    }
    else
    {
        Liste->a_Elmt1=NouvelAgent;
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    Liste->a_Taille++;

    MajCritereAgent(Liste,0);


}
