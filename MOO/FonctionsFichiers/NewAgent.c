#include <stdio.h>
#include <stdlib.h>

int F_NewAgent()
{
    FILE* fichier = NULL;
    fichier = fopen("agent/1.g","a");

    fclose(fichier);
}
