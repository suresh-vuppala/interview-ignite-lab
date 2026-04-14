Word break problem using trie for efficient dictionary lookup.

<br>

> Same as word-break in DP section but using trie for O(L) prefix checks
>
> **Key insight:** Build trie from dictionary. DP: dp[i] = true if s[0..i-1] can be segmented. At each position, walk trie to find matching prefixes.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: DP with hash set lookup

**Intuition:**
The most straightforward approach. Hash set lookup for each substring is O(L) creating + O(1) lookup.

**Algorithm:**
1. Initialize a hash set/map for tracking
2. Iterate through each element
3. Check against the hash set/map for the required condition
4. Update the hash set/map with the current element

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
> Hash set lookup for each substring is O(L) creating + O(1) lookup.

> **Key Insight for Improvement:**
> Trie: walk from current position following trie. Each isEnd = valid word ending. Combine with DP.

<br>

---

## Solution 2: Trie + DP (Optimal)

**Intuition:** Build trie from dictionary. DP: dp[i] = true if s[0..i-1] can be segmented. At each position, walk trie to find matching prefixes.

**Algorithm:**
1. Build trie from wordDict
2. dp[0]=true
3. For i=0 to N-1: if dp[i]:
   - Walk trie from position i
   - For each isEnd reached at position j: dp[j+1]=true
4. Return dp[N]

### Time Complexity: O(N×L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
s='leetcode', dict=['leet','code']
Trie walk from 0: l→e→e→t(end!)→dp[4]=true
Trie walk from 4: c→o→d→e(end!)→dp[8]=true ✓
```

### Space Complexity: O(N×L + N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DP with hash set lookup | O(N²×L) | Varies | Baseline |
| Trie + DP | O(N×L) | O(N×L + N) | Optimal |

**Recommended Solution:** Trie + DP

**Key Insights:**
1. **Trie walks forward:** No substring creation needed
2. **Multiple matches per position:** Trie finds all valid prefixes in one walk
3. **O(N×L) vs O(N²):** Trie walk is bounded by max word length

<br><br>

---

```code```
