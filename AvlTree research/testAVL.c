#include <stdio.h>
#include "avl_tree.h"


/**
 * Doing testing on the AVL tree. 
*/
int main() {
    // Test insert
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the constructed AVL tree: ");
    inorder(root);
    printf("\n");

    // Test deletion
    root = deletion(root, 20);
    printf("Inorder traversal after deletion of 20: ");
    inorder(root);
    printf("\n");

    // Test preorder
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    // Test postorder
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

