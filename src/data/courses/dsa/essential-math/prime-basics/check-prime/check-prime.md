## Overview
Check if a number is prime, count primes up to N, and find nth prime number.

## Topics Covered
1. **Check Prime (√n method)**: Determine if number is prime
2. **Count Primes up to N**: Count all primes ≤ N
3. **Find Nth Prime**: Get the nth prime number

## Approach

### Check Prime
- Check divisibility from 2 to √n
- Time: O(√n)

### Count Primes
- Check each number from 2 to N
- Time: O(N√N) naive, O(N log log N) with sieve

### Nth Prime
- Generate primes until count reaches n
- Time: O(n log n) approximately


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
### Time: O(√n) for check, O(N log log N) for count

## Code
```code```
