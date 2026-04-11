## Overview
Find prime factorization, count distinct and total prime factors, and use SPF array method.

## Topics Covered
1. **Prime Factorization**: Break number into prime factors
2. **Count Distinct Prime Factors**: Count unique primes
3. **Count Total Prime Factors**: Count with multiplicity
4. **SPF Array Method**: Smallest Prime Factor approach

## Approach

### Prime Factorization
- Divide by primes from 2 to √n
- Time: O(√n)

### Count Factors
- Track unique primes and their counts
- Time: O(√n)

### SPF Method
- Precompute smallest prime factor for each number
- Time: O(n log log n) preprocessing, O(log n) per query


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
### Time: O(√n) per number, O(n log log n) with SPF

## Code
```code```
