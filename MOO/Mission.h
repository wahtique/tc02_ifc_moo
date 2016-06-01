#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

#include "Critere.h"

typedef struct Mission Mission;
typedef struct FlagMission FlagMission;

struct Mission
{


    long unsigned int a_ID;
    char *a_tNom;
    float **a_tPonderation;

	double a_Duree; //en heures
	long unsigned int a_DimPonderation; //nombres de criteres auquels on associe une pondération


	Mission *Suivant;
	Mission *Precedent;
};



struct FlagMission
{
    Mission *a_Elmt1;
    Mission *a_Elmtn;

    float **a_tPonderationSchem; // Modèle pondération, permet de générer un squellete de tableau de pondérations de façon indépendante du nombres de mission dans la liste
    long unsigned int a_Taille;
    long unsigned int a_DimPonderation;

};

void InitMission(Mission *Membre); //Initialise tous les membres d'une mission
void InitFlagMission(FlagMission *Liste); // Initialise tous les membres d'un FlagMission

void AjouterMissionNP1(FlagMission *Liste); //Ajout d'une mission à la fin

void AjouterNMissionNP1(FlagMission *Liste,unsigned int Qte); //Ajoute Qte Mission à la fin de la list0e

Mission *GetMission(FlagMission *Liste,unsigned int index); //OK
Mission *GetMissionById(FlagMission *Liste, unsigned int index);
long unsigned int GetIndexMission(FlagMission *Liste,long unsigned int ID);

void SetMission(FlagMission *Liste,unsigned int index,long unsigned int ID,char Nom[],float Duree);


void SupMission(FlagMission *Liste,unsigned int index); //Supprime la i-ème mission
void SupListeM(FlagMission *Liste); //OK

void AjouterCritereM(FlagMission *Liste); //OK
void SupCritereM(FlagMission *Liste,unsigned int idcritere);
void MajCritereMission(FlagMission *Liste,unsigned int indexAgent);
void SaisieScoreM(FlagMission *Liste);

int RecupIndexCritereM(FlagMission *Liste,float ID);

void AfficherListeMission(FlagMission *Liste); //OK
void AfficherCritereM(Critere *ListeCritere,long unsigned int TailleDuTableau); //OK

#endif // MISSION_H_INCLUDED
