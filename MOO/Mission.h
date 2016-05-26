#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

typedef struct Mission Mission;

struct Mission
{

<<<<<<< HEAD
    long unsigned int a_ID;
    char *a_tNom;
    float **a_Ponderation;
    float a_Duree;


	double a_duree; //en heures
	long unsigned int a_DimPonderation;
=======
	long unsigned int a_ID;
	char *a_tNom;
	double a_duree; //en heures
	int nb_crit;
	double **a_tPonderations;
>>>>>>> 6db81c034c99c0b004bf5c1a8daa480ea791105d

	//tableau de [2][nb_crit] pour les pondérations, en 0,i les id des criteres, et en 1,i les pondérations
	//ne pas oublier de caster


<<<<<<< HEAD

=======
>>>>>>> 6db81c034c99c0b004bf5c1a8daa480ea791105d
};



#endif // MISSION_H_INCLUDED
