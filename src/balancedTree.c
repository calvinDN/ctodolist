/********************************************
* File Name : balancedTree.c
* Purpose : AVL Tree
* Creation Date : 11-23-2012
* Last Modified : Sat 24 Nov 2012 09:52:19 PM EDT
* Created By :  Calvin Nichols  
* References : 1. http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html
*              2. http://www.cprogramming.com/tutorial/c/lesson18.html
*              3. http://www.geeksforgeeks.org/archives/18009
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "balancedTree.h"
#include "todoInterface.h"

/* initialization */
Tree * createTree(int(*compare)(void * data1, void * data2), int(*copy)(void *), void(*destroy)(void *))
{
    Tree * newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    newTree->compareptr = compare;
    newTree->copyptr = copy;
    newTree->destroyptr = destroy;

    return newTree;
}

/* print smallest to largest value */
void inorder(struct treeNode *T, void(*print)(void *data))
{
    if (T == NULL)
    {
        return;
    }
    inorder(T->left, print);
    print(T->data);
    inorder(T->right, print);
}

/* print preorder */
void preorder(struct treeNode *T, void(*print)(void *data))
{
    if (T == NULL)
    {
        return;
    }
    print(T->data);
    preorder(T->left, print);
    preorder(T->right, print);
}

/* return the height of the current tree, helper function */
int findHeight(struct treeNode *T)
{
    int height = 0, leftHeight, rightHeight, maxHeight;

    if (T != NULL)
    {
        leftHeight = findHeight(T->left);
        rightHeight = findHeight(T->right);

        if (leftHeight > rightHeight)
        {
            maxHeight = leftHeight;
        }
        else
        {
            maxHeight = rightHeight;
        }

        height = maxHeight + 1;
    }
    return height;
}

/* return the difference in height of the left and right subtrees */
int heightDifference(struct treeNode *T)
{
    int hLeft, hRight;

    hLeft = findHeight(T->left);
    hRight = findHeight(T->right);

    return (hLeft - hRight);

}

/* right tree is heavy by a height of 1, right right rotation */
struct treeNode * rrRotation(struct treeNode *parent)
/* http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html */
{
    struct treeNode *node = parent->right;
    parent->right = node->left;
    node->left = parent;

    return node;
}

/* left left case */
struct treeNode * llRotation(struct treeNode *parent)
/* http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html */
{
    struct treeNode *node = parent->left;
    parent->left = node->right;
    node->right = parent;
    return node;
}

/* right left case */
struct treeNode * rlRotation(struct treeNode *parent)
/* http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html */
{
    struct treeNode *node = parent->right;
    parent->right = llRotation(node);
    return rrRotation(parent);
}

/* left right case */
struct treeNode * lrRotation(struct treeNode *parent)
/* http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html */
{
    struct treeNode *node = parent->left;
    parent->left = rrRotation(node);
    return llRotation(parent);
}

/* balance a tree on insert */
struct treeNode * treeBalance(struct treeNode *node)
/* http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html */
{
    int hDifference = heightDifference(node);

    if (hDifference > 1)
    {
        if (heightDifference(node->left) > 0)
        {
            node = llRotation(node);
        }
        else
        {
            node = lrRotation(node);
        }
    }
    else if (hDifference < -1)
    {
        if (heightDifference(node->right) > 0)
        {
            node = rlRotation(node);
        }
        else
        {
            node = rrRotation(node);
        }
    }

    return node;
}

/* initialize a leaf */
struct treeNode * initNode(void *data)
{
    struct treeNode * new = malloc(sizeof(struct treeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

/* recursive treenode insert function */
struct treeNode * insertTreeNode(struct treeNode *root, void *data, int(*compare)(void * data1, void * data2))
/* http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html */
{
    if (root == NULL)
    {
        root = initNode(data);
        return root;
    }
    else if (compare(data, root->data) > 0)
    {
        root->left = insertTreeNode(root->left, data, compare);
        root = treeBalance(root);
    }
    else if (compare(data, root->data) < 0)
    {
        root->right = insertTreeNode(root->right, data, compare);
        root = treeBalance(root);
    }
    return root;
}

/* insert wrapper */
void insert(Tree *T, void *data)
{
    T->root = insertTreeNode(T->root, data, T->compareptr);
}

/* print visualization of a tree */
void prettyPreorder(struct treeNode *T, int depth, void(*print)(void *data))
{
    int i;

    if (T == NULL)
    {
        return;
    }

    if (T->left != NULL)
    {
        prettyPreorder(T->left, depth+1, print);
    }
    for (i=0; i<depth; i++)
    {
        printf("    ");
    }
    print(T->data);
    if (T->right != NULL)
    {
        prettyPreorder(T->right, depth+1, print);
    }
}

/* return the smallest treeNode */
struct treeNode * minValueNode(struct treeNode *node)
{
    struct treeNode *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

/* return the largest treeNode */
struct treeNode * maxValueNode(struct treeNode *node)
{
    struct treeNode *current = node;

    while (current->right != NULL)
    {
        current = current->right;
    }

    return current;
}

/* remove a treeNode */
struct treeNode * removeNode(struct treeNode *root, void *data, int(*compare)(void * data1, void * data2), void(*destroy)(void *))
/* http://www.geeksforgeeks.org/archives/18009 */
{

    struct treeNode *temp;

    if (root == NULL)
    {
        return root;
    }

    if (compare(data, root->data) > 0)
    {
        root->left = removeNode(root->left, data, compare, destroy);
    }
    else if (compare(data, root->data) < 0)
    {
        root->right = removeNode(root->right, data, compare, destroy);
    }
    else
    {
        /* delete root */
        if ( (root->left == NULL) || (root->right == NULL) )
        {
            if (root->left != NULL)
            {
                temp = root->left;
            }
            else
            {
                temp = root->right;
            }

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else /* one child case */
            {
                *root = *temp;
            }

            /*destroy(temp->data);*/
            free(temp);
        }
        else
        {
            temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data, compare, destroy);
        }
    }

    if (root == NULL)
    {
        return root;
    }

    /* need to fix balancing */
    /* treeBalance(root); */

    return root;
}

/* wrapper that forces removal of the smallest node, dequeue */
void removeRoot(Tree *T)
{
    if (T->root != NULL)
    {
        struct treeNode *node = minValueNode(T->root);
        T->root = removeNode(T->root, node->data, T->compareptr, T->destroyptr);
    }
}

/* free all nodes in the tree and then the tree itself */
void destroyTree(Tree *T)
{
    while (T->root != NULL)
    {
        struct treeNode *node = minValueNode(T->root);
        T->root = removeNode(T->root, node->data, T->compareptr, T->destroyptr);
    }
    free(T);
}