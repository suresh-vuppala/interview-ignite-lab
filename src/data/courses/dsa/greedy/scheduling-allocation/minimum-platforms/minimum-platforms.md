Find minimum platforms needed at a train station given arrival and departure times.

<br>

> arr=[900,940,950,1100], dep=[910,1200,1120,1150] → 3
>
> **Key insight:** Sort arrivals and departures separately. Two-pointer sweep: arrival = +1 platform, departure = -1 platform. Track maximum.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵
- 0 ≤ arrival < departure ≤ 2359 apply

<br>

---

## All Possible Edge Cases
1. **No overlapping trains:** 1 platform
2. **All trains at same time:** N platforms
3. **Trains arriving as others depart**

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Checking all pairs of trains for overlap is quadratic.

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
> Checking all pairs of trains for overlap is quadratic.

> **Key Insight for Improvement:**
> Sweep line: sort events (arrivals and departures separately). Two pointers merge them in time order. Track running count.

<br>

---

## Solution 2: Sort + Two-Pointer Sweep (Optimal)

**Intuition:** Sort arrivals and departures separately. Two-pointer sweep: arrival = +1 platform, departure = -1 platform. Track maximum.

**Algorithm:**
1. Sort arrivals[] and departures[] independently
2. i=0 (arrival ptr), j=0 (departure ptr), platforms=0, max=0
3. While i < N:
   - If arr[i] ≤ dep[j]: platforms++, i++ (train arrives)
   - Else: platforms--, j++ (train departs)
   - max = max(max, platforms)

### Time Complexity: O(N log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
arr=[900,940,950,1100] dep=[910,1120,1150,1200]
i=0: 900≤910 → plat=1
i=1: 940>910 → plat=0, j=1
i=1: 940≤1120 → plat=1
i=2: 950≤1120 → plat=2
i=3: 1100≤1120 → plat=3 ★
max=3 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | Varies | Baseline |
| Sort + Two-Pointer Sweep | O(N log N) | O(1) | Sweep line: sort events (arrivals and departures separately) |

**Recommended Solution:** Sort + Two-Pointer Sweep — O(N log N) time, O(1) space.

**Key Insights:**
1. **Sort arrivals and departures separately:** Don't need to pair them
2. **Sweep line:** Process events in chronological order
3. **Two pointers:** Merge two sorted arrays of events

<br>
<br>

---

```code```
