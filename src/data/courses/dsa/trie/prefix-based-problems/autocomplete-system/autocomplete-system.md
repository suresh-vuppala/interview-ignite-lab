Design autocomplete: given prefix, return top-3 hot sentences by frequency.

<br>

> Input: sentences with frequencies. Type prefix → return top 3 matches
>
> **Key insight:** Trie storing full sentences. Each node tracks frequency. DFS from prefix node collects all completions, sort by frequency.

<br>

---

## Constraints
- 1 ≤ sentences ≤ 1000
- 1 ≤ sentence.length ≤ 100

<br>

---

## All Possible Edge Cases
1. **No matches for prefix: empty list**
2. **Fewer than 3 matches
3. **New sentence added with #
4. **Same prefix different frequencies**

<br>

---

## Solution 1: Scan all sentences each query

**Intuition:**
The most straightforward approach. Scanning all sentences for every keystroke is too slow.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(N×L) per query
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Scanning all sentences for every keystroke is too slow.

> **Key Insight for Improvement:**
> Trie + DFS from prefix endpoint. Collect all completions with frequencies, return top 3.

<br>

---

## Solution 2: Trie + DFS Collection (Optimal)

**Intuition:** Trie storing full sentences. Each node tracks frequency. DFS from prefix node collects all completions, sort by frequency.

**Algorithm:**
1. Build trie from sentences with frequency
2. On input prefix: traverse to prefix end node
3. DFS from that node → collect all (sentence, frequency) pairs
4. Sort by frequency desc, return top 3

### Time Complexity: O(P + N log N) per query
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Type 'i': navigate to 'i' node → DFS finds all sentences starting with 'i' → sort by freq → top 3
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Scan all sentences each query | O(N×L) per query | Varies | Baseline |
| Trie + DFS Collection | O(P + N log N) per query | O(N×L) | Optimal |

**Recommended Solution:** Trie + DFS Collection

**Key Insights:**
1. **DFS from prefix node:** Finds all completions
2. **Frequency tracking:** Enables ranking by popularity
3. **Optimization:** Store pre-computed top-3 at each node for O(P) query

<br><br>

---

```code```
