Find the length of the longest bitonic subsequence (first increasing, then decreasing).

<br>

> **Key insight:** Compute LIS from left (inc[i]) and LIS from right (dec[i]). Answer = max(inc[i]+dec[i]-1).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `bitonic[i] = inc[i] + dec[i] - 1`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `bitonic[i] = inc[i] + dec[i] - 1`

### Time Complexity: O(N²)
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
nums=[1,11,2,10,4,5,2,1] → 6 (1,2,10,4,2,1 or 1,2,5,4,2,1)
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N²) | O(N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
