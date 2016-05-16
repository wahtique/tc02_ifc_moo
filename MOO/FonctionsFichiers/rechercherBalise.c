#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

int F_RechercheBalise(FILE* fichier,char Balise[])
{
    rewind(fichier);
    int pos = ftell(fichier);
    fscanf(fichier,Balise);
    while (ftell(fichier)== pos && !feof(fichier))
    {
        while (fgetc(fichier) != '\n');
        printf("ligne suivante");
        pos = ftell(fichier);
        fscanf(fichier,Balise);
    }
    printf("Balise trouvee");
    return pos;
}
