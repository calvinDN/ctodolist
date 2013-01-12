/********************************************
* File Name : todoListManager.c
* Purpose : Implementation of Assignment 3 specifications
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 09:49:34 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todoInterface.h"
#include "priorityQueue.h"
#include "inputInterface.h"

#define TRUE 1
#define FALSE 0
#define MAX_MENU_INPUT 20

int main (int argc, char *argv[])
{
    /*
     *  VARIABLE DECLARATIONS
     */
    FILE *fp;                           /* file pointer to input file */
    char buffer[100];                   /* buffer for input from file and user */
    dataNode *newEntry;                 /* a pointer to the information about to be used in the priority queue */
    int firstRun = TRUE;                /* prints instructions for add only the first time they open it, unless they make a mistake */
    int quit = FALSE;                   /* flag to quit the command loop and exit the program */
    char menuInput[MAX_MENU_INPUT];     /* input from user for menu selections */
    priorityQ *PQ;                      /* priority queue which provides the main functionality of the to do list manager */

    /*
     *  COMMAND LINE ARGUEMENTS
     */
    if ( argc != 2 )
    {
        printf("usage: %s filename", argv[0]);
    }
    else
    {
        fp = fopen(argv[1], "r");
        if ( fp == 0 )
        {
            printf("Could not open file\n");
        }
    }

    PQ = createPQ(compareToDo, copyToDo, destroyToDo);

    /*
     *  FILE INPUT
     */
    while (fgets(buffer, 100, fp) != NULL)
    {
        newEntry = newDataNode();
        cleanInputLine(buffer); /* cuts newline if necessary */
        dataNodeFileInput(newEntry, buffer); /* parses and stores line into a dataNode */

        /* if an acceptable values has not yet been entered, default to 100 */
        newEntry->priority = verifyPriority(newEntry->priority);

        enqueue(PQ, newEntry);
    }
    fclose(fp);

    /*
     *  USER INPUT
     */
    printf(" <<< To Do List Program >>> \n");
    do /* main program loop */
    {
        printf("  Current List :\n");
        printf("     PRIORITY | ACTIVITY\n");
        printPQ(PQ, printToDo);

        do /* user input loop */
        {
            printf("[1] Add\n");
            printf("[2] Remove\n");
            printf("[3] Quit\n > ");
            takeInput(menuInput, MAX_MENU_INPUT);
        } while (numberSelection(menuInput, "3") == FALSE);

        switch (menuInput[0])
        {
            /* Add */
            case '1':
                do
                {
                    if (firstRun == TRUE)
                    {
                        firstRun = FALSE;
                        printf("Enter an activity and its priority (1-100) ex.\"watch_starwars 4\"\n");
                        printf("priorities range from 1 to 100. They are also optional.\n");
                    }
                    else
                    {
                        printf("Enter an activity and its priority.\n");
                    }
                    printf(" > ");
                    fgets(buffer, 100, stdin);

                    if (buffer[0] == '\n')
                    {
                        firstRun = TRUE;
                    }
                } while (buffer[0] == '\n');

                /* same process as file input */
                newEntry = newDataNode();
                cleanInputLine(buffer);
                dataNodeFileInput(newEntry, buffer);
                newEntry->priority = verifyPriority(newEntry->priority);
                enqueue(PQ, newEntry);
            break;

            /* Remove */
            case '2':
                dequeue(PQ);
            break;

            /* Quit */
            case '3':
                quit = TRUE;
            break;
        }

    } while(quit == FALSE);

    /*
     *  CLEAN UP
     */
    destroyPQ(PQ);

    return EXIT_SUCCESS;
}

