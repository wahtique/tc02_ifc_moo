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
=======
	long unsigned int a_ID;
	char *a_tNom;
	double a_duree; //en heures
	int nb_crit;
	double **a_tPonderations;
	//tableau de [2][nb_crit] pour les pondérations, en 0,i les id des criteres, et en 1,i les pondérations
	//ne pas oublier de caster
	

>>>>>>> 44dcb8e012e28ef0046d8eb380b758592bad8215
};



#endif // MISSION_H_INCLUDED
