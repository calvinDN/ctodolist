/********************************************
* File Name : balancedTree.h
* Purpose : Inferface for Tree functions
* Creation Date : 11-24-2012
* Last Modified : Wed 28 Nov 2012 05:24:31 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include "Tree.h"

/*********************************************************************
* function name: createTree
* purpose: return a pointer to the space needed for a Tree
*          saves the function pointers in the tree
* preconditions: pointers to compare, copy and destroy functions.
* postconditions: a Tree.
* notes: .
*********************************************************************/
Tree * createTree( int(*compare)(void *, void *), int(*copy)(void *), void(*destroy)(void *) );

/*********************************************************************
* function name: insert
* purpose: wrapper function for insertNode.
* preconditions: a Tree and a void pointer.
* postconditions: Tree is larger.
* notes: .
*********************************************************************/
void insert(Tree *T, void *data);

/*********************************************************************
* function name: inorder
* purpose: Print the tree in order.
* preconditions: a Tree, a print function.
* postconditions: none.
* notes: .
*********************************************************************/
void inorder(struct treeNode *T, void(*print)(void *data));

/*********************************************************************
* function name: preorder
* purpose: print the tree in pre order
* preconditions: a Tree, a print function.
* postconditions: none.
* notes: .
*********************************************************************/
void preorder(struct treeNode *T, void(*print)(void *data));

/*********************************************************************
* function name: findHeight
* purpose: returns the height of the tree.
* preconditions: a Tree.
* postconditions: a Height.
* notes: Included for tTest.c.
*********************************************************************/
int findHeight(struct treeNode *T);

/*********************************************************************
* function name: heightDifference
* purpose: returns the difference of height of the left and right subtrees.
* preconditions: a Tree.
* postconditions: a difference of Height.
* notes: Included for tTest.c.
*********************************************************************/
int heightDifference(struct treeNode *T);

/*********************************************************************
* function name: prettyPreorder
* purpose: print a visual representation of a tree.
* preconditions: a Tree, a print function.
* postconditions: none.
* notes: .
*********************************************************************/
void prettyPreorder(struct treeNode *T, int depth, void(*print)(void *data));

/*********************************************************************
* function name: minValueNode
* purpose: returns the smallest node from the tree.
* preconditions: a Tree.
* postconditions: none.
* notes: .
*********************************************************************/
struct treeNode * minValueNode(struct treeNode *node);

/*********************************************************************
* function name: maxValueNode
* purpose: returns the largest node from the tree.
* preconditions: a Tree.
* postconditions: none.
* notes: .
*********************************************************************/
struct treeNode * maxValueNode(struct treeNode *node);

/*********************************************************************
* function name: removeRoot
* purpose: delete the root from the tree.
* preconditions: a Tree.
* postconditions: a smaller tree.
* notes: .
*********************************************************************/
void removeRoot(Tree *T);

/*********************************************************************
* function name: destroyTree
* purpose: free the entire tree.
* preconditions: a Tree.
* postconditions: no tree.
* notes: may only be called once per tree.
*********************************************************************/
void destroyTree(Tree *T);