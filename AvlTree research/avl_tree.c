#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl_tree.h"

int rotation_counter = 0;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getHeight(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

/**
 * Max - return the maximum of two integers. 
*/
int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Right Rotation - perform a right rotation on the given subtree rooted at node.
 * The right rotation method is used to maintain the balance of the tree during insertion and deletion.
*/
Node *rightRotate(Node *parent) {
    // Assign leftChild as the left child of the parent node.
    Node *leftChild = parent->left;
    
    // Assign rightSubtree as the right child of the leftChild node.
    Node *rightSubtree = leftChild->right;
    
    // Update the right child of the leftChild node to be the parent node.
    leftChild->right = parent;// Moves the parent node down one level to the right of the leftChild.
    
    // Update the left child of the parent node to be the rightSubtree node.
    parent->left = rightSubtree;// RightSubtree node becomes the left child of the parent node as it moves down one level.
    
    // Update the height of the parent node based on the maximum height of its left and right children plus one.
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    
    // Update the height of the leftChild node based on the maximum height of its left and right children plus one.
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;
    return leftChild;// Return the leftChild node as the new root of the rotated subtree.
}

/**
 * Left Rotation - perform a left rotation on the given subtree rooted at node. 
*/
Node *leftRotate(Node *parent) {
    // Assign rightChild as the right child of the parent node.
    Node *rightChild = parent->right;
    
    // Assign leftSubtree as the left child of the rightChild node.
    Node *leftSubtree = rightChild->left;
    
    // Update the left child of the rightChild node to be the parent node.
    rightChild->left = parent;// Moves the parent node down one level to the left of the rightChild.
    
    // Update the right child of the parent node to be the leftSubtree node.
    parent->right = leftSubtree;// LeftSubtree node becomes the right child of the parent node as it moves down one level.
    
    // Update the height of the parent node based on the maximum height of its left and right children plus one.
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    
    // Update the height of the rightChild node based on the maximum height of its left and right children plus one.
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;
    // Return the rightChild node as the new root of the rotated subtree.
    return rightChild;
}

/**
 * Check Rotation for insertion - check if the subtree rooted at node is balanced and perform rotations if necessary. 
*/
Node* check_rotation_insert(Node* node, int val) {
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1 && val < node->left->val) {
        rotation_counter++;
        return rightRotate(node); // right rotation
    }
    
    if (balanceFactor < -1 && val > node->right->val) {
        rotation_counter++;
        return leftRotate(node); // left rotation
    }

    if (balanceFactor > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        rotation_counter++;
        return rightRotate(node);
    }

    if (balanceFactor < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        rotation_counter++;
        return leftRotate(node);
    }
    return node;
}

/**
 * Check Rotation for deletion - check if the subtree rooted at node is balanced and perform rotations if necessary.
*/
Node* check_rotation_delete(Node* node) {
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
        rotation_counter++;
        return rightRotate(node); // right rotation
    }
    
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
        rotation_counter++;
        return leftRotate(node); // left rotation
    }

    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        rotation_counter++;
        return rightRotate(node);
    }

    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        rotation_counter++;
        return leftRotate(node);
    }
    return node;
}


/**
 * Insert - insert a new node with the given key into the subtree rooted at node.
 * The insert method is used to insert a new node into the tree.
 * left-right: C(2)          C               B(0)                 right-left:      A        A           B
 *            /             /               / \                                     \        \         / \
 *           A(1)    ->    B       ->      A(0)   C(0)                               C   ->   B   ->  A   C
 *            \           /                                                         /          \      
 *             B(0)      A                                                         B            C
*/           
Node* insert(Node* node, int val) {
    if (node == NULL) return createNode(val);
    if (val < node->val) node->left = insert(node->left, val);
    else if (val > node->val) node->right = insert(node->right, val);
    else return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return check_rotation_insert(node, val); // call helper to check rotation. 
}

/**
 * Find the smallest node in the subtree rooted at node.
*/
Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != NULL) current = current->left; //find the leftmost leaf node. 
    return current;
}

/**
 * Deletion helper with deleting a node with no or one child. 
*/
Node* helper_DeleteSingleOrNoNode (Node* root) {
    Node* temp;
    if (root->left != NULL) temp = root->left;
    else temp = root->right;

    if (temp == NULL) {
        temp = root;
        root = NULL;
    }
    else *root = *temp;
    free(temp);
    return root; 

}

/**
 * Delete method. 
*/
Node* deletion(Node* root, int val) {
    if (root == NULL) return root;
    if (val < root->val) root->left = deletion(root->left, val);
    else if (val > root->val) root->right = deletion(root->right, val);
    else {
        if ((root->left == NULL) || (root->right == NULL)) root = helper_DeleteSingleOrNoNode(root);
        else {
            Node* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deletion(root->right, temp->val);
        }
    }

    if (root == NULL) return root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return check_rotation_delete(root);
}

/**
 * Inorder traversal - print the inorder traversal of the subtree rooted at node.
*/
void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

/**
 * Preorder traversal - print the preorder traversal of the subtree rooted at node.
*/
void preorder(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->val);
    preorder(node->left);
    preorder(node->right);
}

/**
 * Postorder traversal - print the postorder traversal of the subtree rooted at node.
*/
void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->val);
}

/**
 * Search for a node with the given value in the subtree rooted at node. 
*/
int searchForNode(Node *root, int val) {
    if (root == NULL) return 0;
    if (root->val == val) return 1;
    if (val < root->val) return searchForNode(root->left, val);
    else return searchForNode(root->right, val);
}

/**
 * Perform search.
 * Generates random integer values and performs search operations for those values in the AVL tree. 
*/
void doSearch(Node *root, int num_search) {
    srand(time(NULL));
    int found = 0;
    for (int i = 0; i < num_search; i++) {
        int val = rand() % (num_search * 2);
        if (searchForNode(root, val)) found++;
    }
    printf("Number of successful searches: %d\n", found);
}

/**

int main() {
    Node* root = NULL;
    int initial_nodes = 10; // Number of nodes for the existing AVL tree
    int additional_nodes = 1000; // Number of additional nodes to insert

    // Create the initial AVL tree with random values
    unsigned int seed = time(NULL);
    for (int i = 0; i < initial_nodes; i++) {
        int val = rand_r(&seed);
        root = insert(root, val);
    }

    // Reset the rotation counter
    rotation_counter = 0;

    // Insert additional nodes in ascending order to cause more rotations
    for (int i = 1; i <= additional_nodes; i++) {
        root = insert(root, i);
    }

    printf("Number of rotations during additional insertions: %d\n", rotation_counter);
    return 0;
}*/







