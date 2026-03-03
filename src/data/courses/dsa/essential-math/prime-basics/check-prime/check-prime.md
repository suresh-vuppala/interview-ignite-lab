## Overview
Check if a number is prime, count primes up to N, and find nth prime number.

## Topics Covered
1. **Check Prime (√n method)**: Determine if number is prime
2. **Count Primes up to N**: Count all primes ≤ N
3. **Find Nth Prime**: Get the nth prime number

## Approach

### Check Prime
- Check divisibility from 2 to √n
- Time: O(√n)

### Count Primes
- Check each number from 2 to N
- Time: O(N√N) naive, O(N log log N) with sieve

### Nth Prime
- Generate primes until count reaches n
- Time: O(n log n) approximately

## Complexity Analysis
### Time: O(√n) for check, O(N log log N) for count

## Code
```code```