Find primes in range [L, R] using segmented sieve.

<br>

---

## Solution 1: Simple Sieve up to R — O(R) space, infeasible for large R
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
