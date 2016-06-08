#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

Agent *GetAgent(FlagAgent *Liste,unsigned int index) //OK
{

    if(Liste->a_Elmt1!=NULL)
    {
        if(index>=Liste->a_Taille)
        {
            printf("###ERREUR:GetAgent: Index incorrect###");
            exit(EXIT_FAILURE);
        }

        Agent *Pivot=Liste->a_Elmt1;

        if(Liste->a_Elmt1->Precedent!=NULL)
        {
            printf("ERREUR: GetAgent: a_Elmt1 n'est pas le 1er elmt: Valeur de l'index %d",index);
            exit(EXIT_FAILURE);
        }



        int i=0;
        for(i=0;i<index;i++)
        {
            Pivot=Pivot->Suivant;
        }
        //printf("%lu\n",Pivot->a_ID);
        return Pivot;
    }
    else
    {
        return NULL;
    }
}
