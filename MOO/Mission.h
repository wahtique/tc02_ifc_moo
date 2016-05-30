#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

typedef struct Mission Mission;

struct Mission
{


    long unsigned int a_ID;
    char *a_tNom;
    float **a_Ponderation;

	double a_duree; //en heures
	long unsigned int a_DimPonderation;



};



#endif // MISSION_H_INCLUDED
