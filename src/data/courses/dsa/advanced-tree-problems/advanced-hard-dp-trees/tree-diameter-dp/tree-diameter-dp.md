Find tree diameter using DP on the tree.

<br>

> **Key insight:** For each node: diameter through it = two longest paths to leaves. Track global max.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** dp[v] = 1 + max child depth, diameter = max(d1+d2) across all nodes

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `dp[v] = 1 + max child depth, diameter = max(d1+d2) across all nodes`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
