# Modular Inverse

## Overview
Compute modular multiplicative inverse using Extended Euclidean and Fermat's Little Theorem.

## Topics Covered
1. **Modular Inverse using Extended Euclid**: For any modulo
2. **Modular Inverse using Fermat's Little Theorem**: For prime modulo
3. **Applications**: Division in modular arithmetic

## Approach
### Extended Euclidean
- Find x such that (a * x) % m = 1
- Time: O(log m)

### Fermat's Little Theorem
- If m is prime: a^(-1) = a^(m-2) mod m
- Time: O(log m)

## Complexity Analysis
### Time: O(log m), Space: O(1)

## Code
```code```