#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Critere.h"
#include "../Agent.h"

Agent *GetAgentByID(FlagAgent *Liste,unsigned int ID)
{

    return GetAgent(Liste, GetIndexAgent(Liste, ID));

}
