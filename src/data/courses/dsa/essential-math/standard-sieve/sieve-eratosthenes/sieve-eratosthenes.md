## Overview
Efficiently find all prime numbers up to N using Sieve of Eratosthenes algorithm.

## Topics Covered
1. **Sieve Algorithm**: Mark composites, keep primes
2. **Count Primes in Range**: Count primes from 1 to N
3. **Store SPF**: Store smallest prime factor for each number

## Approach

### Sieve of Eratosthenes
- Create boolean array of size N+1
- Mark multiples of each prime as composite
- Time: O(N log log N), Space: O(N)

### SPF Array
- Store smallest prime factor during sieve
- Useful for fast factorization
- Time: O(N log log N)

## Complexity Analysis
### Time: O(N log log N), Space: O(N)

## Code


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

---

```code```
