#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int F_RechercheBalise(FILE* fichier,char Balise[])
{
    rewind(fichier);
    int pos = ftell(fichier);
    fscanf(fichier,Balise);
    while (ftell(fichier)== pos && !feof(fichier))
    {
        while (fgetc(fichier) != '\n');
      //  printf("ligne suivante");
        pos = ftell(fichier);
        fscanf(fichier,Balise);
    }
    //printf("Balise trouvee");
    return pos;
}
