#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

void ClasserAgent(FlagAgent *Liste,float IDCritere)
{
    float ScoreRef=Liste->a_Elmt1->a_tScore[RecupIndexCritere(Liste,IDCritere)][1];
    Agent *Pivot=Liste->a_Elmt1; //Pour éviter les calculs inutiles avec GetAgent
    int i=0,j=0;
    int NombreAgent=Liste->a_Taille;
    if(Liste->a_Taille>0)//Si il y a des agents à classer
    {
        for(i=0;i<Liste->a_Taille;i++) //Recherche du plus grand élement
        {
            //printf("%f     %f\n",ScoreRef,Pivot->a_tScore[RecupIndexCritere(Liste,IDCritere)][1]);
            if(ScoreRef>Pivot->a_tScore[RecupIndexCritere(Liste,IDCritere)][1])
            {
                ScoreRef=Pivot->a_tScore[RecupIndexCritere(Liste,IDCritere)][1];
                //printf("%f\n",ScoreRef);
                if(Pivot->Precedent!=NULL)
                {
                    Pivot->Precedent->Suivant=Pivot->Suivant;
                }
                if(Pivot->Suivant!=NULL)
                {
                    Pivot->Suivant->Precedent=Pivot->Precedent;
                }
                Liste->a_Elmt1->Precedent=Pivot;
                Pivot->Precedent=NULL;
                Pivot->Suivant=Liste->a_Elmt1;
                Liste->a_Elmt1=Pivot;
                Pivot=Liste->a_Elmt1;


                i=0;
            }
            Pivot=Pivot->Suivant;
        }
    }
    else
    {
        printf("Pas d'agents, pas de classements...\n");
    }
}
