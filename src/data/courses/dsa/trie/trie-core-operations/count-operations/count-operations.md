Trie with countWordsEqualTo and countWordsStartingWith.

<br>

> insert('apple')×2, countWords('apple')→2, countPrefix('app')→2
>
> **Key insight:** Track wordCount (incremented at word end) and prefixCount (incremented at every node along the path).

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: HashMap counting

### Time Complexity: O(1) lookup but O(N) prefix count

> **Drawback:**
> HashMap can't count prefix matches without scanning all keys.

> **Key Insight for Improvement:**
> Trie with counters: prefixCount at each node = how many words pass through. wordCount at end nodes = exact word count.

<br>

---

## Solution 2: Trie with Counters (Optimal)

**Intuition:** Track wordCount (incremented at word end) and prefixCount (incremented at every node along the path).

**Algorithm:**
1. Each node: children[26], prefixCount, wordCount
2. Insert: for each char → prefixCount++ at each node → wordCount++ at end
3. CountWords: follow path → return wordCount at end
4. CountPrefix: follow path → return prefixCount at last node

### Time Complexity: O(L) per op
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
insert 'apple' twice: each node on path gets prefixCount=2, end gets wordCount=2
countPrefix('app')→prefixCount at 'p'(3rd) = 2 ✓
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| HashMap counting | O(1) lookup but O(N) prefix count | Varies | Baseline |
| Trie with Counters | O(L) per op | O(N×L) | Optimal |

**Recommended Solution:** Trie with Counters

**Key Insights:**
1. **Two counters per node:** prefixCount for prefix queries, wordCount for exact
2. **Delete support:** Decrement counters along path
3. **Applications:** Autocomplete ranking by frequency

<br><br>

---

```code```
