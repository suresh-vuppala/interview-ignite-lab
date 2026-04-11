Given an array of points on a 2D plane and an integer k, find the k closest points to the origin (0, 0). Distance is calculated using Euclidean distance.

<br>

> Input:
> points = [[1,3], [-2,2], [5,8], [0,1]], k = 2

> Output:
> [[0,1], [-2,2]]

> Explanation:
> Calculate distances from origin:
> - [1,3]: distance = √(1²+3²) = √10 ≈ 3.16
> - [-2,2]: distance = √(4+4) = √8 ≈ 2.83
> - [5,8]: distance = √(25+64) = √89 ≈ 9.43
> - [0,1]: distance = √(0+1) = 1
> 
> Sorted by distance: [0,1] (1), [-2,2] (2.83), [1,3] (3.16), [5,8] (9.43)
> K=2 closest: [[0,1], [-2,2]]
> 
> Max heap process (size k=2):
> - Add [1,3] (dist=10): heap = [[1,3]]
> - Add [-2,2] (dist=8): heap = [[1,3], [-2,2]]
> - Add [5,8] (dist=89): 89 > 10 (top), skip
> - Add [0,1] (dist=1): 1 < 10 (top), remove [1,3], add [0,1]: heap = [[-2,2], [0,1]]

<br>


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single element:** It is both min and max
2. **All same elements:** Heap operations trivial
3. **Already a valid heap:** No restructuring needed
4. **k = 1:** Find min/max directly
5. **k = n:** Need to process entire heap
6. **Negative values:** Min heap with negatives

<br>

---

## Solution: Max Heap of Size K

Use max heap to maintain k closest points:
1. **Build max heap** of size k (stores farthest among k closest)
2. **For each point**:
   - Calculate squared distance (avoid sqrt for efficiency)
   - If heap size < k: add point
   - If distance < heap top: remove top, add current point
3. **Result**: All points in heap are k closest

**Key insight:** Max heap keeps farthest of k closest points at top, easy to compare and replace.

```code```

<br>

### Time Complexity Analysis

**Heap Operations: O(n log k)**
- Process n points: n iterations
- For each point:
  - Calculate distance: O(1)
  - Heap operations (insert/remove): O(log k)
- Total: n × O(log k) = O(n log k)

**Why not O(n log n)?**
- Sorting all points: O(n log n)
- Max heap of size k: O(n log k)
- When k << n, O(n log k) much better
- Example: n=1,000,000, k=10 → O(n log 10) vs O(n log 1,000,000)

**Space Complexity: O(k)**
- Max heap stores exactly k points
- No need to store all n points
- Optimal space usage

**Why max heap (not min heap)?**
- Max heap: Top = farthest among k closest
- Easy to compare new point with farthest
- If new point closer, replace top
- Min heap would have closest at top (hard to decide what to remove)

**Optimization: Squared distance**
- Use x²+y² instead of √(x²+y²)
- Avoids expensive sqrt operation
- Comparison order preserved (if a² < b², then a < b for positive values)
- Significant performance improvement

**Alternative: QuickSelect**
- Partition-based selection: O(n) average
- But modifies input array
- Heap approach: O(n log k), doesn't modify input
- Heap better when k is small

> **Time Complexity:** O(n log k) - process n points with O(log k) heap operations
> **Space Complexity:** O(k) - heap stores k points

<br>
<br>

---
