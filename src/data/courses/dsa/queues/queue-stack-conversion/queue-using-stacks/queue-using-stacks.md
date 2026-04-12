Implement queue using two stacks.

<br>

> **Key insight:** Push to stack1. For pop: if stack2 empty, pour all from stack1 to stack2. Pop from stack2.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Amortized O(1): each element moved at most once

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Amortized O(1): each element moved at most once`

### Time Complexity: O(1) amortized
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) amortized | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
