## Overview
Efficiently find divisors, count divisors, and calculate sum of divisors using √n approach.

## Topics Covered
1. **Count Divisors**: Count total divisors of a number
2. **Sum of Divisors**: Calculate sum of all divisors
3. **Find All Factors**: List all factors efficiently

## Approach

### Count Divisors
- Iterate from 1 to √n
- If i divides n, count both i and n/i
- Handle perfect square case
- Time: O(√n)

### Sum of Divisors
- Similar to count, add i and n/i
- Time: O(√n)

### Find All Factors
- Store factors while iterating to √n
- Time: O(√n), Space: O(number of divisors)


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
### Time: O(√n), Space: O(1) for count/sum, O(d) for listing

## Code
```code```
