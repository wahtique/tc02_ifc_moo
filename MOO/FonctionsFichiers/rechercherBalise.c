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
    fscanf(fichier,Balise);
    //A faire : boucle qui tant que le curseur n'a pas ete bougé par scanf et qu'on a pas atteint la fin du fichier execute les commanges ci dessous
    while (fgetc(fichier) != '\n');
    fscanf(fichier,Balise);
}
