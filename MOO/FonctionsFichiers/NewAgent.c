#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

int F_NewAgent(char Nom[])
{
    char NomFichier[10];
    DIR* rep = NULL;
    struct dirent* fichierLu = NULL;
    rep = opendir("./Agent");
    if (rep == NULL){
        mkdir("./Agent");
    }
    seekdir(rep,2);
    while((fichierLu = readdir(rep)) != NULL){
    //printf("Le fichier lu s'appelle '%s'", fichierLu->d_name);
        strcpy(NomFichier,fichierLu->d_name);
    }
    NomFichier[strlen(NomFichier)-2]='\0';
    int nbr = atoi(NomFichier)+1;
    itoa(nbr,NomFichier,10);


    closedir(rep);

    FILE* fichier = NULL;
    char CheminFichier[10]="./Agent/";
    strcat(CheminFichier,NomFichier);
    strcat(CheminFichier,".g");
    printf("Fichier : %s\n",CheminFichier);
    fichier = fopen(CheminFichier,"w+");

    fprintf(fichier,"Nom : %s",Nom);
    fclose(fichier);
}
