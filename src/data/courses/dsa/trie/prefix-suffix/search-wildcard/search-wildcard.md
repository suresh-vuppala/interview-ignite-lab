Search in trie with '.' matching any single character.

<br>

> addWord('bad'), search('b.d')→true, search('.ad')→true
>
> **Key insight:** On '.', try ALL 26 children recursively. On regular char, follow specific child.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁴
- 1 ≤ word.length ≤ 25
- '.' matches any letter

<br>

---

## Solution 1: Brute force string matching

**Intuition:**
The most straightforward approach. Checking against all words.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N×L) per search
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking against all words.

> **Key Insight for Improvement:**
> DFS trie search: branch on '.' (try all children), direct match on regular chars.

<br>

---

## Solution 2: DFS Trie with Branching (Optimal)

**Intuition:** On '.', try ALL 26 children recursively. On regular char, follow specific child.

**Algorithm:**
1. On regular char: follow specific child
2. On '.': try all 26 children recursively
3. Return true if any path reaches isEnd at word end

### Time Complexity: O(26^dots × L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
search 'b.d' in trie with 'bad': b→(try all 26 for '.')→a(exists)→d(isEnd)→true ✓
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute force string matching | O(N×L) per search | Varies | Baseline |
| DFS Trie with Branching | O(26^dots × L) | O(N×L) | Optimal |

**Recommended Solution:** DFS Trie with Branching

**Key Insights:**
1. **Branching on '.':** Exponential worst case but practical with pruning
2. **LeetCode 211:** Add and Search Word
3. **DFS with backtracking:** Try all valid paths

<br><br>

---

```code```
