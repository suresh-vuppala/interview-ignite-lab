Find the nth Fibonacci number in the Fibonacci series.
F(n) =F(n-1)+F(n-2), where F(0) = 0 and F(1)=1
0, 1, 1, 2, 3, 5, 8, 13….

<br>


> Input:
> N = 4

> Output:
> 3

> Explanation:
> F(n)  	=  F(n-1)   +   F(n-2)
> F(4)      =  F(4-1)   +     F(4-2)
> 	        =  F(3)       +     F(2)
> 	        =   2    +     1
> 	        =   3

<br>

---

## Solution #1: Brute Force - Recursive

![Fibonacci](/Image/FibonacciSeries.png)



```code```

<br>

### Why Recursion algorithm to find the Fibonacci number is Slow?

![Fibonacci](/Image/FibonacciRecursionTree.png)


Here is a diagram which illustrates the reason. This is the visual representation of the recursive algorithm.

Next we need to analyze our solution. If we look at the time complexity of our fib() function, we find that our solution will take O(2^n) time. Each recursive call subtracts 1 from n and results in two child calls. Therefore the depth of our recursion is n and each level has twice as many calls.
> 1c + 2c + 4c + … + 2^(n-1)c = [2⁰ + 2¹ + 2² + … + 2^(n-1)]c = O(2^n).
That’s a really bad runtime.


You can see here that to calculate the 5th term, the same subproblem appears more than once. For example, F(3) is occurring twice, F(1) is occurring 4 times, etc.
So, despite calculating the result of the same problem, again and again, we can store the result once and use it again and again whenever needed.

> **Time Complexity:** O(2^N)
> **Space Complexity:** O(N)
>
> For Fibonacci recursive implementation or any recursive algorithm, the space required is proportional to the maximum depth of the recursion tree, because, that is the maximum number of elements that can be present in the implicit function call stack. 
> As you can see the maximum depth is proportional to the N, hence the space complexity of Fibonacci recursive is O(N).

<br>
<br>
---



-