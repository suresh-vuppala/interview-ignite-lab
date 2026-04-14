Find primes in range [L, R] using segmented sieve.

<br>

---

## Solution 1: Simple Sieve up to R — O(R) space, infeasible for large R

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Segmented Sieve — Sieve primes up to √R, then mark composites in [L,R]

### Time: O((R-L+1) log log R + √R) | Space: O(√R + R-L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Simple Sieve | O(R log log R) | O(R) | Too much memory for large R |
| Segmented | O((R-L) log log R) | O(√R + R-L) | Only sieve the range |

<br>
<br>

---

```code```
