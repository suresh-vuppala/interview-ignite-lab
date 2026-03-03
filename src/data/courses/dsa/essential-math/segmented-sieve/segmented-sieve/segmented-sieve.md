# Segmented Sieve

## Overview
Find primes in large range [L, R] where R can be up to 10^9 using segmented sieve technique.

## Topics Covered
1. **Segmented Sieve Algorithm**: Handle large ranges
2. **Primes in Range [L, R]**: Find all primes in given range
3. **Memory Optimization**: Use only O(√R) space

## Approach

### Segmented Sieve
- First find all primes up to √R using standard sieve
- Use these primes to mark composites in [L, R]
- Process in segments to save memory
- Time: O((R-L+1)log log R + √R log log √R)
- Space: O(√R + (R-L+1))

## Complexity Analysis
### Time: O((R-L)log log R), Space: O(√R)

## Code
```code```