Insert a new interval into a sorted list of non-overlapping intervals, merging if needed.

<br>

> intervals=[[1,3],[6,9]], newInterval=[2,5] → [[1,5],[6,9]]
>
> **Key insight:** Find overlap region, merge all overlapping intervals with the new one.

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
The most straightforward approach. Already optimal at O(N) since we must examine all intervals.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Already optimal at O(N) since we must examine all intervals.

> **Key Insight for Improvement:**
> Three-phase linear scan: (1) add all intervals before new, (2) merge all overlapping with new, (3) add all after.

<br>

---

## Solution 2: Three-Phase Linear Scan (Optimal)

**Intuition:** Find overlap region, merge all overlapping intervals with the new one.

**Algorithm:**
1. Add all intervals ending before newInterval starts
2. Merge all overlapping intervals with newInterval (extend start/end)
3. Add all intervals starting after newInterval ends

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
[[1,3],[6,9]], new=[2,5]
Phase 1: [1,3] ends at 3 ≥ 2 → overlaps, skip
Phase 2: merge [1,3]+[2,5]→[1,5]. [6,9] starts at 6 > 5 → stop
Phase 3: add [6,9]
Result: [[1,5],[6,9]] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N) | Varies | Baseline |
| Three-Phase Linear Scan | O(N) | O(N) | Three-phase linear scan: (1) add all intervals before new, ( |

**Recommended Solution:** Three-Phase Linear Scan — O(N) time, O(N) space.

**Key Insights:**
1. **Three phases:** Before, merge, after — clean separation
2. **Merge phase:** Extend start = min(starts), end = max(ends)
3. **Already O(N):** Can't do better since intervals must be examined

<br>
<br>

---

```code```
