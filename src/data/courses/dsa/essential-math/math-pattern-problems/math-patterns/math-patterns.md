## Overview
Solve common mathematical pattern problems including trailing zeros, Fibonacci, and perfect squares.

## Topics Covered
1. **Trailing Zeros in Factorial**: Count zeros at end of n!
2. **Fibonacci Fast Doubling**: Compute Fib(n) in O(log n)
3. **Check Perfect Square**: Determine if number is perfect square
4. **Happy Number**: Check if number reaches 1 through digit square sum

## Approach
### Trailing Zeros
- Count factors of 5 in n!
- Time: O(log n)

### Fibonacci Fast Doubling
- F(2k) = F(k)[2F(k+1) - F(k)]
- F(2k+1) = F(k+1)^2 + F(k)^2
- Time: O(log n)

### Perfect Square
- Check if sqrt(n)^2 == n
- Time: O(1)


---

## Constraints

- `1 ≤ n ≤ 10⁹ (for number theory problems)`
- `Results may need modular arithmetic`

<br>

---

## All Possible Edge Cases

1. **n = 0:** Check base case definition
2. **n = 1:** Smallest valid input
3. **Prime number input:** Special behavior in factorization/sieve
4. **Power of 2:** Special case in many algorithms
5. **Very large n:** Needs O(√n) or O(log n) algorithm
6. **n = 0 or 1 in GCD:** GCD(a,0) = a, GCD(1,b) = 1

<br>

## Complexity Analysis
### Time: O(log n) for most operations

## Code
```code```
