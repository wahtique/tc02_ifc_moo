#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"

int F_EnregistrerTabCrits(Critere *TabCritsRef,int *NbrCrits)
{
    FILE* fichier = NULL;
    fichier = fopen("TabCrits.g","w+");
    if (fichier != NULL)
    {
        int i;
        for (i=0;i<*NbrCrits;i++)
        {
            printf("%lu : %s\n",TabCritsRef[i].a_ID,TabCritsRef[i].a_tNom);
            fprintf(fichier,"%d : %s\n",TabCritsRef[i].a_ID,TabCritsRef[i].a_tNom);
        }

    }
    fclose(fichier);
    return 0;
}
