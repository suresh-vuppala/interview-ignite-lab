Design WordFilter to find words by prefix and suffix, returning the one with maximum weight.

<br>

> Input:
> words = ["apple", "apply", "sample"], weights = [3, 2, 5]
> f("ap", "le") → 3 ("apple")
> f("a", "") → 5 ("sample" has max weight starting with "a")

> Output:
> 3, 5

> Explanation:
> - f("ap", "le"): Only "apple" matches both → weight 3
> - f("a", ""): "apple"(3), "apply"(2), "sample"(5) match → max is 5
> 
> **Key insight:** Store all suffix#prefix combinations in trie with weights.

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

## Solution: Trie with Suffix#Prefix Combinations

**Algorithm:**
1. For each word, create all suffix#word combinations:
   - "apple" → "e#apple", "le#apple", "ple#apple", "pple#apple", "apple#apple"
2. Store each combination in trie with weight
3. Query "prefix" + "suffix":
   - Search for "suffix#prefix" in trie
   - Return maximum weight found

**Key insight:** Suffix#prefix format allows single trie to handle both conditions.

```code```

<br>

### Time Complexity Analysis

**Build: O(N×L²)**
- For each word of length L: O(L) suffixes
- Each suffix creates L-length trie path: O(L)
- Total per word: O(L²)
- For N words: O(N×L²)

**Query: O(P+S)**
- P = prefix length, S = suffix length
- Search "suffix#prefix": O(S+1+P)
- Return stored weight: O(1)

**Space Complexity: O(N×L²)**
- Store L suffixes per word
- Each suffix creates up to L nodes
- Total: O(N×L²)

**Why this approach?**
- Two tries: O(N×L) space but O(K) query for K matches
- This approach: O(N×L²) space but O(P+S) query
- Trade space for query speed

> **Time Complexity:** O(N×L²) build, O(P+S) query
> **Space Complexity:** O(N×L²)

<br>
<br>

---
