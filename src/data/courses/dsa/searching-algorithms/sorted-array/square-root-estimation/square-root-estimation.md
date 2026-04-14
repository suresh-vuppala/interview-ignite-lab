Find the integer square root of N (largest x where x² ≤ N).

<br>

> N=8 → 2 (2²=4≤8, 3²=9>8)
>
> **Key insight:** Binary search on answer: find largest x where x*x ≤ N.

<br>

---

## Constraints
- 0 ≤ N ≤ 2³¹ - 1

<br>

---

## All Possible Edge Cases
1. **N = 0:** return 0
2. **N = 1:** return 1
3. **Perfect square:** exact answer
4. **Large N:** avoid overflow in mid*mid

<br>

---

## Solution 1: Try all x from 1

**Intuition:**
The most straightforward approach. Linear scan up to √N.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(√N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linear scan up to √N.

> **Key Insight for Improvement:**
> Binary search: lo=1, hi=N. If mid*mid ≤ N → ans=mid, lo=mid+1. Else hi=mid-1. O(log N).

<br>

---

## Solution 2: Binary Search on Answer (Optimal)

**Intuition:** Binary search on answer: find largest x where x*x ≤ N.

**Algorithm:**
1. lo=1, hi=N, ans=0
2. While lo ≤ hi:
   - mid = lo+(hi-lo)/2
   - If mid ≤ N/mid: ans=mid, lo=mid+1 (use N/mid to avoid overflow)
   - Else: hi=mid-1

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
N=8: lo=1,hi=8, mid=4→16>8→hi=3, mid=2→4≤8→ans=2,lo=3, mid=3→9>8→hi=2→done. ans=2 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all x from 1 | O(√N) | Varies | Baseline |
| Binary Search on Answer | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Binary Search on Answer — O(log N) time.

**Key Insights:**
1. **mid ≤ N/mid:** Avoids mid*mid overflow
2. **Binary search on answer:** Classic template — search in value space
3. **Foundation for:** All BS-on-answer problems

<br><br>

---

```code```
