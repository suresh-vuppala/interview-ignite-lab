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
