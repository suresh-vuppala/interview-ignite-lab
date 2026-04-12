Answer XOR queries offline using sorted processing.

<br>

> **Key insight:** Sort queries. Process with binary trie, add numbers incrementally.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Sort queries + binary trie + incremental insertion

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Sort queries + binary trie + incremental insertion`

### Time Complexity: O((N+Q)×32)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×32)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O((N+Q)×32) | O(N×32) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
