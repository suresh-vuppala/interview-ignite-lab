Implement a Compressed Trie (Radix Tree) where chains of single-child nodes are merged.

<br>

> Input:
> insert("romane")
> insert("romanus")
> insert("romulus")
> insert("rubens")

> Output:
> Compressed Trie:
> root → "r" → "om" → ["ane", "anus"] and "ubens"

> Explanation:
> - Standard trie: 20+ nodes
> - Compressed: 7 nodes (merged single-child chains)
> - "rom" shared prefix stored as one edge
> 
> **Key insight:** Merge single-child chains to reduce space.

<br>

---

## Solution: Radix Tree with Edge Compression

**Structure:**
- Each edge stores a string (not single char)
- Node has children map and isEnd flag
- Compress chains when only one child exists

**Operations:**
1. **Insert**:
   - Find longest matching prefix with existing edge
   - Split edge if partial match
   - Add new edge for remaining part
2. **Search**:
   - Match edge strings character by character
   - Check isEnd flag at final node

**Key insight:** Trade insertion complexity for space efficiency.

```code```

<br>

### Time Complexity Analysis

**Insert: O(L)**
- Find matching edge: O(L)
- Split edge if needed: O(L)
- Create new node: O(1)
- Total: O(L)

**Search: O(L)**
- Traverse edges matching string: O(L)
- Check isEnd flag: O(1)

**Delete: O(L)**
- Find and remove node: O(L)
- Merge parent if becomes single-child: O(L)

**Space Complexity: O(N)**
- Standard trie: O(N×L) nodes
- Compressed trie: O(N) nodes (one per word)
- Significant space savings for long unique paths

**When to use?**
- Long strings with few common prefixes
- Memory-constrained environments
- IP routing tables
- File systems

**Trade-offs:**
- Space: Much better than standard trie
- Time: Same O(L) but with higher constants
- Complexity: More complex implementation

**Applications:**
- Linux kernel radix tree
- IP routing (PATRICIA trie)
- Memory-efficient dictionaries

> **Time Complexity:** O(L) for all operations
> **Space Complexity:** O(N) nodes vs O(N×L) in standard trie

<br>
<br>

---
