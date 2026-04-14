Check if kth bit is set, set it, unset it, or toggle it.

<br>

> n=5(101), k=1: check→0, set→7(111), toggle→7(111)
>
> **Key insight:** Use bitmask (1<<k). Check: n&mask. Set: n|mask. Unset: n&~mask. Toggle: n^mask.

<br>

---

## Constraints
- 0 ≤ N ≤ 2³¹ - 1
- 0 ≤ K ≤ 30

<br>

---

## All Possible Edge Cases
1. **K beyond bit width**
2. **N = 0:** no bits set
3. **All bits set**

<br>

---

## Solution 1: N/A — direct operations

**Intuition:**
The most straightforward approach. N/A — these are O(1) bit tricks.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(1)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> N/A — these are O(1) bit tricks.

> **Key Insight for Improvement:**
> Bitmask (1<<k) isolates the kth bit for any operation.

<br>

---

## Solution 2: Bitmask Operations (Optimal)

**Intuition:** Use bitmask (1<<k). Check: n&mask. Set: n|mask. Unset: n&~mask. Toggle: n^mask.

**Algorithm:**
Check: (n >> k) & 1, or n & (1<<k)
Set: n | (1<<k)
Unset: n & ~(1<<k)
Toggle: n ^ (1<<k)

### Time Complexity: O(1)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
n=5(101): check bit 1: (101>>1)&1=10&1=0 (not set)
Set bit 1: 101|010=111=7
Toggle bit 1: 101^010=111=7
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — direct operations | O(1) | Varies | Baseline |
| Bitmask Operations | O(1) | O(1) | Optimal approach |

**Recommended Solution:** Bitmask Operations — O(1) time.

**Key Insights:**
1. **1<<k creates mask:** Single bit at position k
2. **~mask inverts:** For unsetting
3. **Essential toolkit:** Used in generate subsets, DP bitmask, etc.

<br><br>

---

```code```
