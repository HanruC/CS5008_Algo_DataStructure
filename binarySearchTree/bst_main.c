/**
 * Use this file to add your own tests and run a mini BST program.
 *
 * Things to test for...
 *
 * Fill a Binary Search Tree with values 1-100 and searching for nodes
 * Add 100 nodes and then check that the size is 100
 * Add 100 nodes with the value starting at 0 to 99, then check the sum of the tree to be 4950
 * etc...
 * (don't forget to check what happens in the null cases such as trying to find nodes that don't exist,
 * or any action on an empty tree...)
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_bst.h"
#include "my_bst_util.h"


// a helper to get a range  of numbers
int *get_range_array(int start, int end) {
    int *arr = (int*) malloc(sizeof(int) * (end - start));
    int j = 0;
    for (int i = start; i < end; i++, j++) arr[j] = i;
    return arr;
}

// sample helper function to help you create random int arrays
int *get_random_array(int size) {
    int *arr = (int *)malloc(sizeof(int) * size);
    srand(time(NULL)); // seed the random number generator

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

int main(int argc, char const *argv[])
{    
    BST* tree = create_bst();
    bst_add(tree, 4);
    bst_add(tree, 2);
    bst_add(tree, 6);
    bst_add(tree, 1);
    // bst_add(tree, 3);
    // bst_add(tree, 5);
    bst_add(tree, 7);
    bst_print(tree, INORDER);
    printf("\n");
    bst_print(tree, PREORDER);
    printf("\n");
    bst_print(tree, POSTORDER);
    printf("\n");

    int result = bst_exists(tree,3);
    printf("The 0 or 1: %d\n",result);

    int sum_result = sum(tree);
    printf("The sum is : %d\n",sum_result);

    int min_result = min(tree);
    printf("The min is : %d\n",min_result);

    int max_result = max(tree);
    printf("The max is : %d\n",max_result);


    bst_free(tree);
    return 0;
}