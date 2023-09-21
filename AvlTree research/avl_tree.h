#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int rotation_counter;

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node* createNode(int val);
int getHeight(Node* node);
int getBalanceFactor(Node* node);
Node *rightRotate(Node *parent);
Node *leftRotate(Node *parent);
Node* check_rotation(Node* node, int val);
Node* insert(Node* node, int val);
Node* findMin(Node* node);
Node* helper_DeleteSingleOrNoNode (Node* root);
Node* deletion(Node* root, int val);
void inorder(Node* node);
void preorder(Node* node);
void postorder(Node* node);
int searchForNode(Node *root, int val);

#endif
