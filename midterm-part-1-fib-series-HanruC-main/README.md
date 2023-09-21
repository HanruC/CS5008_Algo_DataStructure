# Midterm p1: Report on Analysis of Fibonacci  Series
* **Author**: Hanru Chen 
* **GitHub**: https://github.com/Spring23-CS5008-BOS-Lionelle/midterm-part-1-fib-series-HanruC.git 
* **Semester** Spring 2023
* **Languages Used**: c, python

## Overview
This report focuses on the speed differences between implementations of [Fibonacci Series]. What is fibonacci series? Fibonacci Series is a sequence of numbers that each number after the first two numbers is the sum of these two previous ones. Giving simple example: First two is 0,1. Then the sequence should be 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55.... Basically, in Math representation, it should look like this: $$ a2 = a0 + a1 $$. Or being like this: 
$$F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for every n > 1$$

Plenty ways or algos can be implemented for fibonacci series. In this report, I used three ways(algos): Iterative, Recursion, Dynamic Programming. 
| Version |  Big O | Space Used | 
| :-- | :-- |  :-- |
| Iterative | $O(n)$ | $O(1)$ |
| Recursive | $O(2^n)$  | $O(n)$ |
| Dynamic Programming | $O(n)$ | $O(n)$ |

1. Iterative: 
In this approach, I use a loop to calculate $nth$ Fibonacci number by having three variables which are total, fib1, and fib2. Doing so, I can update them in each iteration process. The time complexity is $O(n)$ because we need to iterate over all numbers in order to calculate the nth number. 
The pseudocode is like: 
```text 
A = 0
B = 1
Total = 0 
for 0..n: 
    Total = A + B
    A = B 
    B = Total
return A
```
2. Recursion: 
In this approach, I calculate $nth$ Fibonacci number by recursively calling function with $n-1$ and $n-2$ until we reach the base case which are listed in the method($n = 0, n = 1$). The time complexity is $O(2^n)$. Psudocode is like: 
```text 
func fib_recur(n): 
    if n<= 0: 
        return 0
    if n == 1: 
        return 1
    return fib_recur(n-1) + fib_recur(n-2)
```
3. Dynamic Programming: 
This approach is using dynamic programming thought which is i am storing the results in an array so that we do not need to recalculate them each time we need them in the calculating process. The time complexity is $O(n)$. Psudocode is like: 
```text 
fiblist = [0,1] 
for i in range 2...n+1:
    fiblist.append(fiblist[i-1] + fiblist[i-2])
return fiblist[n]
```
For this analysis, I chose python for my second langauge to use. The reason is that we just learned python last semester and also I noticed on the web that C is faster language than python. Thus, I want to use Fibonacci series as an example to test this. 
## Empirical Data & Discussion 
For all empirical results, the maximun out time is 60 seconds. In order to do it like that, I just want to set the time efficiency and do not want to waste plenty of time on one of the algo since I noticed that recursion may take a long time when number goes up according to the previous experience. ([test script])

Empirically, the recursive version for C timed out much quicker. The following is the graph for recursion C. 
### Recursive Versions 
![Recursive C]  
The C recursive version stopped at N = 48. In the graph, you can see that curve goes up suddenly. 
![Recursive P]
Although python does not stopped at N = 48, but in order to do the clear comparison, the graph also stops at 48. But, according to the csv, python went well 
in all the test number I had (N = 1000). The graph I had seems to be a big flow, but when you go to the Y, the number does not flow that much. Typically, it
just flows a little bit. ([test_run]) 

