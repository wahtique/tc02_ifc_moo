#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Mission.h"

void InitMission(Mission *Membre)
{
    Membre->a_ID=0;
    Membre->a_tPonderation=NULL;
    Membre->a_tNom=NULL;
    Membre->a_Duree=0;
    Membre->a_DimPonderation=0;

    Membre->Suivant=NULL;
    Membre->Precedent=NULL;


}


