

## Solution #2: Top-Down Approach(Memoization)
Why are we adding memoization to our recursion? 
We encounter the same subproblems which, without memoization, are computed repeatedly. Those repetitions very often lead to exponential time complexities.

**Steps:**

**1. Use a global array or a lookup table of size N+1 to store solution of the different subproblems.**
>            Let’s say N=5
>            cache[N+1]

**2. Initialize all the values in the array to -1 (Since the value of Fibonacci can’t be negative)**
>            cache[6] = {-1,-1,-1,-1,-1,-1}

**3. Recurrence relation**
>            F(n) =F(n-1)+(n-2), 

**4. Base Condition**
>            F(0) = 0 and F(1)=1


<br>
<br>


![Fibonacci Carousel](/Image/FibonacciSolution)


> **Order of recursive calls:** fib(n)-> fib(n-1)-> fib(n-2) ...-> fib(i)-> fib(i-1)-> fib(i-2)    ...    -> fib(2)-> fib(1)-> fib(0)
> **Order of storing the results in the table:** F[0]-> F[1]-> F[2] ...-> F[i]-> F[i-1]-> F[i-2]    ...   -> F[n-2]-> F[n-1] ->F[n]

[code]