Find shortest prefix for each word that uniquely identifies it.

<br>

> words=['zebra','dog','duck','dove'] → ['z','dog','du','dov']
>
> **Key insight:** Insert all words into trie with count at each node. Prefix is unique when node's prefixCount == 1.

<br>

---

## Constraints
- 1 ≤ N ≤ 1000
- 1 ≤ word.length ≤ 1000

<br>

---

## All Possible Edge Cases
1. **All words start with different letters: single char each**
2. **All words share long prefix
3. **Single word: first character**

<br>

---

## Solution 1: Compare all pairs

**Intuition:**
The most straightforward approach. Quadratic pair comparisons.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²×L)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Quadratic pair comparisons.

> **Key Insight for Improvement:**
> Trie with count: walk each word's path until prefixCount == 1 → that prefix uniquely identifies the word.

<br>

---

## Solution 2: Trie with Count (Optimal)

**Intuition:** Insert all words into trie with count at each node. Prefix is unique when node's prefixCount == 1.

**Algorithm:**
1. Insert all words, increment count at each node
2. For each word: walk path until node.count == 1 → prefix found

### Time Complexity: O(N×L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
words=['dog','duck','dove']: d(count=3)→o(1)→'dog' unique at 'dog'
d→u(1)→'du' unique for 'duck'
d→o(1)→wait, 'dog' has o(count=1) so prefix='do'? Need full path check
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Compare all pairs | O(N²×L) | Varies | Baseline |
| Trie with Count | O(N×L) | O(N×L) | Optimal |

**Recommended Solution:** Trie with Count

**Key Insights:**
1. **Count = number of words through this node**
2. **Count==1 means unique:** Only one word passes through
3. **First count==1 node:** Shortest unique prefix

<br><br>

---

```code```
