# Sieve of Eratosthenes

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
```code```