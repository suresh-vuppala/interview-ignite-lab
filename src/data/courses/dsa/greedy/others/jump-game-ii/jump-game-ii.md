Find MINIMUM number of jumps to reach the last index.

<br>

> nums=[2,3,1,1,4] → 2 (index 0→1→4)
>
> **Key insight:** BFS-like: track current range end and farthest reachable. When reaching range end, jump (extend range to farthest).

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
The most straightforward approach. BFS exploring all positions at each level is quadratic.

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
> BFS exploring all positions at each level is quadratic.

> **Key Insight for Improvement:**
> Greedy BFS: track current jump's range [start..end] and farthest reachable. At range end → must jump (increments). Update range.

<br>

---

## Solution 2: Greedy BFS Levels (Optimal)

**Intuition:** BFS-like: track current range end and farthest reachable. When reaching range end, jump (extend range to farthest).

**Algorithm:**
1. jumps=0, currentEnd=0, farthest=0
2. For i = 0 to N-2:
   - farthest = max(farthest, i + nums[i])
   - If i == currentEnd: jumps++, currentEnd = farthest
3. Return jumps

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
nums=[2,3,1,1,4]
i=0: farthest=2, i==currentEnd(0) → jump! currentEnd=2, jumps=1
i=1: farthest=max(2,4)=4, i≠2
i=2: farthest=max(4,3)=4, i==currentEnd(2) → jump! currentEnd=4, jumps=2
Answer: 2 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | Varies | Baseline |
| Greedy BFS Levels | O(N) | O(1) | Greedy BFS: track current jump's range [start..end] and fart |

**Recommended Solution:** Greedy BFS Levels — O(N) time, O(1) space.

**Key Insights:**
1. **BFS levels:** Each "level" = one jump. Level boundary = currentEnd.
2. **Farthest tracks next boundary:** Maximum reach from current level
3. **Stop at N-2:** Don't need to jump FROM last index

<br>
<br>

---

```code```
