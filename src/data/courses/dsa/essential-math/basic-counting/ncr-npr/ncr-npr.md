## Overview
Calculate combinations (nCr) and permutations (nPr) with and without modulo.

## Topics Covered
1. **nCr Calculation**: Combinations formula
2. **nPr Calculation**: Permutations formula
3. **Pascal's Triangle**: Dynamic programming approach
4. **nCr % m**: Modular combinations

## Approach
### nCr = n! / (r! * (n-r)!)
- Optimize by canceling terms
- Time: O(r)

### nPr = n! / (n-r)!
- Time: O(r)

### Pascal's Triangle
- C(n,r) = C(n-1,r-1) + C(n-1,r)
- Time: O(n*r), Space: O(n*r)


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

## Complexity Analysis
### Time: O(r) direct, O(n*r) DP

## Code
```code```
