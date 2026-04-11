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
