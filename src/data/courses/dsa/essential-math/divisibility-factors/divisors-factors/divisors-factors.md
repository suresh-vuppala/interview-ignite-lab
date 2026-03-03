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

## Complexity Analysis
### Time: O(√n), Space: O(1) for count/sum, O(d) for listing

## Code
```code```