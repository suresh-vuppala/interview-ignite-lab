


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

<br>

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
