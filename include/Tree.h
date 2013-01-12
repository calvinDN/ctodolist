/********************************************
* File Name : Tree.h
* Purpose : definition of a Tree
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 07:24:31 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include "treeNode.h"

typedef struct AvlTree
{
    struct treeNode * root;

    int (* compareptr) (void *, void *);
    int (* copyptr) (void *);
    void (* destroyptr) (void *);

}Tree;
