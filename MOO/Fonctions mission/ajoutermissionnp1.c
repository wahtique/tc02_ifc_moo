#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"
void AjouterMissionNP1(FlagMission *Liste)
{
    int i=0, ID_temp=1;

    Mission *NouvelleMission=(Mission*)malloc(sizeof(Mission));
    if(NouvelleMission==NULL)
    {
        printf("### ERREUR:InsMission: Allocation impossible ###");
        exit(EXIT_FAILURE);
    }
    InitMission(NouvelleMission);
    if(Liste->a_Elmt1!=NULL)
    {
        Liste->a_Elmtn->Suivant=NouvelleMission;
        NouvelleMission->Precedent=Liste->a_Elmtn;
        Liste->a_Elmtn=NouvelleMission;
    }
    else
    {
        Liste->a_Elmt1=NouvelleMission;
        Liste->a_Elmtn=Liste->a_Elmt1;
    }
    Liste->a_Taille++;
    MajCritereMission(Liste,Liste->a_Taille-1);

    ID_temp=1;

    while(i<Liste->a_Taille) //Pour s'assurer l'unicité de l'ID
    {
        if((int)ID_temp==(int)GetMission(Liste,i)->a_ID)
        {
            ID_temp++;
            i=0;
        }
        i++;
    }

    Liste->a_Elmtn->a_ID=ID_temp;


}
