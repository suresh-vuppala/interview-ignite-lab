Find maximum XOR of any two numbers in array.

<br>

> **Key insight:** Binary trie. For each number, greedily choose opposite bit at each level.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary trie: greedily pick opposite bit for max XOR

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary trie: greedily pick opposite bit for max XOR`

### Time Complexity: O(N×32)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×32)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N×32) | O(N×32) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
