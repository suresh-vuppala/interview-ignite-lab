Check if string with '(', ')' and '*' (* can be (, ), or empty) is valid.

<br>

> s='(*)' → true
>
> **Key insight:** Track range [lo, hi] of possible open parenthesis count. lo = treat * as ), hi = treat * as (. Valid if lo ever ≤ 0 at end.

<br>

---

## Constraints
- 1 ≤ N ≤ 100
- s[i] ∈ {'(', ')', '*'} apply

<br>

---

## All Possible Edge Cases
1. **All stars:** always valid
2. **No stars:** standard valid parentheses
3. **Empty string:** valid
4. **All opening/closing**

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Each * has 3 choices — exponential.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(3^N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Each * has 3 choices — exponential.

> **Key Insight for Improvement:**
> Range tracking: lo = minimum possible opens (treat * as ) or empty). hi = maximum possible opens (treat * as (). If lo < 0 → clamp to 0. If hi < 0 → invalid. End: lo == 0 → valid.

<br>

---

## Solution 2: Lo-Hi Range Tracking (Optimal)

**Intuition:** Track range [lo, hi] of possible open parenthesis count. lo = treat * as ), hi = treat * as (. Valid if lo ever ≤ 0 at end.

**Algorithm:**
1. lo = hi = 0
2. For each char:
   - '(': lo++, hi++
   - ')': lo--, hi--
   - '*': lo-- (as ) or empty), hi++ (as ()
   - lo = max(0, lo) — can't have negative opens
   - If hi < 0 → too many )'s → false
3. Return lo == 0

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
s='(*))'
'(': lo=1, hi=1
'*': lo=0, hi=2
')': lo=-1→0, hi=1
')': lo=-1→0, hi=0
lo==0 → true ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(3^N) | Varies | Baseline |
| Lo-Hi Range Tracking | O(N) | O(1) | Range tracking: lo = minimum possible opens (treat * as ) or |

**Recommended Solution:** Lo-Hi Range Tracking — O(N) time, O(1) space.

**Key Insights:**
1. **Range tracks all possibilities:** lo = most conservative, hi = most optimistic
2. **lo clamped to 0:** Can't have fewer than 0 open parens
3. **hi < 0 = impossible:** Even optimistically, too many closing parens

<br>
<br>

---

```code```
