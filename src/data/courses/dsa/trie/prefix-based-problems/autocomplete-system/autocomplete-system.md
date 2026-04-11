Design a search autocomplete system that returns top 3 matching sentences based on input prefix and frequency.

<br>

> Input:
> sentences = ["i love you", "island", "iroman", "i love leetcode"]
> times = [5, 3, 2, 2]
> input("i") → input(" ") → input("a")

> Output:
> ["i love you", "island", "i love leetcode"] → ["i love you", "i love leetcode"] → []

> Explanation:
> - input("i"): All 4 sentences match, return top 3 by frequency
> - input(" "): "i love you" and "i love leetcode" match
> - input("a"): No sentence starts with "i a"
> 
> **Key insight:** Store sentences at each node, sort by frequency.

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

## Solution: Trie with Sentence Storage

Use trie to store sentences with frequencies:
1. Each node stores list of (sentence, frequency) pairs
2. On character input:
   - Traverse to prefix node
   - Return top 3 sentences sorted by frequency (then lexicographically)
3. On '#' input: Save current sentence

**Key insight:** Store complete sentences at each prefix node.

```code```

<br>

### Time Complexity Analysis

**Insert: O(L×K)** where L = sentence length, K = sentences per node

**Query: O(L + K log K)**
- Traverse to prefix: O(L)
- Sort K matching sentences: O(K log K)
- Return top 3: O(1)

**Optimization:**
- Store only top 3 at each node
- Update during insertion
- Query becomes O(L)

**Space Complexity: O(N×L×K)**
- N sentences, length L
- K sentences stored per node
- Can be optimized to O(N×L×3) by storing only top 3

**Applications:**
- Search engines
- IDE code completion
- Mobile keyboard suggestions

> **Time Complexity:** O(L + K log K) per query
> **Space Complexity:** O(N×L×K) for trie storage

<br>
<br>

---
