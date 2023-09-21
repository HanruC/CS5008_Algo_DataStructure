# Sort Analysis Data

## Results Table
Make sure to go out to at least 100,000 (more are welcome), and you have 10 different values (more welcome). You are welcome to go farther, but given 100,000 can take about 20 seconds using a selection sort on a fast desktop computer, and 200,000 took 77 seconds, you start having to wait much longer the more 0s you add. However, to build a clearer line, you will want more data points, and you will find merge and quick are able to handle higher numbers easier (but at a cost you will explore below). 

You are free to write a script to run the program and build your table (then copy that table built into the markdown). If you do that, please include the script into the repo.  Note: merge sort is going to be completed in the workshop for Module 06. You can start on it now, but welcome to wait.

### Table
| N | Bubble | Selection | Insertion | Merge | Quick |
| :-- | :--: | :--: | :--: | :--: | :--: |
| 1 | 0.000002s | 0.000001s | 0.000002s | 0.000002s | 0.000005s | 
| 10 | 0.000003s | 0.000013s | 0.000002s | 0.000007s | 0.000011s | 
| 100 | 0.000137s | 0.000052s | 0.000049s | 0.000043s | 0.000034s | 
| 1000 | 0.0104s | 0.0028s | 0.004s | 0.0004s | 0.0006s | 
| 5000 | 0.207s | 0.0624s | 0.0783s | 0.002s | 0.00212s | 
| 10000 | 0.53s | 0.173s | 0.222s | 0.005s | 0.0042s | 
| 30000 | 4.20s | 0.974s | 1.364s | 0.0143s | 0.012s |
| 50000 | 11.49s | 2.555s | 3.81s | 0.0257s | 0.0215s | 
| 80000 | 29.432s | 6.377s | 9.35s | 0.040s | 0.0338s | 
| 100000 | 49.75s | 10.66s | 15.19s | 0.05s | 0.03s |
| 105000 | 53.87s | 11.59s | 16.9s | 0.045s | 0.024s |
| 110000 | 59.36s | 12.43s | 18.41s | 0.045s | 0.041s |
| 120000 | 70.70s | 15.01s | 21.65s | 0.04s | 0.03s |   
| 130000 | 83.15s | 17.67s | 25.3s | 0.05s | 0.05s |
| 140000 | 96.25s | 20.04s | 29.45s | 0.058s | 0.042s | 
| 150000 | 109.7s | 23.6s | 33.88s | 0.055s | 0.057s |     
| 160000 | 123s | 26.36s | 38.71s | 0.06s | 0.058s |
| 170000 | 136.7s | 30.46s | 44.12s | 0.07s | 0.064s |
| 180000 | 149.8s | 33.6s | 49.16s | 0.08 | 0.067s |
## BigO Analysis  / Questions

### 1. Build a line chart
Build a line chart using your favorite program. Your X axis will be N increasing, and your Y access will be the numbers for each type of sort. This will create something similar to the graph in the instructions, though it won't be as smooth.

Include the image in your markdown. As a reminder, you save the image in your repo, and use [image markdown].
Here is the line chart 
![line chart]

### 2. Convinced?
Given the direction of the line chart, are you "convinced" of the complexity of each of the sorts? Why or why not?
Based on the line chart, i am convinced of the complexity of these different sorts. In the chart, we can see that bubble sort and 
selection sort have a steeper slope as N increases. Also, for the insertion sort, it can be clearly found out that it is slower than 
merge sort and quicksort which is consistent with the worst case complexity. 

### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do. 
| Algorithm | Best Case | Worst Case | Average Case |
| --- | --- | --- | --- |
| Bubble Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ |
| Selection Sort | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ |
| Insertion Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ |
| Merge Sort | $O(n log n)$ | $O(n log n)$ | $O(n log n)$ |
| Quick Sort | $O(n log n)$ | $O(n^2)$ | $O(n log n)$ |

Resource: Iqbal, Z. (2021). Time and Space Complexity of Bubble Sort. OpenGenus IQ. https://iq.opengenus.org/time-space-complexity-bubble-sort/


#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts

Bubble sort: [8,7,6,5,4,3,2,1] 
Reason: Basically, the worst case scenario for Bubble sort occurs when the array is in the reverse sorted order. In this situation, the largest element needs to be 
swapped all the way back the end of the array which means we need to traverse the 
whole list, which requires n-1 passes to sort. 

selection sort: [9,8,7,6,5,4,3,2,1]
Reason: The worst case scenario for selection sort occurs when the array is in reverse sorted order. In this situation, we need to swap n * (n - 1) / 2 swaps.
insertion sort: [8,7,6,5,4,3,2,1] 

Reason: The worst case scenario for insertion sort occurs when reverse sorted order list happens. This case, all elements needs to be moved all the way to the beginning which means we need to traverse the whole list. 
merge sort: [8,7,6,5,4,3,2,1] 

