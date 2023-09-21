#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl_tree.h"

int main() {
    int num_iterations = 20;
    int num_insertions = 100000;

    srand(time(NULL)); // Seed the random number generator with the current time.

    for (int i = 0; i < num_iterations; i++) {
        Node *root = NULL;
        rotation_counter = 0;
        int search_counter = 0;

        // Insert random data into the AVL tree and record the time.
        clock_t start_insert = clock();
        for (int j = 0; j < num_insertions; j++) {
            int random_val = rand() % (num_insertions * 10);
            root = insert(root, random_val);
        }
        clock_t end_insert = clock();

        // Search for random data in the AVL tree and record the number of searches.
        for (int j = 0; j < num_insertions; j++) {
            int random_val = rand() % (num_insertions * 10);
            if (searchForNode(root, random_val)) {
                search_counter++;
            }
        }

        // Delete random data from the AVL tree and record the time.
        clock_t start_delete = clock();
        for (int j = 0; j < num_insertions; j++) {
            int random_val = rand() % (num_insertions * 10);
            root = deletion(root, random_val);
        }
        clock_t end_delete = clock();

        double insert_time = (double)(end_insert - start_insert) / CLOCKS_PER_SEC;
        double delete_time = (double)(end_delete - start_delete) / CLOCKS_PER_SEC;

        printf("Iteration %d:\n", i + 1);
        printf("  Insertion time: %.4f seconds\n", insert_time);
        printf("  Deletion time: %.4f seconds\n", delete_time);
        printf("  Number of rotations: %d\n", rotation_counter);
        printf("  Number of search operations: %d\n", search_counter);
    }

    return 0;
}

