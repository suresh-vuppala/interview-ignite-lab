Design a dictionary that supports search with '.' wildcard matching any single character.

<br>

> Input:
> addWord("bad")
> addWord("dad")
> addWord("mad")
> search("pad") → false
> search(".ad") → true
> search("b..") → true

> Output:
> false, true, true

> Explanation:
> - "pad" not in dictionary → false
> - ".ad" matches "bad", "dad", "mad" → true
> - "b.." matches "bad" → true
> 
> **Key insight:** Use DFS to explore all possible paths when encountering '.'.

<br>

---

## Solution: Trie with DFS for Wildcard

**Algorithm:**
1. **addWord**: Standard trie insertion
2. **search**: DFS traversal
   - Regular character: follow that path only
   - '.': recursively try all 26 children
   - Return true if any path reaches word end

**Key insight:** Wildcard requires exploring multiple paths, DFS handles this naturally.

```code```

<br>

### Time Complexity Analysis

**addWord: O(L)**
- Insert word character by character: O(L)
- Create nodes if needed: O(1) per character

**search: O(26^W × L)**
- W = number of wildcards
- Each wildcard branches to 26 children
- Worst case: all wildcards = O(26^L)
- Best case: no wildcards = O(L)

**Why exponential?**
- Each '.' creates 26 branches
- Multiple wildcards multiply branches
- Example: "..." explores 26³ = 17,576 paths

**Space Complexity: O(N×L)**
- Trie storage: O(N×L) for N words
- DFS recursion stack: O(L)

**Optimization:**
- Early termination when path doesn't exist
- Prune branches with no children

**Applications:**
- Pattern matching
- Regular expression engines
- Spell checkers

> **Time Complexity:** O(L) add, O(26^W × L) search
> **Space Complexity:** O(N×L)

<br>
<br>

---
