#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

typedef struct Mission Mission;

struct Mission
{

    long unsigned int a_ID;
    char *a_tNom;
    float **a_Ponderation;
    float a_Duree;


	double a_duree; //en heures
	long unsigned int a_DimPonderation;

	//tableau de [2][nb_crit] pour les pondérations, en 0,i les id des criteres, et en 1,i les pondérations
	//ne pas oublier de caster



};



#endif // MISSION_H_INCLUDED
