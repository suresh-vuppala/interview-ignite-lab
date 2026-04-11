Given an array of intervals, merge all overlapping intervals.

<br>

> Input:
> intervals = [[1,3], [2,6], [8,10], [15,18]]

> Output:
> [[1,6], [8,10], [15,18]]

> Explanation:
> After sorting by start time: [[1,3], [2,6], [8,10], [15,18]]
> 
> Merge process:
> 1. Start with [1,3]
> 2. [2,6] overlaps with [1,3] (2 ≤ 3) → merge to [1,6]
> 3. [8,10] doesn't overlap with [1,6] (8 > 6) → add [1,6] to result, start new [8,10]
> 4. [15,18] doesn't overlap with [8,10] (15 > 10) → add [8,10] to result, start new [15,18]
> 5. Add final [15,18] to result
> 
> Result: [[1,6], [8,10], [15,18]]

<br>


---

## Constraints

- `1 ≤ intervals.length ≤ 10⁴`
- `0 ≤ start ≤ end ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **No overlaps:** Return all intervals as-is
2. **All overlap into one:** Return single merged interval
3. **Single interval:** Return it
4. **Adjacent intervals:** [1,2],[2,3] → [1,3] (touching counts as overlapping)
5. **Nested intervals:** [1,10],[2,5] → [1,10]
6. **Unsorted input:** Must sort first by start time
7. **Duplicate intervals:** [1,3],[1,3] → [1,3]

<br>

---

## Solution: Merge Overlapping Intervals

Approach:
1. Sort intervals by start time
2. Iterate through sorted intervals
3. If current interval overlaps with last merged interval, extend the end
4. Otherwise, add current interval to result

**Overlap condition:** current.start ≤ last.end

```code```

<br>

### Time Complexity Analysis

**Sorting Phase: O(n log n)**
- Sort n intervals by start time
- Comparison-based sorting takes O(n log n)

**Merging Phase: O(n)**
- Single pass through sorted intervals
- For each interval: O(1) comparison and merge operation
- Total: n × O(1) = O(n)

**Overall: O(n log n)**
- Sorting dominates the complexity
- Merging is linear but doesn't affect overall complexity

> **Time Complexity:** O(n log n) - dominated by sorting
> **Space Complexity:** O(n) - for storing merged intervals result

<br>
<br>

---
