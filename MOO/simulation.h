#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED


typedef struct simulation simulation;

//a_tAttributions donne la répartition agents - mission
//une mission peut apparaitre plusieurs fois
//un agent de peut apparaitre qu'une fois
//a_tCouts donne le cout en i de la ièeme mission éxécutée par le i-ème agent
//le nom (optionnel, laisser vide par défaut) et la date ne sont là que
//pour aider l'utilisateur à s'y retrouver

struct simulation
{
	long unsigned int a_ID;
	long unsigned int a_NbrElements;
	char *a_tNom;
	long unsigned int **a_tAttributions;
	double *a_tCouts;
};

simulation* AllocSimulation(simulation*Simulation,int NbrElement);
void SuppSimulation(simulation*Simulation,int NbrElement);
#endif // SIMULATION_H_INCLUDED