### Iterative and Dynamic Programming Versions 
For the Iterative and Dynamic Programming, according to their Big O above I showed, they are fast as O(n). In the following graph, you can see the speed: 
![P DP Iterative] 
The number on Y is the time. As number goes up to 1000, the time is still fast as almost $0.08$ Compared to recursive, it is much faster. 
For dynamic and iterative, it is interesting to find out that dynamic suddenly goes up from about 481.It is possibly because the size of list goes up and memory usage increases. While dynamic prgramming time goes up, the iterative method remains stable in time efficiency.  
![C DP Iterative]
For the C version, it is similar to python which is dynamic programming time goes up when number goes up. Iterative method remains stable in all 1000 numbers. 
For large number, such as I have $N = 10000$, the iterative method also goes up while dynamic programming, as same as the small number, goes up as expected. 
For the larger number comparison, I take steps in 500. In the graph, it seems like iterative method is more efficient than dynamic programming method as the curve trend in the graph. 
![Large number comparison]
In general, for both languages, iterative is faster than dynamic prgramming, and dynamic programming is faster than recursive. 
## Language Analysis
The code can be found in the following: 
* [fib.c]  -- implementation of functions in c
* [fib.py] -- implementation of function in python
* [test_runner.py] -- run script to help with tests and keep timings

### Language 1: C
For C version, it is a low_level language that the speed of processing can be fast. When I was trying to implement the code in C, my first concern is about
how to malloc and free in the method, especially in the dynamic programming method. In dynamic programming method, firstly, I was trying to use a temp table to store the numbers that are calculated. For this choice, I need to malloc the temp table and then free it at the end. I found it not so efficient because malloc makes the code not that clean. So my second try is to do a global table at the top of the code which is like: 
```c 
#define MAX 50000
typedef uint64_t ull;
static ull fib_table[MAX];
```
By doing this choice, there is no need to malloc the memory in the method because I am using the globle table to store the number. Declaring the array statically can be efficient in memory and also the performance. Static arrays are stored in data section which is allocated before the program starts. When we 
mallco the array in the method, it takes more runtime when operating it. [Static arrays]

The code for both recursive and dynamic programming were matched the pesodocode exactly which also needed to fit in C. 
```c  
ull fib_dynamic(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        fib_table[0] = 0;
        fib_table[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib_table[i] = fib_table[i - 1] + fib_table[i - 2];
        }
        ull result = fib_table[n];
        return result;
    }
ull fib_recursive(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib_recursive(n-1) + fib_recursive(n-2);
    }
}
ull fib_iterative(int n) {
    uint64_t fibTotal = 0, fib1 = 0, fib2 = 1;
    for (int i = 0; i < n; i++) {
        fibTotal = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibTotal;
    }
    return fib1;
}
```
As you can see, in the dynamic programming part, I gave up using temp table and malloc the table at first and then free it at the end. Instead, I can directly
use the fib_table I made at the top of the program. 
Another problem I met when do ing the printing is that I the boolean method I need to import from the library which is 
```c  
#include <stdbool.h>
```
In order to do the print and select version, importing this library is pretty necessary since we need to do it in the main like this: 
```c  
bool print = false;
if (printLevel > 1) {
    print = true;
}
int* fib_series = print_fib_series(n, print, version);
if (printLevel == 1) {
    printf("%d\n", getFib(n, version));
}
```

### Language 2: Python 
For python version, I first wrote the iterative method, and then the recursive. In the process of writing at first, I just soley do the function like: 
```python
 def fib_recursive(n: int) -> int:
```
However, for here, I found another efficient way of importing the List from typing. By doing this, the code is really clear to see that I am returning a 
list at the end which is like what I revised in the second version: 
```python
def fib_recursive(n: int) -> List[int]:
    if n == 0:
        return [0]
    elif n == 1:
        return [0, 1]
    else:
        fib_list = fib_recursive(n - 1)
        fib_list.append(fib_list[-1] + fib_list[-2])
        return fib_list
```
In the dynamic programming method, I used the built-in lru_cache which can automatically caches the result of function. It is also a good way to 
reduce manual memoization operation in the method. I also used the click library to create a command-line for the program, which made it easy to run and test different versions of the algo with different input sizes and parameters.
One of the another concern or even the question I had when I tried to write the get method and main is that how can I can use the enumaration like java in python. For this question, my solution is to import enum from Enum and create an Enum class like this: 
```python
class FibType(Enum):
    DP = 2
    RECURSIVE = 1
    ITERATIVE = 0 
```

