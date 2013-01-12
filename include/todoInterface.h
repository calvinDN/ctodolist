/********************************************
* File Name : todoInterface.h
* Purpose : Interface for functions specific to the dataNode filetype
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 09:49:34 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include "todoNode.h"

/*********************************************************************
* function name: compareToDo
* purpose: compare two dataNodes.
* preconditions: Two dataNodes.
* postconditions: A value representing the comparison of the two dataNodes
* notes: .
*********************************************************************/
int compareToDo (void *data1, void *data2);

/*********************************************************************
* function name: compareTreeTest
* purpose: compare two dataNodes for the tree test, onlt uses ints.
* preconditions: Two dataNodes.
* postconditions: A value representing the comparison of the two dataNodes
* notes: .
*********************************************************************/
int compareTreeTest (void *data1, void *data2);

/*********************************************************************
* function name: copyToDo
* purpose: copy a dataNode.
* preconditions: a dataNode.
* postconditions: .
* notes: .
*********************************************************************/
int copyToDo (void * cpy);

/*********************************************************************
* function name: destroyToDo
* purpose: destroy a dataNode.
* preconditions: a dataNode.
* postconditions: a dangling pointer.
* notes: .
*********************************************************************/
void destroyToDo (void *node);

/*********************************************************************
* function name: printToDo
* purpose: print a dataNode.
* preconditions: a dataNode.
* postconditions: a string in standard out.
* notes: .
*********************************************************************/
void printToDo (void *data);

/*********************************************************************
* function name: printTestTree
* purpose: print a dataNode for the tree test, only uses ints.
* preconditions: a dataNode.
* postconditions: a string in standard out.
* notes: .
*********************************************************************/
void printTestTree (void *node);

/*********************************************************************
* function name: newDataNode
* purpose: initialize a new dataNode.
* preconditions: none.
* postconditions: an initialized dataNode.
* notes: .
*********************************************************************/
dataNode * newDataNode();

/*********************************************************************
* function name: dataNodeFileInput
* purpose: read in a dataNode from file and verify its contents.
* preconditions: a file containing dataNodes.
* postconditions: an appropriate dataNode containing the file contents.
* notes: .
*********************************************************************/
void dataNodeFileInput(dataNode *node, char *fileLine);

/*********************************************************************
* function name: verifyPriority
* purpose: ensure an acceptable priority.
* preconditions: a priority.
* postconditions: a verified priority.
* notes: .
*********************************************************************/
int verifyPriority(int priority);