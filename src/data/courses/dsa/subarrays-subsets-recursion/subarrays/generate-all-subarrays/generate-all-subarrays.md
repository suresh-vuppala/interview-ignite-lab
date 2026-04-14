Generate all contiguous subarrays of an array.

<br>

> nums=[1,2,3] → [1],[1,2],[1,2,3],[2],[2,3],[3]
>
> **Key insight:** Two nested loops: outer for start, inner for end. Total N(N+1)/2 subarrays.

<br>

---

## Constraints
- 1 ≤ N ≤ 100

<br>

---

## Solution 1: Same — this IS the standard approach

**Intuition:**
The most straightforward approach. O(N²) subarrays exist — can't generate faster.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

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
> O(N²) subarrays exist — can't generate faster.

> **Key Insight for Improvement:**
> Two nested loops. Cannot be faster than O(N²) since that many subarrays exist.

<br>

---

## Solution 2: Nested Loops (Optimal)

**Intuition:** Two nested loops: outer for start, inner for end. Total N(N+1)/2 subarrays.

**Algorithm:**
1. For i = 0 to N-1:
   - For j = i to N-1:
     - Subarray = arr[i..j]

### Time Complexity: O(N²) or O(N³) with printing
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[1,2,3]: i=0: [1],[1,2],[1,2,3]. i=1: [2],[2,3]. i=2: [3]. Total=6
```

### Space Complexity: O(N) per subarray

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same — this IS the standard approach | O(N²) | Varies | Baseline |
| Nested Loops | O(N²) or O(N³) with printing | O(N) per subarray | Optimal |

**Recommended Solution:** Nested Loops

**Key Insights:**
1. **N(N+1)/2 subarrays:** Can't avoid generating all
2. **Contiguous:** Must be consecutive elements
3. **Foundation:** Many problems iterate over all subarrays

<br><br>

---

```code```
