Find the kth smallest element in an N×N matrix where each row and column is sorted.

<br>

> matrix=[[1,5,9],[10,11,13],[12,13,15]], k=8 → 13
>
> **Key insight:** Min-heap BFS: start with (matrix[0][0], 0, 0). Pop min, push right and down neighbors (if not visited). Kth pop = answer.

<br>

---

## Constraints
- 1 ≤ N ≤ 300
- -10⁹ ≤ matrix[i][j] ≤ 10⁹
- 1 ≤ K ≤ N² apply

<br>

---

## All Possible Edge Cases
1. **K = 1:** top-left corner
2. **K = N²:** bottom-right corner
3. **All elements equal**

<br>

---

## Solution 1: Flatten and sort

**Intuition:**
The most straightforward approach. Flattening ignores the sorted structure of the matrix entirely.

**Algorithm:**
1. Sort the input array
2. Iterate through the sorted array
3. Check the required condition at each step

### Time Complexity: O(N² log N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Flattening ignores the sorted structure of the matrix entirely.

> **Key Insight for Improvement:**
> Min-heap starting with top-left. Pop minimum, push right and down neighbors. Kth extraction = kth smallest.

<br>

---

## Solution 2: Min-Heap Matrix BFS (Optimal)

**Intuition:** Min-heap BFS: start with (matrix[0][0], 0, 0). Pop min, push right and down neighbors (if not visited). Kth pop = answer.

**Algorithm:**
1. Push (matrix[0][0], 0, 0) to min-heap
2. Pop K times:
   - Pop (val, r, c)
   - Push (matrix[r+1][c], r+1, c) if valid and not visited
   - Push (matrix[r][c+1], r, c+1) if valid and not visited
3. Kth pop = answer

### Time Complexity: O(K log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
matrix=[[1,5,9],[10,11,13],[12,13,15]], k=3
Pop 1→push (5,0,1) and (10,1,0)
Pop 5→push (9,0,2) and (11,1,1)
Pop 9 → 3rd smallest = 9
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Flatten and sort | O(N² log N²) | Varies | Baseline |
| Min-Heap Matrix BFS | O(K log N) | O(N) | Min-heap starting with top-left. Pop minimum, push right and |

**Recommended Solution:** Min-Heap Matrix BFS — O(K log N) time, O(N) space.

**Key Insights:**
1. **Exploits sorted structure:** Only explore neighbors of extracted elements
2. **Binary search alternative:** Search on value range [min, max], count elements ≤ mid
3. **Visited set needed:** Prevent duplicate pushes for same cell

<br>
<br>

---

```code```
