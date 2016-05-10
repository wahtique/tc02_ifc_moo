#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"


int main()
{
    printf("**** Project MOO **** \n Is the best project ever");
    Agent NouvelAgent = {1,NULL,NULL,0.5};
    printf("%2.2f",NouvelAgent.a_Salaire);
    F_NewAgent();
    return 0;
}
