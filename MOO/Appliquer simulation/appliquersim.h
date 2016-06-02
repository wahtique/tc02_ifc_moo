#ifndef APPLIQUERSIM_H_INCLUDED
#define APPLIQUERSIM_H_INCLUDED

#include "../simulation.h"
#include "../Mission.h"
#include "../Agent.h"

//fonction appliquant une simulation
//on lui fournit aussi un tableau à une dimension donnant les succès
void appliquersim(simulation, FlagAgent *ListeA, FlagMission *ListeM, int *);

#endif // APPLIQUERSIM_H_INCLUDED
