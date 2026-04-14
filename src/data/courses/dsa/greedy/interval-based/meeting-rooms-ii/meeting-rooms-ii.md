Find the minimum number of meeting rooms required for a schedule.

<br>

> intervals=[[0,30],[5,10],[15,20]] → 2
>
> **Key insight:** Sort by start time. Use min-heap of end times to track active meetings. If earliest ending meeting ends before new one starts → reuse room.

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
The most straightforward approach. Trying all room assignments is exponential.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Trying all room assignments is exponential.

> **Key Insight for Improvement:**
> Min-heap of end times: if heap.top ≤ current.start → room freed (pop). Always push current end. Heap size = rooms needed.

<br>

---

## Solution 2: Sort + Min-Heap of End Times (Optimal)

**Intuition:** Sort by start time. Use min-heap of end times to track active meetings. If earliest ending meeting ends before new one starts → reuse room.

**Algorithm:**
1. Sort meetings by start time
2. Min-heap of end times
3. For each meeting:
   - If heap not empty and heap.top ≤ start → pop (room freed)
   - Push current end time
4. Heap size = minimum rooms needed

### Time Complexity: O(N log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
[[0,30],[5,10],[15,20]] sorted by start
push 30 → heap=[30], rooms=1
5<30 → push 10 → heap=[10,30], rooms=2
15>10 → pop 10, push 20 → heap=[20,30], rooms=2
Answer: 2 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(2^N) | Varies | Baseline |
| Sort + Min-Heap of End Times | O(N log N) | O(N) | Min-heap of end times: if heap.top ≤ current.start → room fr |

**Recommended Solution:** Sort + Min-Heap of End Times — O(N log N) time, O(N) space.

**Key Insights:**
1. **Min-heap tracks earliest ending meeting:** Can we free a room?
2. **Heap size = concurrent meetings = rooms needed**
3. **Alternative:** Sweep line — sort start/end events, track running count

<br>
<br>

---

```code```
