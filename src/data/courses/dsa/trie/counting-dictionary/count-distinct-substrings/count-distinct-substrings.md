Count the number of distinct substrings of a given string.

<br>

> s='abab' → 7 distinct substrings: a,b,ab,ba,aba,bab,abab (plus empty)
>
> **Key insight:** Insert ALL suffixes into a trie. Each node in the trie represents a unique prefix of some suffix = a unique substring. Count = number of nodes.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Generate all substrings + hash set

**Intuition:**
The most straightforward approach. Hash set approach works but has high constant factor and collision risk.

**Algorithm:**
1. Initialize a hash set/map for tracking
2. Iterate through each element
3. Check against the hash set/map for the required condition
4. Update the hash set/map with the current element

### Time Complexity: O(N²) time, O(N²) space
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Hash set approach works but has high constant factor and collision risk.

> **Key Insight for Improvement:**
> Suffix trie: insert s[0..], s[1..], ..., s[N-1..]. Each trie node = distinct substring. Count nodes = count distinct substrings.

<br>

---

## Solution 2: Suffix Trie — Count Nodes (Optimal)

**Intuition:** Insert ALL suffixes into a trie. Each node in the trie represents a unique prefix of some suffix = a unique substring. Count = number of nodes.

**Algorithm:**
1. For i = 0 to N-1: insert suffix s[i..N-1] into trie
2. Count total nodes in trie (excluding root)
3. Each node = one distinct substring
4. Add 1 for empty string if needed

### Time Complexity: O(N²)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
s='aba': suffixes = 'aba', 'ba', 'a'
Trie: root→a(→b→a), root→b(→a)
Nodes: a, ab, aba, b, ba = 5 distinct substrings + empty = 6
```

### Space Complexity: O(N²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Generate all substrings + hash set | O(N²) time, O(N²) space | Varies | Baseline |
| Suffix Trie — Count Nodes | O(N²) | O(N²) | Optimal |

**Recommended Solution:** Suffix Trie — Count Nodes

**Key Insights:**
1. **Each trie node = unique substring:** Fundamental trie property
2. **N suffixes × avg L/2 length:** O(N²) nodes worst case
3. **Suffix array alternative:** O(N log N) with LCP array for counting

<br><br>

---

```code```
