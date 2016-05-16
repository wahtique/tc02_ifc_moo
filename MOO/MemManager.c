#include <stdio.h>
#include <stdlib.h>
#include "MemManager.h"
#define TENTATIVE 3


void CheckMalloc(void *Ptr,unsigned int n)
{
    void **Ptr2=NULL;
    Ptr2=Ptr;
    int i=0;
    Ptr=NULL;
    while(Ptr2==NULL&&i<TENTATIVE)
    {
        *Ptr2=malloc(n*sizeof(*Ptr));
        i++;
    }
}



void CheckRealloc(void *Ptr,unsigned int n)
{
    int i=0;
    while(Ptr==NULL&&i<TENTATIVE)
    {
        Ptr=realloc(Ptr,n*sizeof(*Ptr));
        i++;
    }



}
