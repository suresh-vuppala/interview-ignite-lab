At most 2 transactions. Maximize profit.

<br>

> **Key insight:** Track buy1, profit1, buy2, profit2 in one pass. buy2 considers profit1 as discount.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `State machine / track approach`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `State machine / track approach`

### Time Complexity: O(N)
**Why?** Each state computed once.

### Space Complexity: O(1) or O(K)

**Example walkthrough:**
```
Single pass through prices/values tracking states
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N) | O(1) or O(K) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
