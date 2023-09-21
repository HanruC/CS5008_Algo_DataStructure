/** Implementation of the BST data structure 
 * 
 * @author YOUR NAME
 * Semester YOUR SEMESTER
*/

#include "my_bst.h"


/**
 * Checks to see if the tree is empty
 * by looking at the tree size.
 * returns true if the tree is empty.
 * False otherwise.
*/
bool bst_is_empty(BST *tree) {
    if (tree == NULL) return false;
    if (tree->size == 0) return true;
    return false;
}

/**
 * Checks to see if the value exists in the tree.
 * returns true if the value exists in the tree.
 * False otherwise.
*/
int bst_exists_helper(Node* node, int value) {
    if (node == NULL) return 0;
    if (node->data == value) return 1;
    return bst_exists_helper(node->left,value) || bst_exists_helper(node->right, value);
}

bool bst_exists(BST *tree, int value)
{
    if (tree == NULL) return false;
    if (tree->root == NULL) return false;
    
    if (bst_exists_helper(tree->root,value) == 1) return true;
    return false;
}

/**
 * Returns the size of the tree.
*/
unsigned int bst_size(BST *tree) {
    if (tree == NULL) return -1;
    return tree->size;
}

/**
 * Adds a value to the tree.
 * returns 1 if the value was added successfully.
 * returns 0 if the value already exists in the tree.
 * returns -1 if the value could not be added due to errors. (malloc failed)
*/
int add_helper(Node* node, Node* newNode) {
    if (node == NULL) {
        node = newNode;
        return 1;
    }
    if (node->data > newNode->data) {
        if (node->left == NULL) {
            node->left = newNode;
            return 1;
        } else {
            add_helper(node->left,newNode);
        }
    } else if (node->data < newNode->data) {
        if (node->right == NULL) {
            node->right = newNode;
            return 1;
        } else {
            add_helper(node->right,newNode);
        }
    } 
    return 0;
}

int bst_add(BST *tree, int value) {
    if (tree == NULL) return -1;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = value;
    if (tree->root == NULL) {
        tree->root = newNode;
        tree->size++;
        return 1;
    } 
    if (add_helper(tree->root, newNode) == 1) {
        tree->size++;
        return 1;
    }
        
    return 0;
}


/**
 * Frees the memory allocated for the tree.
 * hint: Think about which order works for traversal (pre, in, post) and how that
 * can help you free the memory
*/
void free_helper(Node* node) {
    if (node == NULL) {
        return;
    } 
    free_helper(node->left);
    free_helper(node->right);
    free(node);
}

void bst_free(BST *tree) {
    if (tree == NULL) return;
    free_helper(tree->root);
    free(tree);
    
}



/**
 * Creates a new BST.
 * returns a pointer to the new BST.
 * The root node will still be NULL until the first bst_add is called
*/
BST *create_bst() {

    BST *newTree = (BST*)malloc(sizeof(BST));
    if (newTree) {
        newTree->root = NULL;
        newTree->size = 0;
    } 
    return newTree;
}