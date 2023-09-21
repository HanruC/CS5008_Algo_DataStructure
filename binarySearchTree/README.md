# Homework 10 - Binary Search Trees (BST)

Name: Hanru Chen

Github Account name: HanruC

How many hours did it take you to complete this assignment (estimate)? 4 hours

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed

I just asked Tarakeswar Nallamothu for some couple questions for clang issue. Other than that, I did it myself. 

Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource
StackOverFlow, GeeksforGeeks

(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## BST Questions

1. Given a *balanced* and *full* Binary Search Tree, what is the Big O for finding a value in the tree?
In order to access or search value in a balanced and full Binary Search Tree, the Big O is O(log(n)). In order to find a value, I would need to 
follow a single path from the root to the target. Since it is a balanced and full Binary Search Tree, there are two children for each parents. Thus, the 
Big O is log(n). 

2. Define balanced in relation to BSTs. Remember to relate it to height. 
In BSTs, a balanced tree is the one that the height of the tree is minimized to reduced the time complexity of operations such as insertion, deletion, or searching. 
For a balanced BST, the difference in heights between left and right subtrees node is no more than 1. Simply speaking, no side is much larger than the other side. 
When it is balanced, the height is as small as possible. When a BST is balanced, it takes fewer steps to find value which is much efficient. 

3. What is the Worst Case Big O for searching or adding to a BST?
   * What type of BST would this be? (how would it look)
Basically, the worst case big O for search or adding to BST is O(n) where n is the number of nodes in the tree. This worst case occurs when the tree is extremely 
unbalanced and looks like a linked list but not a tree structure. In this worst case, the BST would look like a straight line where each node has only left child
or right child. It means that every level of the tree only consists one node and the height of the tree is equal to the number of nodes. 

4. What are some of the advantages of a BST over a linked list?
BST has some advantages over linked list. First, the serach time is faster in a balanced BST. The serach time big O is O(log(n)) while the linked list is O(n). 
Second advantage is that BST is more efficient in insertion and deletion. BST insertion and deletion big O is O(log(n)) while the linked list is O(n). In this situation, 
BST need to be fairly balanced. 
Third advantage is that BST is naturally sorted since we know that the right side is always smalled than the left side. Thus, it would be easier to find the min and 
max in BST. In linked list, we need to do an extra step for sorting which requires more processing time. 
In general, all these advantages should depend on the the tree is balanced. 

5. What are some cases / examples of when you would use a BST?
(1) Databases: BSTs are often used in databases to manage the keys or indexes for faster retreiving and modifying data. Good example will be AVL trees or Red-Black
trees. Databases often need to handle large data sets. Thus, they need to the characteristics of efficient storing, retreving, and modifying. In balanced BST, seraching 
for keys takes O(log(n)), where n is the number of nodes in tree. At this time, time complexity is fast. Self-balancing trees like AVL trees and Red-Black trees can automatically adjust structure to maintain balance when keys are inserted or deleted. 

(2) Symbol tables: Symbol tables stores information about functions, variables and etc of programming langauge. Thus, the time complexity is crucial. BSTs can be used
to look up, insert, and delet symbols while the program is being compiled. The average insertion and lookup big O is O(log2(n)). 

(3) Frequency sorting: BSTs can be used to keep tracking of the frequency of elements in data sets. According to the reserach: "The overall time complexity of the algorithm can be minimum O(nLogn) if we use a O(nLogn) sorting algorithm and use a self-balancing BST with O(Logn) insert operation." 
Resource: GeeksforGeeks. Sort Elements by Frequency using Binary Search Tree. Available at: https://www.geeksforgeeks.org/sort-elements-by-frequency-using-binary-search-tree/. Accessed: March 27th, 2023.
