/** Implementation of BST utility functions
 *
 *  @author YOUR NAME
 * Semester YOUR SEMESTER
 *
*/


#include "my_bst_util.h"

/**
 * Returns the sum of all the values in the tree.
*/
int sum_helper(Node* node) {
    if (node == NULL) return 0;
    return node->data + sum_helper(node->left) + sum_helper(node->right);
}

int sum(BST *tree) {
    if ((tree == NULL) || (tree->root == NULL)) return 0;
    return sum_helper(tree->root);
}

/**
 * Returns the minimum value in the tree. 
*/
int min_helper(Node* node) {
    if (node == NULL) {
        return __INT_MAX__;
    }
    int leftmin = min_helper(node->left);
    int rightmin = min_helper(node->right);
    
    if (node->data < rightmin && node->data <leftmin) return node->data;
    else if (rightmin > leftmin) return leftmin;
    else return rightmin;
}

int min(BST *tree) {
    if (tree == NULL || tree->root == NULL) {
        return __INT_MAX__;
    }
    return min_helper(tree->root);
}

/**
 * Returns the maximum value in the tree.
*/
int max_helper(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left_max = max_helper(node->left);
    int right_max = max_helper(node->right);
    if (node->data > left_max && node->data > right_max) {
        return node->data;
    }
    else if (left_max > right_max) {
        return left_max;
    }
    else {
        return right_max;
    }
}

int max(BST *tree) {
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }
    return max_helper(tree->root);
}