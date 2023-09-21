# Research Paper
Name: Hanru Chen 

Semester: Spring 2023

Topic: AVL Tree Research Paper

Link The Repository: https://github.com/Spring23-CS5008-BOS-Lionelle/research-project-HanruC.git

## Introduction
- Brief introduction: This research paper provides an overview and detailed knowledge about the AVL tree data structure. An AVL tree is a self-balancing binary search tree that maintains the height balance property of a binary search tree. In an AVL tree, the height of the left and right subtrees should not differ by more than 1. Generally speaking, AVL trees solve the problem of maintaining the height balance of a binary search tree, which ensures efficient search, deletion, and insertion operations. 

- History: According to the research, "an AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree. It was the first such data structure to be invented. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property." "The AVL tree is named after its two Soviet inventors, Georgy Adelson-Velsky and Evgenii Landis, who published it in their 1962 paper "An algorithm for the organization of information. " 
Reference: John Smith. 2021. AVL Tree. In Wikipedia. [Online]. Retrieved April 14, 2023, from https://en.wikipedia.org/wiki/AVL_tree

- Main topics: In this research paper, I am going to provide the importance of AVL tree in computer science area, basic analysis of AVL (mostly analyzing through codes), empirical analysis, and also the application of AVL tree.  



## Analysis of Algorithm/Datastructure 

[AVL Tree Code]
- Time complexity: 

    | Insertion | Deletion | Search |
    |-----------|:---------|:-------|
    | $O(log(n))$ | $O(log(n))$ | $O(log(n))$ |
    
    - *Insertion*: The insertion function performs the operation of inserting a new node into the AVL tree. The time complexity of insertion is     $O(log(n))$ where n is the number of nodes in the AVL tree. The reason why it is $O(log(n))$ is that the AVL tree maintains balance, which we call the balance factor. In the code, I provide a method called getBalanceFactor which takes the tree node as a parameter to calculate the balance factor. The balance factor should be calculated as the difference between the heights of the left subtree and the right subtree. In raw math, it can be shown as: BalanceFactor = height(left-subtree) - height(right-subtree).
    ```c
    int getBalanceFactor(Node* node) {
        if (node == NULL) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    ```

    The main reason why the Big O for insertion is O(log n) is that the AVL tree maintains height balance, ensuring that the left and right subtrees of any node differ by at most 1. This property ensures that the AVL tree remains balanced. When a new node is inserted into the AVL tree, the search for the correct position follows the fixed height of the tree. Therefore, the height is always logarithmic to the number of nodes. Even if the tree becomes unbalanced after insertion, the rotation operations only take O(1) time, as shown in the code below.
    ```c
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
        r   eturn leftRotate(node);
        }
        return node;
    }
    ```
    The insertion method is shown below: 
    ```c
    Node* insert(Node* node, int val) {
        if (node == NULL) return createNode(val);
        if (val < node->val) node->left = insert(node->left, val);
        else if (val > node->val) node->right = insert(node->right, val);
        else return node;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        return check_rotation_insert(node, val); // call helper to check rotation. 
    }
    ```
    - *Deletion*: The deletion method basically performs the operation of removing a node from the AVL tree. Similar to insertion, the deletion operation also has a time complexity of $O(log(n))$, as it uses recursion to follow the tree's height. Because the AVL tree is well-balanced, with a balance factor no more than 1, the deletion process remains $O(log(n))$.
    ```c
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

    Node* deletion(Node* root, int val) {
        if (root == NULL) return root;
        if (val < root->val) root->left = deletion(root->left, val);
        else if (val > root->val) root->right = deletion(root->right, val);
        lse {
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
    ```
    - *Search*: The searching process has the same time complexity of insertion and deletion since the searching process is also needed 
    in deletion and insertion. Searching time complexity is also $O(log(n))$ since the tree heights are maintained, and the searching process 
    will follow the height. 

- Space Complexity: 
The space complexity of AVL is $O(n)$ since the number of nodes in the tree determines the space complexity. AVL tree with n nodes has $n - 1$ edges. Therefore, the total nodes and edges in the tree is $2n - 1$. Thus, the space complexity is $O(n)$.

-Traversal process: Inorder, preorder, and postorder The traversal process has a time complexity of $O(n)$ since they need to visit every node in the tree once. The space complexity, therefore, is $O(n)$ since all nodes need to be stored. However, since it is an AVL tree where the height is balanced, the space complexity of recursive traversals should be $O(log(n))$. 

Reference: 
Edleno S. de Moura, Gonzalo Navarro, and Nivio Ziviani. 2000. Expected Behaviour Analysis of AVL Trees. Algorithmica 27, 3-4 (2000), 367-381. 
L. Wang, Y. Zhang, and Z. Huang, "A Tale of Two Trees: New Analysis for AVL Tree and Binary Heap," ResearchGate, October 2020. [Online]. Available: https://www.researchgate.net/publication/344622226_A_Tale_of_Two_Trees_New_Analysis_for_AVL_Tree_and_Binary_Heap

## Empirical Analysis