Reason: Although merge sort is a divide and conquer algo, the worst case is still in the reverse sorted order. Each merge operation requires comparing and copying n elements, which requires n*log(n) comparisons and swaps. 

#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts 

Bubble: [1,2,3,4,5,6] 
Reason: The best-case scenario for Bubble Sort occurs when the array is already sorted in ascending order. In this case, we only need to do one pass which is only one traverse of the list. Thus, the time complexity reduced to n. 

selection: [1,2,3,4,5,6]
Reason: The best-case scenario for Selection Sort occurs when the array is already sorted in ascending order. In this case, the algo compares each element and swaps the smallest element with first unsorted one. Since the list is sorted, then the complexity reduced from $n^2$ to n. 

insertion: [1,2,3,4,5,6]
Reason: The best-case scenario for Insertion Sort occurs when the array is already sorted in ascending order. In this case, there is no swaps needed. Thus, the time complexity reduced to n. 

merge sort: [1,2,3,4,5,6]
Reason: The best case scenario for merge sort is same as above which is sorted in ascending order. Each recursive call will divide the array into two halves of equal size, and the merging process will concatenate the two sorted halves together. In this case, although the time complexity is still n*logn, the time complexity is still smaller since in each recursive the number is smaller since each number is sorted. 

#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 
Selection, insertion, and bubble: These three use O(1) memory because they sort the array in place. Thus, they do not need additional memory
for temp arrays or recursions.
Quick: quick sort uses O(logn) memory in average. The recrusive algo divides the array into two subarrays and so the memory usage all depends on how many times of recursion calls needs. The worst situation for memory is O(n) when divides into subarrays of size 1 and
size n-1. 
Merge sort: Merge sort uses O(n) memory. It divides the array into to temp arrays of n/2 size. The going to the recursive part. So it continues to divide and finally merge those arrays back. 
### 4. Growth of Functions
Give the following values, place them correctly into *six* categories. Use the bullets, and feel free to cut and paste the full LatexMath we used to generate them.  

$n^2$  
$n!$  
$n\log_2n$  
$5n^2+5n$  
$10000$  
$3n$    
$100$  
$2^n$  
$100n$  
$2^{(n-1)}$
#### Categories
* $\mathcal{O}(1)$: $10000$
* $\mathcal{O}(n)$: $3n$, $100n$
* $\mathcal{O}(n\log n)$: $n\log_2n$
* $\mathcal{O}(n^2)$: $n^2$, $5n^2+5n$
* $\mathcal{O}(2^n)$: $2^n$, $2^{(n-1)}$
* $\mathcal{O}(n!)$: $n!$

### 5. Growth of Function Language

Pair the following terms with the correct function in the table. 
* Constant, Logarithmic, Linear, Quadratic, Cubic, Exponential, Factorial

| Big $O$     |  Name  |
| ------      | ------ |
| $O(n^3)$    |  Cubic |
| $O(1)$      | Constant |
| $O(n)$      | Linear |
| $O(\log_2n)$ | Logarithmic |
| $O(n^2)$    | Quadratic |
| $O(n!)$     | Factorial |
| $O(2^n)$    | Exponential |



### 6. Stable vs Unstable
Look up stability as it refers to sorting. In your own words, describe one sort that is stable and one sort that isn't stable  
Basically, if a sort algo is stable it means that it does not gurantee or keep the order of array. Another words, if it preserves the relative order of elements. For example, it i have two elements with same key value, then a stable sort algo will still maintain these order
in output, but unstable algo will not. Example for stable will be insertion sort which is that the two elements have same values, the first appears first will still in the first pos when sorted.

### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 
Given the example above, in a stable algo, if two elements in the input have same value, then it will remains the same pos in the output. 
Simple example when we really need stable alog. When there are bunch of keys in a dataset and we need to sort it, then we really need a 
stable algo. Example: if i have a data set includes a medicine's color, price, name, function, and benefit, i want to sort the price, then 
i need a stable algo to preserve other things beside the price. 
### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles. 

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.
Algo: 
1. First divide the 250 coins into two of 125 each.
2. Then weigh these two parts on the scale. 
3. check which is larger and lower, then the rare coin must be in one of the other 125. 
4. Then discard the parts that was weighed lower. 
5. Then repeat the process above by dividing and weighing and discarding. 

pseudo-code:
function findRare(coins)
    p1 = coins[0:124]
    p2 = coins[125:249]
    while true 
        w1 = weigh(p1)
        w2 = weigh(p2)
        if w1 > w2 
            p1 = p1[0:62]
            p2 = p1[63:124]+p2 
        else if w1 < w2
            p1 = p2[0:62]
            p2 = p2[63:124]+p1
        end
        if len(p1) == 1
            return p1[0]
        end

#### 7.2 Time Complexity
What is the average time complexity of your algorithm? 

My time complexity is O(logn) since it is same as merge sort which is we divide the coins into halves and repeat this process until divide
the coins into one or two. 


[line chart]:1951678390327_.pic.jpg