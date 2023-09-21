[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9861995&assignment_repo_type=AssignmentRepo)
# Homework 03 - Stacks and Queues -

Name:Hanru Chen

Github Account name:HanruC  

How many hours did it take you to complete this assignment (estimate)? 20 hours to 24 hours. 

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed 
I learned and check all resources by my own. 


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource
GeeksforGeeks
Stackoverflow
w3schools.com
c programming book


(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## Further Thinking Questions

1. Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and answer this question specifically: Why is a ring buffer useful and/or when should it be used? 
2. We are going to talk about stacks quite a lot in this course, so it will be important to understand them. Do a little outside research, and edit this section of the readme answering specifically: Why is a stack useful and/or when should it be used?

Answer1. Basically, circular queues are used in when i tried to do the dequeue in the myqueue.h . Basically it tells us that we have reached
to the end. Using circular queues can prevent us to exceed the capacity. Also, it allows an efficient memory access. And the time is O(1). 

Also, ring buffer is used in many different situations. Firstly, the ring buffer can be used in the memory log with certain size. For using ring buffer,
it would be easy to records the log whenver exception happened. For this part, the most significant benefit for ring buffer is that we do not need an 
infinite size of memory. The older things will be overriden. 

Answer2. First, stack structure is fast in run time which is O(1). This time can be in both push and pop. Stack in problem solving area can be
powerful. Stacks are useful for doing the backtracking since it is LIFO structure. 

Stack can also be used in many situations. Firstly, stack can be powerful for doing Undo or Redo actions. In the documents we write, we sometimes need
to do undo action since we need to revise. Now, stack, due to its special data structure, can be powerful for designing undo redo process. 

Stack can also be useful for the browser history. Web browser can use stack to track what user has visited. Basically, when user using back and forward 
browser in google, stack can be really powerful to keep tracking the visiting history. 



For each of these questions, we are expecting your answer to be in the range of 2-3 paragraphs (can include complexity, example usage, pros/cons, etc). Make sure to cite your sources. It is recommended you use [IEEE citation style](https://owl.purdue.edu/owl/research_and_citation/ieee_style/ieee_overview.htm) as it is most common for CS papers and research. 


## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

