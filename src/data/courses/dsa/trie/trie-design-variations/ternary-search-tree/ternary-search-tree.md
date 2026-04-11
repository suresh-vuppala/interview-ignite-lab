Implement a Ternary Search Tree (TST) - a space-efficient alternative to standard trie.

<br>

> Input:
> insert("cat")
> insert("cats")
> insert("up")
> search("cat") → true
> search("dog") → false

> Output:
> true, false

> Explanation:
> TST Structure:
> - Each node has 3 children: left (smaller), middle (equal), right (larger)
> - 'c' → middle → 'a' → middle → 't' (end)
> - More space-efficient than 26-way trie
> 
> **Key insight:** Use BST-like structure at each level to save space.

<br>


---

## Constraints

- `1 ≤ number of words ≤ 3 × 10⁴`
- `1 ≤ word length ≤ 2000`
- `Words consist of lowercase English letters (unless stated otherwise)`

<br>

---

## All Possible Edge Cases

1. **Empty trie:** Search returns false, prefix returns false
2. **Single character words:** Trie depth = 1
3. **All same word inserted:** Count or flag must handle duplicates
4. **Prefix is also a complete word:** isEnd flag must be separate from having children
5. **Very long word:** Deep trie path
6. **No matching prefix:** Return false or empty list

<br>

---

## Solution: Ternary Search Tree Structure

**Node Structure:**
```
class TSTNode:
    char c
    left, middle, right  // 3 children
    isEnd
```

**Operations:**
1. **Insert**:
   - Compare current char with node char
   - Go left if smaller, right if larger, middle if equal
   - Mark isEnd when word complete
2. **Search**:
   - Follow same comparison logic
   - Check isEnd at final node

**Key insight:** Combines benefits of BST (space) and Trie (prefix matching).

```code```

<br>

### Time Complexity Analysis

**Insert: O(L + log N)**
- L = word length
- At each level: O(log N) to find character (BST)
- Total: O(L + log N)

**Search: O(L + log N)**
- Same as insert
- Traverse L characters: O(L)
- BST navigation: O(log N) per level

**Space Complexity: O(N)**
- Standard Trie: O(26 × N × L) pointers
- TST: O(3 × N) = O(N) pointers
- Significant space savings

**Comparison:**

| Structure | Space | Search Time |
|-----------|-------|-------------|
| Standard Trie | O(26×N×L) | O(L) |
| TST | O(N) | O(L + log N) |
| BST | O(N) | O(L×log N) |

**When to use TST?**
- Large alphabet (Unicode)
- Memory-constrained systems
- Sparse tries (few words)

**Trade-offs:**
- Space: Much better than trie
- Time: Slightly slower than trie
- Complexity: Moderate implementation

**Applications:**
- Symbol tables
- Spell checkers
- Auto-completion
- IP routing

> **Time Complexity:** O(L + log N) for insert/search
> **Space Complexity:** O(N) vs O(26×N×L) in standard trie

<br>
<br>

---
