Implement ternary search tree as a trie alternative.

<br>

> More space-efficient than 26-children trie. Three pointers: less, equal, greater.
>
> **Key insight:** Three children per node: lt (char < current), eq (char == current, advance to next char), gt (char > current).

<br>

---

## Constraints
- Sparser alphabets benefit most

<br>

---

## Solution 1: 26-children trie

**Intuition:**
The most straightforward approach. 26 children per node wastes space for sparse alphabets.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(L) per op, O(N×26×L) space
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> 26 children per node wastes space for sparse alphabets.

> **Key Insight for Improvement:**
> TST: 3 pointers per node. Like BST for characters at each level. Space = O(N×L) nodes × 3 pointers.

<br>

---

## Solution 2: Ternary Search Tree (Optimal)

**Intuition:** Three children per node: lt (char < current), eq (char == current, advance to next char), gt (char > current).

**Algorithm:**
1. Node: char, lt, eq, gt, isEnd
2. Insert: compare char → lt/gt if different, eq if match (advance to next char)
3. Search: same comparison logic
4. Prefix search: reach end of prefix via eq links, DFS for completions

### Time Complexity: O(L) per op
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Insert 'cat','cap': root='c'→eq→'a'→eq→('t' end, 'p'→lt of 't')
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| 26-children trie | O(L) per op, O(N×26×L) space | Varies | Baseline |
| Ternary Search Tree | O(L) per op | O(N×L) | Optimal |

**Recommended Solution:** Ternary Search Tree

**Key Insights:**
1. **3 pointers vs 26:** Much more space-efficient for sparse alphabets
2. **BST at each level:** Sorts characters naturally
3. **Prefix search:** Follow eq links for prefix, DFS for completions

<br><br>

---

```code```
