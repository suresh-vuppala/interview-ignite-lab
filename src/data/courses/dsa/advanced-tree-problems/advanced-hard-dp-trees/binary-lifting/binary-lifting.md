Precompute 2^k-th ancestors for O(log N) ancestor queries.

<br>

> **Key insight:** up[node][k] = up[up[node][k-1]][k-1]. Precompute in O(N log N).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** up[v][k] = up[up[v][k-1]][k-1], query by decomposing k into powers of 2

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `up[v][k] = up[up[v][k-1]][k-1], query by decomposing k into powers of 2`

### Time Complexity: O(N log N) prep, O(log N) query
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) prep, O(log N) query | O(N log N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
