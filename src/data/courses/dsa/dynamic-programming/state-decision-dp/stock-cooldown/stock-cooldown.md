Buy/sell with 1-day cooldown after selling.

<br>

> **Key insight:** Three states: sold, held, rest. Transition with cooldown constraint.

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
