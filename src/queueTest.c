/********************************************
* File Name : queueTest.c
* Purpose : Testing for the priority queue
* Creation Date : 11-24-2012
* Last Modified : Wed 28 Nov 2012 05:24:31 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"
#include "inputInterface.h"
#include "todoInterface.h"

#define TRUE 1
#define FALSE 0
#define MAX_MENU_INPUT 20

int main (void)
{
    char buffer[100];
    dataNode *newEntry;
    int quit = FALSE;
    char menuInput[MAX_MENU_INPUT];
    priorityQ *PQ = createPQ(compareToDo, copyToDo, destroyToDo);

    printf(" <<< Priority Queue Test Program >>> \n");
    do
    {
        do
        {
            printf("[1] Add\n");
            printf("[2] Remove\n");
            printf("[3] Quit\n > ");

            takeInput(menuInput, MAX_MENU_INPUT);
        } while (numberSelection(menuInput, "3") == FALSE);

        switch (menuInput[0])
        {
            case '1':
                do
                {
                    printf("Enter an activity and its priority.\n");
                    printf(" > ");
                    fgets(buffer, 100, stdin);

                } while (buffer[0] == '\n');

                newEntry = newDataNode();
                cleanInputLine(buffer);
                dataNodeFileInput(newEntry, buffer);
                newEntry->priority = verifyPriority(newEntry->priority);
                enqueue(PQ, newEntry);
                printf("  Current List :\n");
                printf("     PRIORITY | ACTIVITY\n");
                printPQ(PQ, printToDo);
            break;

            case '2':
                dequeue(PQ);
                printf("  Current List :\n");
                printf("     PRIORITY | ACTIVITY\n");
                printPQ(PQ, printToDo);
            break;

            case '3':
                quit = TRUE;
            break;
        }

    } while(quit == FALSE);

    return 0;
}