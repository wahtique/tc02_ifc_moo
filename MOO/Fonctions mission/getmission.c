#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

Mission *GetMission(FlagMission *Liste,unsigned int index)
{

    if(Liste->a_Elmt1!=NULL)
    {
        if(index>=Liste->a_Taille)
        {
            printf("###ERREUR:GetMission: Index incorrect###");
            exit(EXIT_FAILURE);
        }

        Mission *Pivot=Liste->a_Elmt1;
        int i=0;
        for(i=0;i<index;i++)
        {
            Pivot=Pivot->Suivant;
        }

        return Pivot;
    }
    else
    {
        return NULL;
    }

}
