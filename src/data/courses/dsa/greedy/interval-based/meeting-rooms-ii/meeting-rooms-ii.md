Given an array of meeting time intervals, find the minimum number of conference rooms required.

<br>

> Input:
> intervals = [[0,30], [5,10], [15,20]]

> Output:
> 2

> Explanation:
> Timeline of events:
> - Time 0: Meeting 1 starts (room 1) - rooms needed: 1
> - Time 5: Meeting 2 starts (room 2) - rooms needed: 2
> - Time 10: Meeting 2 ends (room 2 free) - rooms needed: 1
> - Time 15: Meeting 3 starts (room 2) - rooms needed: 2
> - Time 20: Meeting 3 ends (room 2 free) - rooms needed: 1
> - Time 30: Meeting 1 ends (room 1 free) - rooms needed: 0
> 
> Maximum rooms needed at any time: 2

<br>


---

## Constraints

- `1 ≤ intervals.length ≤ 10⁴`
- `0 ≤ start < end ≤ 10⁶`

<br>

---

## All Possible Edge Cases

1. **No overlaps:** 1 room needed
2. **All overlap:** n rooms needed
3. **Single meeting:** 1 room
4. **Back-to-back meetings:** [0,10],[10,20] — same room reusable
5. **All same time:** n rooms needed
6. **One long meeting + many short:** May need 2 rooms

<br>

---

## Solution: Two Pointer Approach

Approach:
1. Separate and sort start times and end times
2. Use two pointers to track starts and ends
3. When meeting starts, increment rooms needed
4. When meeting ends, decrement rooms needed
5. Track maximum rooms needed



<br>

### Time Complexity Analysis

**Sorting Phase: O(n log n)**
- Sort start times: O(n log n)
- Sort end times: O(n log n)
- Total: 2 × O(n log n) = O(n log n)

**Two Pointer Traversal: O(n)**
- Process each start and end time once
- Two pointers move through arrays: at most 2n steps
- Each step: O(1) comparison and counter update
- Total: O(n)

**Overall: O(n log n)**
- Sorting dominates the complexity
- Two pointer scan is linear

> **Time Complexity:** O(n log n) - sorting dominates
> **Space Complexity:** O(n) - for storing separate start and end arrays

<br>
<br>

---

---

```code```
