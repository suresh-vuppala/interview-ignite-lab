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

---

```code```
