Find max number of envelopes you can nest (both width and height must be strictly larger).

<br>

> **Key insight:** Sort by width ascending, height DESCENDING for same width. Then LIS on heights. Descending height prevents using two envelopes with same width.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `Sort + LIS on heights`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `Sort + LIS on heights`

### Time Complexity: O(N log N)
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
envelopes=[[5,4],[6,4],[6,7],[2,3]] → sort: [2,3],[5,4],[6,7],[6,4] → LIS on heights [3,4,7,4]=3
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N log N) | O(N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
