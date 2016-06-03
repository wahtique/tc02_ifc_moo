#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void AjouterMission0(FlagMission *Liste)
 {
    int i=0,ID_temp=1;

    Mission *NouvelMission=(Mission*)malloc(sizeof(Mission));
    InitMission(NouvelMission);
    if(Liste->a_Elmt1!=NULL)
    {
        Liste->a_Elmt1->Precedent=NouvelMission;
        NouvelMission->Suivant=Liste->a_Elmt1;
        Liste->a_Elmt1=NouvelMission;

    }
    else
    {
        Liste->a_Elmt1=NouvelMission;
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    Liste->a_Taille++;

    MajCritereMission(Liste,0);


    ID_temp=1;

    while(i<Liste->a_Taille) //Pour s'assurer l'unicité de l'ID
    {
        if((int)ID_temp==(int)(GetMission(Liste,i)->a_ID))
        {
            ID_temp++;
            i=0;
        }
        i++;
    }


}
