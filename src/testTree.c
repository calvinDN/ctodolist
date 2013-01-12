/********************************************
* File Name : testTree.c
* Purpose : Testing of AVL Tree Implementation
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 09:49:34 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "balancedTree.h"
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
    int i;
    int convert = TRUE;
    char menuInput[MAX_MENU_INPUT];
    struct treeNode * node;
    Tree *T = createTree(compareTreeTest, copyToDo, destroyToDo);

    printf(" <<< Tree Test Program >>> \n");
    do
    {
        do
        {
            printf("[1] Add\n");
            printf("[2] Remove\n");
            printf("[3] maxNode\n");
            printf("[4] minNode\n");
            printf("[5] treeHeight\n");
            printf("[6] Print Pretty Tree\n");
            printf("[7] Print PreOrder\n");
            printf("[8] Print InOrder\n");
            printf("[9] Quit\n > ");

            takeInput(menuInput, MAX_MENU_INPUT);
        } while (numberSelection(menuInput, "9") == FALSE);

        switch (menuInput[0])
        {
            case '1':
                do
                {
                    printf("Enter a number to insert.\n");
                    printf(" > ");
                    fgets(buffer, 100, stdin);

                } while (buffer[0] == '\n');

                cleanInputLine(buffer);

                /* could make this a function and use it in the datanode input as well... */
                for (i=0; i<strlen(buffer); i++){
                    if ( buffer[i] < '0' || buffer[i] > '9' ){
                        convert = FALSE;
                        break;
                    }
                }

                if (convert == TRUE)
                {
                    newEntry = newDataNode();
                    newEntry->priority = atoi(buffer);
                    insert(T, newEntry);
                }
                else
                {
                    printf("Input unacceptable\n");
                }

                printf("  Current List :\n");
                inorder(T->root, printTestTree);
            break;

            case '2':
                removeRoot(T);
                printf("  Current List :\n");
                inorder(T->root, printTestTree);
            break;

            case '3':
                node = maxValueNode(T->root);
                printTestTree(node->data);
            break;

            case '4':
                node = minValueNode(T->root);
                printTestTree(node->data);
            break;

            case '5':
                printf("height: %d\n", findHeight(T->root));
            break;

            case '6':
                prettyPreorder(T->root, 0, printTestTree);
            break;

            case '7':
                preorder(T->root, printTestTree);
            break;

            case '8':
                inorder(T->root, printTestTree);
            break;

            case '9':
                quit = TRUE;
            break;
        }

    /* Reset Variables */
    convert = TRUE;

    } while(quit == FALSE);

    return 0;
}