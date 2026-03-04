Given an array of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

<br>

> Input:
> intervals = [[1,2], [2,3], [3,4], [1,3]]

> Output:
> 1

> Explanation:
> After sorting by end time: [[1,2], [2,3], [1,3], [3,4]]
> 
> Selection process (similar to activity selection):
> 1. Select [1,2] - first interval
> 2. Select [2,3] - starts at 2 ≥ 2 (non-overlapping)
> 3. Skip [1,3] - starts at 1 < 3 (overlaps with [2,3])
> 4. Select [3,4] - starts at 3 ≥ 3 (non-overlapping)
> 
> Non-overlapping intervals: 3
> Intervals to remove: 4 - 3 = 1

<br>

---

## Solution: Greedy Interval Selection

Approach:
1. Sort intervals by end time
2. Count maximum non-overlapping intervals (activity selection)
3. Return total intervals - non-overlapping count

**Greedy choice:** Always keep interval with earliest end time to maximize future selections.

```code```

<br>

### Time Complexity Analysis

**Sorting Phase: O(n log n)**
- Sort n intervals by end time
- Uses comparison-based sorting

**Counting Phase: O(n)**
- Single pass through sorted intervals
- For each interval: O(1) comparison with last selected end
- Total: n × O(1) = O(n)

**Overall: O(n log n)**
- Sorting is the bottleneck
- Counting is linear but doesn't affect overall complexity

**Why this works:**
- Problem is equivalent to finding maximum non-overlapping intervals
- Greedy choice (earliest end time) guarantees optimal solution
- Removing fewest = keeping maximum non-overlapping

> **Time Complexity:** O(n log n) - sorting dominates
> **Space Complexity:** O(1) - only counter variables needed (excluding sort space)

<br>
<br>

---