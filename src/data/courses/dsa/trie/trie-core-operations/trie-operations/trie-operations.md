Implement Trie with insert, search, and startsWith operations.

<br>

> insert('apple'), search('apple')→true, startsWith('app')→true
>
> **Key insight:** Node with children[26] and isEnd flag. Insert: create path char by char. Search: follow path, check isEnd. Prefix: follow path, existence suffices.

<br>

---

## Constraints
- 1 ≤ word.length ≤ 2000
- 1 ≤ total operations ≤ 3 × 10⁴
- Lowercase English letters

<br>

---

## All Possible Edge Cases
1. **Search empty trie**
2. **Prefix of existing word vs complete word**
3. **Insert same word twice
4. **Case sensitivity**

<br>

---

## Solution 1: Hash Set of words

**Intuition:**
The most straightforward approach. Hash set doesn't support prefix queries efficiently.

**Algorithm:**
1. Initialize a hash set/map for tracking
2. Iterate through each element
3. Check against the hash set/map for the required condition
4. Update the hash set/map with the current element

### Time Complexity: O(N×L) search
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Hash set doesn't support prefix queries efficiently.

> **Key Insight for Improvement:**
> Trie enables O(L) prefix lookup — check if ANY word starts with given prefix.

<br>

---

## Solution 2: Trie Node Array (Optimal)

**Intuition:** Node with children[26] and isEnd flag. Insert: create path char by char. Search: follow path, check isEnd. Prefix: follow path, existence suffices.

**Algorithm:**
1. TrieNode: children[26], isEnd
2. Insert: for each char → create child if missing → mark last as isEnd
3. Search: follow path → return isEnd at last node
4. StartsWith: follow path → return true if path exists

### Time Complexity: O(L) per op
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
insert 'apple': root→a→p→p→l→e(end)
search 'app': root→a→p→p, isEnd=false → false
startsWith 'app': root→a→p→p exists → true
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set of words | O(N×L) search | Varies | Baseline |
| Trie Node Array | O(L) per op | O(N×L) | Optimal |

**Recommended Solution:** Trie Node Array

**Key Insights:**
1. **children[26]:** Each node has 26 possible children (a-z)
2. **isEnd flag:** Distinguishes complete words from prefixes
3. **O(L) all operations:** L = word length, independent of dictionary size
4. **Foundation:** Autocomplete, spell check, word search II

<br><br>

---

```code```
