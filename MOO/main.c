#include <stdio.h>
#include <stdlib.h>
#include "Agent.h"

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
*/


    //printf("**** Project MOO **** \n Is the best project ever");
    FlagAgent *Liste=(FlagAgent*)malloc(sizeof(FlagAgent));
    InitFlagAgent(Liste);

    AjouterAgent(Liste,0);
    AjouterAgent(Liste,1);
    AjouterAgent(Liste,2);

    Liste->a_Elmt1->a_Salaire=50.;
    Liste->a_Elmtn->a_Salaire=100.;
    DebugListe(Liste);
    //printf("%f",Liste->a_Elmt1->a_Salaire);

    //AfficherListeAgent(Liste->a_Elmt1);


    free(Liste);





    return 0;
}
