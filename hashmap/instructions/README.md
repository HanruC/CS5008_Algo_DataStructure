# Homework 09 - Hashmap

For this assignment, you will implement the hashmap as defined by [hashmap.h](../hashmap.h). We encourage you to take a simple approach. 


## The Goal
The hashmap you are building is to track items with their respective prices. As such, it is a key (item name) and value(float value of price). 
Similar to the hashmap talked about in Grokking Algorithms chapter 5. 

## Provided Code

The following two structs are provided. You have to use them as is. 
```c
typedef struct node
{
    char *key;
    float value;
    struct node *next;
} h_node;

typedef struct ht {
    int size;
    h_node **contents;

} *hashmap;

```
For this hashmap, you are storing the size with the struct, so the size can be declared during `map_create(int)`. This will allow us to test 
with a map of size 1, and a map of size 100000 (ok, maybe not that large..). 

For the functions you need to implement, those are all in the hashmap.h. The "test" file is there, so you can incrementally develop, but as you
notice there aren't any real tests in it. You will need to add tests for everything but the `map_print(hashmap)`. You will want to test the output
on that also, but harder to write a test function. 


👉🏽 **Task**: Implement all functions in hashmap.h and add tests to [testmap.c](../testmap.c). 

## 📝 Grading Rubric


Add (AG) and (MG) next to tiers, add major conditions to meet to pass each tier. 

1. Learning (AG)
   * Tests to make sure a simple hashmap is created
   * Tests to make sure a simple hashmap with larger numbers is created
   * Tests to make sure a simple get works
   * Tests to make sure a simple put works
2. Approaching  (AG)
   * Test get an invalid item
   * Test putting items that have a collision
   * Test deleting an item
1. Meets  (AG)
   * Test overwriting items with put
   * Test deleting an invalid item
   * Test printing times
2. Exceeds  (MG)
   * Reviews code for comments, style, and properly completed functions (including free)
   * Tests added for functions
   * All questions in README.md answered correctly


AG - Auto-graded  
MG - Manually graded

