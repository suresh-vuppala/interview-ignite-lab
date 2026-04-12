Binary trie for XOR operations on integers.

<br>

> **Key insight:** Store integers bit by bit (MSB to LSB). Each node has children[0] and children[1].

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary trie: each level = one bit position

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary trie: each level = one bit position`

### Time Complexity: O(32) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N×32)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(32) per op | O(N×32) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
