# GCD and LCM

## Overview
Learn to compute Greatest Common Divisor (GCD) using Euclidean algorithm and Least Common Multiple (LCM) using GCD.

## Topics Covered
1. **GCD (Euclidean Algorithm)**: Find greatest common divisor
2. **LCM using GCD**: Calculate LCM efficiently
3. **Check Coprime**: Determine if two numbers are coprime
4. **Extended Euclidean Algorithm**: Find coefficients for Bezout's identity

## Approach

### GCD - Euclidean Algorithm
- gcd(a, b) = gcd(b, a % b)
- Base case: gcd(a, 0) = a
- Time: O(log(min(a,b)))

### LCM using GCD
- lcm(a, b) = (a * b) / gcd(a, b)
- Time: O(log(min(a,b)))

### Coprime Check
- Two numbers are coprime if gcd(a, b) = 1

### Extended Euclidean
- Find x, y such that ax + by = gcd(a, b)
- Used for modular inverse

## Complexity Analysis
### Time: O(log n), Space: O(1)

## Code
```code```