### Comparison and Discussion Between Experiences
After implementing fibonacci series using both C and Python, there are couple notable differences and also pre-think when implementing the code. 

Firstly, when I was trying to implement using C, the first concern is about memory leaking. As I mentioned above, I tried two different ways in 
the implementation which are malloc table in the method or using global table at the beginning of the program. Both work, but they are different in 
operating efficiency and the visual experience in coding. Also, it would be a disaster when I do the python first and then C next since the syntax of 
C is much more complex and more concerns. For example, for the bool library, I cannot directly use bool print_it but need to include the library in C. It is
similar to python but it is not a exisiting method like python. 
On the other hand, Python has a lot of built-in function and libraries that make it easier to write concise, readable code. For example, the built-in Iru_cache makes the code easier for dynamic programming in python since I do not need to worry about the cache size in python. However, when printing out the 
time efficiency in excel and csv, I can clearly find out that Python is slower than C especially when values go larger. 
In the empirical results, we can see that both C and Python showed the expected results of run complexity. Another thing I noticed that is interesting is that
in python recursive, the way I implement is quite similar to dynamic programming since I am storing 0 and 1 in the method and do the recursion after that. It might be the reason that it did not time out like recursion C when number goes up. 
Also, for python dynamic programming, when number goes up to almost 1000, the time efficiency is slower than C dynamic programming. In this case, my analysis 
is that there may be some kinds of langauge factors that play role in memory management. 

## Conclusions / Reflection
After conducting the analysis of Fibonacci series algos in both C and Python, several crucail takeaways in below's listings. 
Firstly, the most important notice and recognition when doing the graph analysis is that I found out that C is much more efficient than
Python which answers my web discovery at the beginning of this report. But according to the nature and syntax of two languages, concerns are
different. For example, I do not need to think about the memory leaking risk in python but I need to pre-think it when writing C. 
On the other hand, in python, the lru_cache helps me to implement dynamic programming without any memoization table in the method. 

Secondly, another big discovery in empirical results is that the iterative approach in both languages has the best time complexity which is not expected 
at the beginning of the analysis. It might be cause by the large memory storage in dynamic prgramming when N values go up. In general, the result not quite 
surpise me since I knew that dynamic programming and iterative is faster than recursive method. 

Finally, the language choice matters too. It is important to choose the langauge. When choosing the langauge, we need to include different languages' 
features. C is fast since it is a low-level language but the syntax and built-in functions are totally different from python. Python is a quite readable 
language which has many built-in functions but the trade-off is the speed. 

Generally speaking, this analysis helps me to have a clear view of different languages and different algorithms. 

## References 
1. Wikipedia, "Fibonacci number," Wikipedia: The Free Encyclopedia,
October 22, 2022. https://en.wikipedia.org/wiki/Fibonacci_number.
Accessed on: March 5, 2023.

2. eComputerNotes, "Static Arrays," eComputerNotes, n.d.
https://ecomputernotes.com/what-is-c/array/static-arrays.
Accessed on: March 5, 2023.

<!-- auto references --> 
[Fibonacci Series]: https://en.wikipedia.org/wiki/Fibonacci_number
[test script]: test_runner.py  
[Recursive C]:1881678041923_.pic.jpg 
[Recursive P]: 1891678041923_.pic.jpg 
[test_run]: fib_run.csv
[P DP Iterative]: 1901678042114_.pic.jpg
[C DP Iterative]:  1911678042302_.pic.jpg  
[Large number comparison]:1921678048386_.pic.jpg 
[fib.c]: fib.c 
[fib.py]: fib.py
[test_runner.py]:test_runner.py 
[Static arrays]: https://ecomputernotes.com/what-is-c/array/static-arrays