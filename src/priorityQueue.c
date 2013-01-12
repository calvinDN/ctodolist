/********************************************
* File Name : priorityQueue.c
* Purpose : Implementation of Priority Queue Functions
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 07:24:31 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "priorityQueue.h"

/* initialize a priority queue and return it */
priorityQ * createPQ(int(*compare)(void * data1, void * data2), int(*copy)(void *), void(*destroy)(void *))
{
    priorityQ * newQ = malloc(sizeof(priorityQ));
    newQ->tree = createTree(compare, copy, destroy);
    return newQ;
}

/* add an entry to the tree */
void enqueue(priorityQ *Q, void *data)
{
    if (Q->tree != NULL)
    {
        insert(Q->tree, data);
    }
}

/* inorder print */
void printPQ(priorityQ *Q, void(*print)(void *data))
{
    if (Q->tree->root != NULL)
    {
        inorder(Q->tree->root, print);
    }
    else
    {
        printf("     List is Empty!\n");
    }
}

/* preorder print */
void preorderPQ(priorityQ *Q, void(*print)(void *data))
{
    if (Q->tree->root != NULL)
    {
        preorder(Q->tree->root, print);
    }
}

/* pretty print of the tree */
void prettyPQ(priorityQ *Q, void(*print)(void *data))
{
    if (Q->tree->root != NULL)
    {
        prettyPreorder(Q->tree->root, 0, print);
    }
}

/* delete the smallest node */
void dequeue(priorityQ *Q)
{
    if (Q->tree->root != NULL)
    {
        removeRoot(Q->tree);
    }
}

/* clean up */
void destroyPQ(priorityQ * Q)
{
    if (Q->tree->root != NULL)
    {
        destroyTree(Q->tree);
    }
    free(Q);
}