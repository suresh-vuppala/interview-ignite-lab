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

## Complexity Analysis
### Time: O(log n) for most operations

## Code
```code```