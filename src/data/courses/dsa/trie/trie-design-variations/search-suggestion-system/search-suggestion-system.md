Design a search suggestion system that returns top 3 lexicographically smallest products after each character typed.

<br>

> Input:
> products = ["mobile", "mouse", "moneypot", "monitor", "mousepad"]
> searchWord = "mouse"

> Output:
> [
>   ["mobile", "moneypot", "monitor"],  // after 'm'
>   ["mobile", "moneypot", "monitor"],  // after 'mo'
>   ["mouse", "mousepad"],               // after 'mou'
>   ["mouse", "mousepad"],               // after 'mous'
>   ["mouse", "mousepad"]                // after 'mouse'
> ]

> Explanation:
> - After 'm': top 3 are "mobile", "moneypot", "monitor"
> - After 'mou': only "mouse", "mousepad" match
> 
> **Key insight:** Store top 3 products at each trie node for O(1) query.

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

## Solution: Trie with Pre-computed Top 3

**Algorithm:**
1. **Build Phase**:
   - Sort products lexicographically
   - Insert each product into trie
   - At each node, store top 3 products passing through
2. **Query Phase**:
   - For each prefix character:
     - Traverse to that node
     - Return stored top 3 products

**Key insight:** Pre-compute and store results during build for O(1) query.

```code```

<br>

### Time Complexity Analysis

**Build Phase: O(N×L×log N)**
- Sort products: O(N×L×log N)
- Insert N products: O(N)
- Each insertion: O(L) with top-3 update
- Total: O(N×L×log N)

**Query Phase: O(L)**
- For each character in searchWord: O(L)
- Retrieve stored top 3: O(1) per character
- Total: O(L)

**Alternative: DFS without pre-computation**
- Build: O(N×L)
- Query: O(L + K×log K) where K = matching products
- Worse when K is large

**Space Complexity: O(N×L)**
- Trie nodes: O(N×L)
- Top 3 at each node: O(3) = O(1)
- Total: O(N×L)

**Why pre-compute?**
- Query time: O(L) vs O(L + K×log K)
- Space overhead: Minimal (3 pointers per node)
- Perfect for autocomplete (many queries)

**Optimization:**
- Limit stored products to top K
- Use priority queue for updates
- Cache frequent prefixes

**Applications:**
- E-commerce search
- IDE autocomplete
- Search engines
- Command-line completion

> **Time Complexity:** O(N×L×log N) build, O(L) query
> **Space Complexity:** O(N×L)

<br>
<br>

---
