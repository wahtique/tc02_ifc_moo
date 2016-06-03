#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"
void AjouterMissionNP1(FlagMission *Liste)
{
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


}