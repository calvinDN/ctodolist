/********************************************
* File Name : treeNode.h
* Purpose : definition of struct treeNode
* Creation Date : 11-24-2012
* Last Modified : Sun 25 Nov 2012 07:24:31 PM EDT
* Created By :  Calvin Nichols  
********************************************/

struct treeNode
{
    void *data;

    struct treeNode *right;
    struct treeNode *left;
};