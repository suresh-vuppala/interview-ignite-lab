Find maximum XOR of a number with any array element ≤ a constraint.

<br>

> nums with constraint limit
>
> **Key insight:** Binary trie with range constraint checking — only follow paths that keep value ≤ limit.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check all valid pairs

### Time Complexity: O(N²)

> **Drawback:**
> Quadratic.

> **Key Insight for Improvement:**
> Binary trie: at each bit, check if choosing opposite bit keeps value ≤ constraint. If not, must choose same bit.

<br>

---

## Solution 2: Constrained Binary Trie (Optimal)

**Intuition:** Binary trie with range constraint checking — only follow paths that keep value ≤ limit.

**Algorithm:**
1. Insert numbers into trie
2. Query: at each bit, try opposite bit first
3. If taking opposite would exceed constraint → must take same bit
4. Track accumulated value to check constraint

### Time Complexity: O(N×32)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Similar to max XOR but with constraint checking at each level
```

### Space Complexity: O(N×32)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all valid pairs | O(N²) | Varies | Baseline |
| Constrained Binary Trie | O(N×32) | O(N×32) | Optimal |

**Recommended Solution:** Constrained Binary Trie

**Key Insights:**
1. **Constraint check at each level:** Can we afford to take the XOR-maximizing path?
2. **Fallback to same bit:** When opposite would violate constraint

<br><br>

---

```code```
