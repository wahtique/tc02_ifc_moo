#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"
<<<<<<< HEAD

=======
#include <string.h>

//<<<<<<< HEAD
/*
int main()
{
    // Test manipulation de pointeurs 2D dinamique n lignes p colones
/*
    int n=3,p=2;
    int i=0,j=0;
    int **A=NULL;
    A=(int**)malloc(n*sizeof(int*));

    for(i=0;i<n;i++)
    {
        *(A+i)=(int*)malloc(p*sizeof(int));
    }
    int S=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            *(*(A+i)+j)=S;
            printf("%d\n",A[i][j]);
            S++;
        }
    }




    free(A);

>>>>>>> 34665411967c06e0e69c562549901ab2cd6bae7d

int main() // main de Tri0b
{

    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    AjouterAgentNP1(Liste);
    AjouterAgentNP1(Liste);
    //SetAgent(Liste,0,1,"Robin",47000);
    //printf("%p",Liste->a_Elmt1);
    DebugListe(Liste);


    //printf("%d",Liste->a_Taille);

    //DebugListe(Liste);
    //AfficherListeAgent(Liste);
    //printf("%f",Liste->a_Elmt1->a_Salaire);

    //AfficherListeAgent(Liste->a_Elmt1);

    free(Liste);
<<<<<<< HEAD

    return 0;
}
=======
*/
>>>>>>> 34665411967c06e0e69c562549901ab2cd6bae7d



/*

int main() //Main de Naej
{
<<<<<<< HEAD
    printf("**** Project MOO **** \n Is the best project ever");
    Agent NouvelAgent = {1,NULL,NULL,0.5};
    printf("%2.2f",NouvelAgent.a_Salaire);
    F_NewAgent();

=======
    printf("**** Project MOO **** \n Is the best project ever\n");
    //Agent NouvelAgent = {1,NULL,NULL,0.5};

    //printf("%2.2f",NouvelAgent.a_Salaire);
    printf("Entrez le nom de l'agent :");
    char NomAgent[25];
    gets(NomAgent);
    F_NewAgent(NomAgent);
    F_LoadAgent();
>>>>>>> 34665411967c06e0e69c562549901ab2cd6bae7d
    return 0;
}
*/


/*

int main() //Main de Willy
{

    return 0;
}


*/
