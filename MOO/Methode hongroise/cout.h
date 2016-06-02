#ifndef COUT_H_INCLUDED
#define COUT_H_INCLUDED

typedef struct Cout Cout;

struct Cout
{
	//le cout calculé avec un agent
	float c;
	//des boolens, essayez pas de comprendre ce que ça veut dire
	int barre;
	int encadre;
	//celui là entre 0 et 2
	int trait;
};



#endif // COUT_H_INCLUDED
