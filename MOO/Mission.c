#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Critere.h"
#include "Mission.h"

void InitMission(Mission *Membre) //OK
{
    Membre->a_ID=0;
    Membre->a_tPonderation=NULL;
    Membre->a_tNom=NULL;
    Membre->a_Salaire=0;
    Membre->a_DimScore=0;

    Membre->Suivant=NULL;
    Membre->Precedent=NULL;


}