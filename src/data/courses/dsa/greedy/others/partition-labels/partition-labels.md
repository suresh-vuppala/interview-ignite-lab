Partition string so each letter appears in at most one part. Maximize number of partitions.

<br>

> s='ababcbacadefegdehijhklij' → [9,7,8]
>
> **Key insight:** Track last occurrence of each character. Expand partition to include all last occurrences of characters seen so far.

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Exponential — checking all possible partitions.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Exponential — checking all possible partitions.

> **Key Insight for Improvement:**
> Greedy: scan tracking farthest last occurrence of any seen character. When current index reaches that farthest → partition ends here.

<br>

---

## Solution 2: Last Occurrence + Greedy Expand (Optimal)

**Intuition:** Track last occurrence of each character. Expand partition to include all last occurrences of characters seen so far.

**Algorithm:**
1. Compute last[c] = last index of each character
2. start=0, end=0
3. For each i:
   - end = max(end, last[s[i]])
   - If i == end: partition [start..end], start = i+1

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
s='ababcbacadefegdehijhklij'
last: a=8, b=5, c=7, d=14, e=15, ...
i=0('a'): end=max(0,8)=8. Not at end yet.
...i=8: end=8, i==end → partition [0..8] size=9 ✓
Continue for next partitions...
```

### Space Complexity: O(26)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(2^N) | Varies | Baseline |
| Last Occurrence + Greedy Expand | O(N) | O(26) | Greedy: scan tracking farthest last occurrence of any seen c |

**Recommended Solution:** Last Occurrence + Greedy Expand — O(N) time, O(26) space.

**Key Insights:**
1. **Farthest last occurrence:** Ensures all instances of seen characters are included
2. **Partition when i == end:** All characters in [start..end] don't appear later
3. **O(26) space:** Just the last occurrence map

<br>
<br>

---

```code```
