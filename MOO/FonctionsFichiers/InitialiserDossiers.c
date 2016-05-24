#include <stdlib.h>
#include <dirent.h>
#ifndef WIN32
    #include <sys/types.h>
#endif

void F_InitialiserDossiers()
{
    DIR* rep = NULL;
    rep = opendir("./Agent");
    if (rep == NULL){
        mkdir("./Agent");
    }closedir(rep);
    rep = opendir("./Simulations");
    if (rep == NULL){
        mkdir("./Simulations");
    }closedir(rep);
    rep = opendir("./Missions");
    if (rep == NULL){
        mkdir("./Missions");
    }

    closedir(rep);
}
