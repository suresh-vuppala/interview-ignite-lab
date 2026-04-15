Implement compressed (radix/Patricia) trie to reduce space.

<br>

> Merge single-child chains: a→b→c becomes edge 'abc'
>
> **Key insight:** Merge consecutive single-child nodes into one edge with multi-character label. Reduces node count.

<br>

---

## Constraints
- Conceptual — reduces node count

<br>

---

## Solution 1: Standard trie

**Intuition:**
The most straightforward approach. Standard trie wastes nodes on long single-child chains.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(L) per op, O(N×L) space
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Standard trie wastes nodes on long single-child chains.

> **Key Insight for Improvement:**
> Compressed trie: edges store strings, not single chars. Branching only at actual divergence points.

<br>

---

## Solution 2: Compressed/Radix Trie (Optimal)

**Intuition:** Merge consecutive single-child nodes into one edge with multi-character label. Reduces node count.

**Algorithm:**
1. Node edges are strings (not single chars)
2. Insert: find longest matching prefix edge → split if needed
3. Search: match edge strings character by character
4. Fewer nodes but more complex edge splitting

### Time Complexity: O(L) per op
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Words 'test','team': standard trie has t→e→(s→t, a→m)
Compressed: t→e→('st','am') — fewer nodes
```

### Space Complexity: O(total unique chars)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Standard trie | O(L) per op, O(N×L) space | Varies | Baseline |
| Compressed/Radix Trie | O(L) per op | O(total unique chars) | Optimal |

**Recommended Solution:** Compressed/Radix Trie

**Key Insights:**
1. **Fewer nodes:** Merges single-child chains
2. **Edge splitting on insert:** More complex but space-efficient
3. **Used in:** IP routing (Patricia trie), suffix trees

<br><br>

---

```code```
