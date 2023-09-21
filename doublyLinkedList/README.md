# Homework 04: Doubly Linked List

Name: Hanru Chen 

Github Account name: HanruC

How many hours did it take you to complete this assignment (estimate)? Eight hours.  

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed 
No. I did it myself. 


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource
GeeksForGeeks. 
Stackoverflow. 

(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## Understanding Time Complexity

1. Using a markdown table and markdown/latex math, show the BigO for Arrays, Singly Linked Lists, Doubly Linked Lists (so total of 3). For the columns, you will look at the Average Case Time Complexity for Access, Search/Find,	Insertion, and Deletion.

| Data Structure      | Access            | Search/Find         | Insertion          | Deletion           |
|---------------------|:----------------:|:-------------------:|:------------------:|:------------------:|
| Arrays              | $O(1)$            | $O(n)$              | $O(n)$             | $O(n)$             |
| Singly Linked Lists | $O(n)$            | $O(n)$              | $O(n)$             | $O(n)$             |
| Doubly Linked Lists | $O(n)$            | $O(n)$              | $O(n)$             | $O(n)$             |


2. Usually for singly and doubly linked lists, we reference both the head and tail for speed considerations. What would be the cost if you only had your head referenced, and you wanted to push to the tail of either?  $O(?)$
Firstly, for singly linked lists, if we only have a reference to the head and want to push to the tail, then we need to traverse the whole list in order to get the last one. Then it will take $O(n)$ time complexity because we are looking for the entire list. 
Secondly, for doubly linked lists, if i only have a reference to the head but without reference to the tail, I can push to the tail in $O(1)$ because it is doubly linked list then nodes have pointer pointing to prev and next. Thus, we can easily updating next pointer and prev pointer. 

3. Name an example where an array is better than a linked list, and an example where a linked list is better than an array. Make sure to reference the big O as part of your reasoning. 
First, an array is better than linked list: If we want to acceess the element by index, array is better than linked list. It is because that arrays have $O(1)$ for accessing whereas linked lists have $O(n)$ to access. Such as implementing hash table where we need access frequently by the indices. 

Second, the linked list is better than array: When we are inserting and deleting, when these operations are frequent, we need linked list. It is because that when we are inserting and deleting, the time complexity of linked list is $O(1)$ while the array is $O(n)$. Concrete example is queue and stack we learned before. 

Note: Make sure look at your finished markdown in the browser hosted on github or via a markdown preview extension. To confirm the notation is showing up properly. 

## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

