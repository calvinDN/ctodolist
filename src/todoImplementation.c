/********************************************
* File Name : todoImplementation.c
* Purpose : Implementation of functions specific to the dataNode filetype
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 09:49:34 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "todoInterface.h"
#include "treeNode.h"

int compareToDo (void *data1, void *data2)
{
    int value;
    dataNode *d1, *d2;
    d1 = (dataNode *) data1;
    d2 = (dataNode *) data2;

    value = d2->priority - d1->priority;
    if (value != 0)
    {
        return value;
    }
    else
    {
        return strcmp(d2->activity, d1->activity);
    }

    return 0;
}

int copyToDo (void * cpy)
{
    return 0;
}

/* function that calls this should free their pointer and set it to NULL */
void destroyToDo (void *node)
{
    dataNode *data = (dataNode *)node;
    free(data->activity);
    free(data);
}

void printToDo (void *node)
{
    dataNode *data = (dataNode *)node;
    printf("          %3d | %s \n", data->priority, data->activity);
}

dataNode * newDataNode()
{
    dataNode * new = malloc(sizeof(dataNode));
    new->priority = -1;
    new->activity = NULL;
    return new;
}

void dataNodeFileInput(dataNode *newEntry, char *buffer)
{
    int numTokens = 0, i, convert = 1;

    char *token = strtok (buffer," ");

    while (token != NULL && numTokens < 3)
    {
        numTokens++;
        if (numTokens == 1)
        {
            newEntry->activity = malloc(sizeof(char) * (strlen(token)+1));
            strcpy(newEntry->activity, token);
        }
        if (numTokens == 2)
        {
            if(strlen(token) < 4)
            {
                for (i=0; i<strlen(token); i++){
                    if ( token[i] < '0' || token[i] > '9' ){
                        convert = 0;
                        break;
                    }
                }

                if (convert == 1)
                {
                    newEntry->priority = atoi(token);
                }
            }
        }
        else
        {
            /* discard extra tokens*/
        }

        token = strtok (NULL, " ");
    }
}

int verifyPriority(int priority)
{
    if ( (priority < 1) || (priority > 100) )
    {
        return 100;
    }

    return priority;
}

int compareTreeTest (void *data1, void *data2)
{
    dataNode *d1, *d2;
    d1 = (dataNode *) data1;
    d2 = (dataNode *) data2;
    return (d2->priority - d1->priority);
}

void printTestTree (void *node)
{
    dataNode *data = (dataNode *)node;
    printf("          %3d\n", data->priority);
}