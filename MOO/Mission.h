#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

typedef struct Mission Mission;

struct Mission
{
    long unsigned int a_ID;
    char *a_tNom;
    float **a_Ponderation;
    float a_Duree;
};



#endif // MISSION_H_INCLUDED
