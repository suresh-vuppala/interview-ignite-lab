Given start and end times of activities, select the maximum number of non-overlapping activities that can be performed by a single person.

<br>

> Input:
> start = [1, 3, 0, 5, 8, 5]
> end = [2, 4, 6, 7, 9, 9]

> Output:
> 4

> Explanation:
> Activities sorted by end time: [(1,2), (3,4), (5,7), (8,9), (0,6), (5,9)]
> 
> Selection process:
> 1. Select (1,2) - first activity
> 2. Select (3,4) - starts at 3 ≥ 2 (previous end)
> 3. Skip (0,6) - starts at 0 < 4 (overlaps)
> 4. Select (5,7) - starts at 5 ≥ 4
> 5. Select (8,9) - starts at 8 ≥ 7
> 6. Skip (5,9) - starts at 5 < 8
> 
> Maximum activities: 4

<br>

---

## Solution: Greedy Activity Selection

Greedy strategy: Always pick activity that finishes earliest
1. Sort activities by end time
2. Select first activity
3. For each remaining activity, if start ≥ last end time, select it

**Why greedy works:** Choosing activity with earliest end time leaves maximum room for future activities.

```code```

<br>

### Time Complexity Analysis

**Sorting Phase: O(n log n)**
- Must sort n activities by end time
- Uses comparison-based sorting (merge sort, quick sort, etc.)

**Selection Phase: O(n)**
- Single pass through sorted activities
- For each activity: O(1) comparison with last selected end time
- Total: n × O(1) = O(n)

**Overall: O(n log n)**
- Dominated by sorting step
- Selection is linear but sorting is bottleneck

> **Time Complexity:** O(n log n) - sorting dominates
> **Space Complexity:** O(1) if sorting in-place, O(n) for storing result

<br>
<br>

---