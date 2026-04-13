Find all prime factors of N with their multiplicities.

<br>

> N=60 → 2²×3×5
>
> **Key insight:** Divide by 2 repeatedly, then by odd numbers 3,5,7... up to √N. Remaining N > 1 is a prime factor.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Trial division up to N

### Time Complexity: O(N)

> **Drawback:**
> Checking all numbers up to N.

> **Key Insight for Improvement:**
> Divide by smallest primes first, only up to √N.

<br>

---

## Solution 2: Optimized Trial Division (Optimal)

**Intuition:** Divide by 2 repeatedly, then by odd numbers 3,5,7... up to √N. Remaining N > 1 is a prime factor.

**Algorithm:**
1. While N%2==0: add 2, N/=2
2. For i=3 to √N, step 2: while N%i==0: add i, N/=i
3. If N>1: add N (remaining prime)

### Time Complexity: O(√N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
60: /2→30→/2→15→/3→5→5>√5? Yes→add 5. Factors: [2,2,3,5]
```

### Space Complexity: O(log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Trial division up to N | O(N) | Varies | Baseline |
| Optimized Trial Division | O(√N) | O(log N) | Optimal |

**Recommended Solution:** Optimized Trial Division

**Key Insights:**
1. **Smallest factors first:** Ensures each factor is prime
2. **Remaining N>1:** Must be prime (no factors ≤ √N found)
3. **Sieve optimization:** Precompute smallest prime factor for O(log N)

<br><br>

---

```code```
