Extend Trie to support counting operations:
- **countWordsEqualTo**: Count how many times exact word exists
- **countWordsStartingWith**: Count words with given prefix

<br>

> Input:
> Operations: ["insert", "apple"], ["insert", "apple"], ["countWordsEqualTo", "apple"], ["countWordsStartingWith", "app"], ["insert", "app"], ["countWordsStartingWith", "app"]

> Output:
> [null, null, 2, 2, null, 3]

> Explanation:
> - insert("apple"): Add "apple" (count = 1)
> - insert("apple"): Add "apple" again (count = 2)
> - countWordsEqualTo("apple"): Returns 2
> - countWordsStartingWith("app"): Returns 2 ("apple" twice)
> - insert("app"): Add "app"
> - countWordsStartingWith("app"): Returns 3 ("apple" twice + "app" once)
> 
> **Key insight:** Track word count and prefix count at each node.

<br>

---

## Solution: Modified Trie with Counters

**Modified Trie Node:**
- Add two counters:
  - `wordCount`: Number of times this word ends here
  - `prefixCount`: Number of words passing through this node

**Operations:**
1. **Insert**: Increment prefixCount along path, increment wordCount at end
2. **countWordsEqualTo**: Traverse to end, return wordCount
3. **countWordsStartingWith**: Traverse to prefix end, return prefixCount

**Key insight:** Counters enable duplicate word tracking.

```code```

<br>

### Time Complexity Analysis

**All Operations: O(L)** where L = word/prefix length

**Insert: O(L)**
- Traverse L characters: O(L)
- Increment counters at each node: O(1) per node
- Total: O(L)

**countWordsEqualTo: O(L)**
- Traverse L characters: O(L)
- Return wordCount: O(1)

**countWordsStartingWith: O(L)**
- Traverse L characters: O(L)
- Return prefixCount: O(1)

**Why counters are efficient?**
- No need to traverse all words
- Counts maintained during insert
- O(L) query time regardless of word count

**Space Complexity: O(N×L)**
- N words of average length L
- Two extra integers per node (negligible)

**Applications:**
- Word frequency analysis
- Autocomplete with popularity
- Prefix statistics

> **Time Complexity:** O(L) for all operations
> **Space Complexity:** O(N×L) for N words

<br>
<br>

---
