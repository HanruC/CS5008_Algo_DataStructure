# Homework 09

Name: Hanru Chen

Github Account name: HanruC

Link to Github Repo: https://github.com/Spring23-CS5008-BOS-Lionelle/homework-09-HanruC.git   

How many hours did it take you to complete this assignment (estimate)? 10 hours

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed

I did it by myself. 


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource
Geeks for Geeks 


(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## Questions

1. Add a markdown table demonstrating the in practice time for Hashmaps. 


| Operation      | Average case Time Complexity            | Worst case Time Complexity         | 
|---------------------|:----------------:|:-------------------:|
| Insertion              | $O(1)$            | $O(n)$              |
| Deletion | $O(1)$            | $O(n)$              | 
| Retrieval | $O(1)$            | $O(n)$              | 

Insertion: Average case: Big O is O(1) since in average case the hash function could make the keys per
bucket small enough. Thus, inserting a new key value pair should take a constant time since the linked-list
in each bucket is small. For worst case, it is O(n) because we need to consider if the collision happens a lot 
which means that in each bucket, we have large number of linked list. Thus, we need to traverse the whole list 
which is based on the number of elements in the hashmap. 

Deletion: Average case is O(1) because it is quite similar to insertion that the collision in each bucket is small, which 
means that the linked list in each bucket is smaller enough. Thus it takes O(1). The worst case is O(n) since we also
need to consider that if the collision is really big in each bucket, where we need to traverse the whole large linked
list. It makes the deletion O(n) in worst case. 

Retrieval: Similar to above that we need to consider if the collision is big or small. If the collision is small,
we can retrive the value really fast since the linked list is small. However, in the worst case, if the linked list
is large which means that the collision is large, we need to traverse the large number of linked list which makes
the time complexity linear time depends on the number of elements in hashmap. 

2. What is the worst case time for a hashmap, even if rare, can you come up with a condition that always generates worst case?
Simply speaking, the worst case which is quite rare, is when all the key value pairs on in the same bucket. In this 
condition, it makes the hashmap into a linked list style. In this situation, the hash function is usually designed 
pretty bad. For example if the hash function is designed to return 0, then it will always return the same hash
value 0 no matter what input string. 
```c
unsigned long bad_hash(char *str) {
    return 0;
}
```

3. Looking back at the Lab09, how often did you see collisions from the various data sizes? (go ahead and copy/paste the output from the lab)
Collisions: 391, Highest: 5, Average Length > 1: 2.22, Filled Spots: 785, Load: 0.00039
Collisions: 22, Highest: 2, Average Length > 1: 2.00, Filled Spots: 989, Load: 0.00049
Collisions: 22, Highest: 2, Average Length > 1: 2.00, Filled Spots: 989, Load: 0.00049
Collisions: 24, Highest: 2, Average Length > 1: 2.00, Filled Spots: 988, Load: 0.00049

4. To make this hashmap fully usable - what are some functions missing that should be implemented? (props if you implement them!)
   * if you are stuck, think about how would someone get all the names of the food items, if they are doing inventory?
Actually, three methods are missing. First is the mapKeys(). This method should return an array of keys in the hashmap. This method is useful to iterate through all keys. 
The second method is the mapValues(). This method is to return all values in the hashmap. 
It is quite useful for iterating all values if we just want to calculate items which is 
the values in the hashmap. 
Third one, i believe that I should include a mapSize() method to get the size of the 
key value pairs in the hashmap. 
Basically these three method is kind of like a getter method in java which we can directly 
call these method to do the specific operation. 

5. How can hashmaps help you with dynamic programming? Are they effective mechanisms for caches? 
As we know that dynamic programming is to solve a problem by breaking into smaller pieces and use them to solve and find the solution. Thus, hashmap can help by storing those smaller
pieces and make it fast to find the those smaller parts. It is useful for memoization which is a technique of saving the result when doing complex calculations and use those saved result when having repeated inputs. This is quite effective for caches since it make the process faster by storing those repeated calcuation in the hashmap. 


## Important notes

* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