| Iteration | Insertion Time (s) | Deletion Time (s) | Rotations | Search Operations |
|-----------|:--------------------|:-------------------|:-----------|:------------------|
| 1         | 0.1100             | 0.1300            | 46734     | 9522             |
| 2         | 0.0800             | 0.0700            | 46605     | 9610             |
| 3         | 0.0700             | 0.0700            | 46491     | 9479             |
| 4         | 0.0700             | 0.0800            | 46641     | 9507             |
| 5         | 0.0700             | 0.0800            | 46778     | 9463             |
| 6         | 0.0700             | 0.0800            | 46770     | 9488             |
| 7         | 0.0600             | 0.0800            | 46553     | 9557             |
| 8         | 0.0700             | 0.0800            | 46707     | 9542             |
| 9         | 0.0700             | 0.0700            | 46696     | 9566             |
| 10        | 0.1200             | 0.0900            | 46828     | 9543             |
| 11        | 0.0800             | 0.0700            | 46784     | 9524             |
| 12        | 0.0700             | 0.0800            | 46531     | 9587             |
| 13        | 0.0700             | 0.0800            | 47060     | 9485             |
| 14        | 0.0700             | 0.0700            | 46795     | 9340             |
| 15        | 0.0700             | 0.0800            | 46925     | 9575             |
| 16        | 0.0800             | 0.0800            | 46903     | 9525             |
| 17        | 0.0700             | 0.0700            | 46979     | 9474             |
| 18        | 0.0700             | 0.0800            | 46879     | 9592             |
| 19        | 0.0700             | 0.0800            | 46688     | 9463             |
| 20        | 0.0600             | 0.0700            | 46636     | 9634             |

According to the table above, we can find that the insertion and deletion times are relatively stable across all iterations. The insertion times range from 0.06 to 0.12, and deletion times range from 0.07 to 0.13. This can indicate that the AVL tree has relatively stable time complexity when inserting and deleting.

Also, the number of rotations performed during insertions and deletions are slightly different, but the numbers do not vary significantly. This shows that the AVL tree performs numerous rotations to maintain its balance.
![time compare]
The number of successful searches is close to 9500 in most iterations. According to the comparison between the rotation and search operations, we can see that the number of rotations is stable, which makes the search operations number also stable. This can indicate that AVL trees are well-balanced and self-balancing trees, which makes the search operations in AVL trees consistent due to their height-balanced nature.
![count compare]

## Application
AVL trees are used for many areas especially when eficient seraching and insertion of data are needed. Here is couple specific examples: 

- First example: In games, particularly story-line games, managing and organizing different paths that a player can take is crucial. An example of such a game is Invisible Guardian on Steam, where players have to make decisions at various points that determine the path of the game. AVL trees can be used to represent different story paths, with each node in the tree representing a decision point. The height-balanced characteristic ensures that each path remains balanced and keeps the game fair. AVL trees can also be used to keep track of a player's progress and offer game hints.

- Second example: File systems also make use of AVL trees for efficient searching and retrieval of files. As file systems need to retrieve files quickly, AVL trees provide a fast, efficient, and robust way to achieve this goal. Each node in the AVL tree can represent a file or directory, with keys stored in any order, such as alphabetical order. As files are added and deleted, the AVL tree can be rebalanced to maintain its efficiency.

- Third example: AVL trees are commonly used in database applications due to their fast search, deletion, and addition time complexity. Since most database systems require frequent data lookup and retrieval, AVL trees are efficient data structures that keep the tree height-balanced, making each operation quick and efficient. Even with an increasing amount of data, AVL trees maintain a time complexity of O(log(n)).

    - A real-life example of the use of AVL trees can be found in the railway system, which uses AVL trees to store information about train schedules, such as departure and arrival times. AVL trees can efficiently search the train schedule and, since they are self-balanced, they maintain their efficiency even when train schedules are added or removed. As train schedules are changed frequently, maintaining efficiency is a critical characteristic. Additionally, the system can use AVL trees to store information about delays, cancellations, or changes, enabling quick updates to passengers.

Reference: Parekh, Heet (2021). "AVL Trees and Its Applications." In Medium. Retrieved April 14, 2023, from https://heet-parekh19.medium.com/avl-trees-and-its-applications-dfc66fae3f16


## Implementation
The language I used is C. In the implementation of code, I used <stdio.h> and <stdlib.h>. The biggest challenge is that I was first confused about
how to write a program to do the empirical analysis. I was trying to add a large number of items to an AVL and record the swap times need to keep 
balanced. 

While attempting to conduct an empirical analysis, the first obstacle I encountered was tracking the rotation times when inserting a large number of nodes in the AVL tree. To address this issue, I modified my code slightly to include a rotation counter for tracking purposes.
```c
if (balanceFactor > 1 && val < node->left->val) {
    rotation_counter++;
    return rightRotate(node); // right rotation
}
    
if (balanceFactor < -1 && val > node->right->val) {
    rotation_counter++;
    return leftRotate(node); // left rotation
}
   ```

Another obstacle is writing a program to test rotation, insertion time, deletion time, and search time. I included the library that can generate random numbers - <time.h>. I also used clock_t to measure processor time. In the code, I employed the clock() function, which returns processor time and stores it in clock_t. Additionally, I utilized a specific method to define the range of random values that will be searched in the AVL tree.
```c
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
```
As the code above, I limit the number to 100000 each time insertion, and the iteration time is 20. 

## Summary
In summary, the AVL tree is a self-balancing binary search tree that maintains the balance factor through rotation operations when nodes are added and deleted. The AVL tree ensures that the height of the tree remains logarithmic in relation to the number of nodes, which makes searching, insertion, and deletion operations efficiently time-complex.

AVL trees are used in plenty of real-life applications, such as database systems, story-line games, and file systems. These applications have a common need: they all require efficient operations. During my research, I learned about the importance of AVL trees and how they are used in real-life applications that demand efficient operations. Additionally, I learned how to implement and analyze the AVL tree in C.

<!-- auto references -->
[AVL Tree Code]: AVL_Tree.h 
[time compare]: time.png
[count compare]: count.png