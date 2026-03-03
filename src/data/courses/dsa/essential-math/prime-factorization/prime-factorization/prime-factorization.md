# Prime Factorization

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

## Complexity Analysis
### Time: O(√n) per number, O(n log log n) with SPF

## Code
```code```