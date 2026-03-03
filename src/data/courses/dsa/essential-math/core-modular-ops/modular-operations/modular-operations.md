## Overview
Perform arithmetic operations under modulo including fast modular exponentiation.

## Topics Covered
1. **(a + b) % m**: Modular addition
2. **(a - b) % m**: Modular subtraction
3. **(a * b) % m**: Modular multiplication
4. **Fast Modular Exponentiation**: Compute (a^b) % m efficiently

## Approach
### Basic Operations
- (a + b) % m = ((a % m) + (b % m)) % m
- (a - b) % m = ((a % m) - (b % m) + m) % m
- (a * b) % m = ((a % m) * (b % m)) % m

### Fast Modular Exponentiation
- Use binary exponentiation with modulo
- Time: O(log b)

## Complexity Analysis
### Time: O(1) for basic ops, O(log b) for power

## Code
```code```