#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"
<<<<<<< HEAD
=======
//<<<<<<< HEAD

//=======
>>>>>>> 3a65a69f6b834de4b0674413dcb23c048762b3a1
#include <string.h>
#define DEBUT 0
#define FIN 1

typedef unsigned short byte;



int main() // main de Tri0b
{

    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    AjouterNAgent(Liste,3,DEBUT);
    AjouterNAgent0(Liste,5);
    AjouterNAgentNP1(Liste,4);
    SetAgent(Liste,0,1,"Robin",777);
    SupAgent(Liste,0);
    DebugListe(Liste);



    //Désalocation de Liste

    SupListe(Liste);







    //Déclaration
    int **Tab2D;
    int n=5,p=3;
    int i=0,j=0,s=0;

    Tab2D=(int**)malloc(n*sizeof(int*));

    if(Tab2D==NULL)
    {
        exit(EXIT_FAILURE);
    }

    for(i=0;i<n;i++)
    {
        *(Tab2D+i)=(int*)malloc(p*sizeof(int));
        if(*(Tab2D+i)==NULL)
        {
            exit(EXIT_FAILURE);
        }
    }
    //Affichage et affectation
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            *(*(Tab2D+i)+j)=s;
            printf("%d   ",*(*(Tab2D+i)+j));
            s++;
        }
        printf("\n");
    }
    */



    //Redimenssionement

    //On souhaite ajouter 2 lignes et 3 colones
    n+=2;
    p+=3;
    Tab2D=(int**)realloc(Tab2D,n*sizeof(int*));

    if(Tab2D==NULL)
    {
        exit(EXIT_FAILURE);
    }

    for(i=0;i<n;i++)
    {
        *(Tab2D+i)=(int*)realloc(*(Tab2D+i),p*sizeof(int));
        if(*(Tab2D+i)==NULL)
        {
            exit(EXIT_FAILURE);
        }
    }


    //Nouveau test d'affichage et allocation
    printf("\n");
    s=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            *(*(Tab2D+i)+j)=s;
            printf("%p   ",(*(Tab2D+i)+j));
            s++;
        }
        printf("\n");
    }




    //Suppression

    for(i=0;i<n;i++)
    {
        if(Tab2D[i])
        {
            free(Tab2D[i]);
            Tab2D[i]=NULL;
        }
    }
    if(Tab2D)
    {
        free(Tab2D);
        Tab2D=NULL;
    }



    return 0;
}
<<<<<<< HEAD

=======
=======
*/
//>>>>>>> 34665411967c06e0e69c562549901ab2cd6bae7d
>>>>>>> 3a65a69f6b834de4b0674413dcb23c048762b3a1





int main() //Main de Naej
{
    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};

    //printf("%2.2f",NouvelAgent.a_Salaire);
    printf("Entrez le nom de l'agent :");
    char NomAgent[25];
    gets(NomAgent);
    F_NewAgent(NomAgent);
    //F_LoadAgent();
    F_GetAgentNom(1);
    return 0;
}



/*

int main() //Main de Willy
{

    return 0;
}
*/


