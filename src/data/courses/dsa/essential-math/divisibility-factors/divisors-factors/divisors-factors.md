Find all divisors of a number N.

<br>

> N=12 → [1,2,3,4,6,12]
>
> **Key insight:** Check from 1 to √N. If i divides N, both i and N/i are divisors.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check all 1 to N

**Intuition:**
The most straightforward approach. Checking all numbers up to N.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking all numbers up to N.

> **Key Insight for Improvement:**
> Only check up to √N: if i divides N, both i and N/i are divisors.

<br>

---

## Solution 2: Square Root Optimization (Optimal)

**Intuition:** Check from 1 to √N. If i divides N, both i and N/i are divisors.

**Algorithm:**
1. For i = 1 to √N:
   - If N % i == 0: add i (and N/i if different)
2. Sort result if needed

### Time Complexity: O(√N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
N=12: i=1→(1,12), i=2→(2,6), i=3→(3,4), √12≈3.46→stop
Divisors: [1,2,3,4,6,12]
```

### Space Complexity: O(√N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all 1 to N | O(N) | Varies | Baseline |
| Square Root Optimization | O(√N) | O(√N) | Optimal |

**Recommended Solution:** Square Root Optimization

**Key Insights:**
1. **Divisors come in pairs:** i and N/i
2. **√N sufficiency:** One of each pair is ≤ √N
3. **Perfect square:** Don't double-count √N

<br><br>

---

```code```
