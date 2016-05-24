#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int F_RechercheBalise(FILE* fichier,char Balise[])
{
    rewind(fichier);
    int pos = ftell(fichier);
    fscanf(fichier,Balise);
    int i=0;
    while (i<strlen(Balise) && !feof(fichier))
    {
        if (fgetc(fichier)==Balise[i]){
            i++;
        } else {
            i=0;
        }
    }
    //printf("Balise trouvee");
    return i;
}
