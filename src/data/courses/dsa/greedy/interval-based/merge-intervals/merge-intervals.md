Merge all overlapping intervals into non-overlapping intervals.

<br>

> intervals=[[1,3],[2,6],[8,10],[15,18]] → [[1,6],[8,10],[15,18]]
>
> **Key insight:** Sort by start time. If current interval overlaps with previous, merge (extend end). Otherwise, add as new interval.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁴
- 0 ≤ start ≤ end ≤ 10⁴ apply

<br>

---

## All Possible Edge Cases
1. **No overlaps:** return as-is
2. **All overlap into one:** single merged interval
3. **Already sorted**
4. **Touching intervals [1,2],[2,3]:** merge

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Checking all pairs for overlap is quadratic.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking all pairs for overlap is quadratic.

> **Key Insight for Improvement:**
> Sort by start: overlapping intervals become adjacent. Linear scan to merge.

<br>

---

## Solution 2: Sort + Linear Merge (Optimal)

**Intuition:** Sort by start time. If current interval overlaps with previous, merge (extend end). Otherwise, add as new interval.

**Algorithm:**
1. Sort intervals by start time
2. For each interval:
   - If overlaps with last merged (start ≤ last.end): merge (extend end = max(ends))
   - Else: add as new merged interval
3. Return merged list

### Time Complexity: O(N log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
[1,3],[2,6],[8,10],[15,18]
[1,3]+[2,6]: 2≤3 → merge [1,6]
[1,6]+[8,10]: 8>6 → new interval
[8,10]+[15,18]: 15>10 → new interval
Result: [[1,6],[8,10],[15,18]] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | Varies | Baseline |
| Sort + Linear Merge | O(N log N) | O(N) | Sort by start: overlapping intervals become adjacent. Linear |

**Recommended Solution:** Sort + Linear Merge — O(N log N) time, O(N) space.

**Key Insights:**
1. **Sort makes overlaps adjacent:** Key insight for O(N) merge
2. **Extend end on merge:** end = max(end, current.end)
3. **FAANG top-10:** Extremely frequently asked interval problem

<br>
<br>

---

```code```
