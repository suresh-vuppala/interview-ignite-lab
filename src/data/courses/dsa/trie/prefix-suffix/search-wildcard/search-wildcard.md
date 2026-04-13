Search in trie with '.' matching any single character.

<br>

> addWord('bad'), search('b.d')→true, search('.ad')→true
>
> **Key insight:** On '.', try ALL 26 children recursively. On regular char, follow specific child.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Brute force string matching

### Time Complexity: O(N×L) per search

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
