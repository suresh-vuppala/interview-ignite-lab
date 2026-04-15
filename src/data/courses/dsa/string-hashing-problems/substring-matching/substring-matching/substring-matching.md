Find all occurrences of pattern in text using KMP or Rabin-Karp.

<br>

> text='aabaacaadaabaaba', pattern='aaba' → [0,9,12]
>
> **Key insight:** KMP: build failure function (longest proper prefix that is also suffix). Use it to skip unnecessary comparisons.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵ (text)
- 1 ≤ M ≤ N (pattern)

<br>

---

## All Possible Edge Cases
1. **Pattern longer than text: no match
2. **Pattern at start / end of text
3. **Overlapping matches
4. **All characters same**

<br>

---

## Solution 1: Brute force

**Intuition:**
The most straightforward approach. Restart comparison from beginning on mismatch.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N×M)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Restart comparison from beginning on mismatch.

> **Key Insight for Improvement:**
> KMP: failure function enables skipping to next potential match position on mismatch. O(N+M) total.

<br>

---

## Solution 2: KMP Algorithm (Optimal)

**Intuition:** KMP: build failure function (longest proper prefix that is also suffix). Use it to skip unnecessary comparisons.

**Algorithm:**
1. Build failure function F[i] = length of longest proper prefix of pattern[0..i] that is also suffix
2. Match: on mismatch at j, jump to F[j-1] (skip already matched prefix)
3. On full match: record position, continue with F[M-1]

### Time Complexity: O(N+M)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
pattern='aaba': F=[0,1,0,1]
text matching: on mismatch, use F to skip → never re-examine text chars
```

### Space Complexity: O(M)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute force | O(N×M) | Varies | Baseline |
| KMP Algorithm | O(N+M) | O(M) | Optimal |

**Recommended Solution:** KMP Algorithm

**Key Insights:**
1. **Failure function:** Computed in O(M), reused for all matches
2. **No backtracking in text:** Each text char examined once
3. **KMP vs Rabin-Karp:** KMP guaranteed O(N+M), RK has O(NM) worst case

<br><br>

---

```code```
