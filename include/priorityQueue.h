/********************************************
* File Name : priorityQueue.h
* Purpose : Interface for Priority Queue Functions
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 07:24:31 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include "balancedTree.h"
#include "priorityQNode.h"

/*********************************************************************
* function name: createPQ
* purpose: return a pointer to space for a priority queue
* preconditions: pointers to compare, copy and destroy functions.
* postconditions: a priority queue.
* notes: .
*********************************************************************/
priorityQ * createPQ(int(*compare)(void * data1, void * data2), int(*copy)(void *), void(*destroy)(void *));

/*********************************************************************
* function name: enqueue
* purpose: add an item to the priority queue
* preconditions: a priority queue and a void pointer.
* postconditions: a larger priority queue.
* notes: .
*********************************************************************/
void enqueue(priorityQ * Q, void *data);

/*********************************************************************
* function name: printPQ
* purpose: Print the priority queue in order.
* preconditions: a priorityQ, a print function.
* postconditions: none.
* notes: .
*********************************************************************/
void printPQ(priorityQ * Q, void(*print)(void *data));

/*********************************************************************
* function name: dequeue
* purpose: Removes the root from the priority queue.
* preconditions: a priorityQ.
* postconditions: a smaller priorityQ.
* notes: .
*********************************************************************/
void dequeue(priorityQ * Q);

/*********************************************************************
* function name: destroyPQ
* purpose: free the priority queue.
* preconditions: a priority queue.
* postconditions: no priority queue.
* notes: may only be called once per queue.
*********************************************************************/
void destroyPQ(priorityQ * Q);