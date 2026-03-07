# Minimum Time to Complete Trips

## Problem Statement

You are given an array `time` where `time[i]` denotes the time taken by the `i-th` bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer `totalTrips`, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least `totalTrips` trips.

## Visual Example

```
Input: time = [1, 2, 3], totalTrips = 5

Visualization at different times:

Time = 3:
Bus 0 (time=1): 3/1 = 3 trips
Bus 1 (time=2): 3/2 = 1 trip
Bus 2 (time=3): 3/3 = 1 trip
Total: 3 + 1 + 1 = 5 trips ✓

Time = 2:
Bus 0 (time=1): 2/1 = 2 trips
Bus 1 (time=2): 2/2 = 1 trip
Bus 2 (time=3): 2/3 = 0 trips
Total: 2 + 1 + 0 = 3 trips ✗

Answer: 3 (minimum time to complete 5 trips)

Timeline visualization at time = 3:
Bus 0: |T|T|T|     (3 trips)
Bus 1: |--T|--T|   (1 trip, would complete 2nd at time 4)
Bus 2: |----T|     (1 trip)
       0 1 2 3
```

## Algorithm Explanation

### Approach: Binary Search on Answer

The key insight is that if we can complete `totalTrips` in time `t`, we can also complete them in any time greater than `t`. This monotonic property allows binary search.

**Trips Calculation:**
- At time `t`, bus `i` completes `t / time[i]` trips (integer division)
- Total trips at time `t` = sum of all individual bus trips

**Search Space:**
- Minimum time: 1 (at least 1 unit of time needed)
- Maximum time: min(time) × totalTrips (slowest case: fastest bus does all trips)

**Binary Search Logic:**
1. For each candidate time `mid`, calculate total trips possible
2. If total trips ≥ totalTrips, try smaller time (search left)
3. If total trips < totalTrips, need more time (search right)

### Step-by-Step Process

```
time = [1, 2, 3], totalTrips = 5

Initial: left = 1, right = 1 × 5 = 5

Iteration 1: mid = 3
  Trips: 3/1 + 3/2 + 3/3 = 3 + 1 + 1 = 5 ≥ 5 ✓
  Enough trips! Try less time: right = 2

Iteration 2: mid = 1
  Trips: 1/1 + 1/2 + 1/3 = 1 + 0 + 0 = 1 < 5 ✗
  Not enough! Need more time: left = 2

Iteration 3: mid = 2
  Trips: 2/1 + 2/2 + 2/3 = 2 + 1 + 0 = 3 < 5 ✗
  Not enough! Need more time: left = 3

left > right, stop
Answer: 3
```

## Complexity Analysis

**Time Complexity:** O(n log(m × k))
- **Why?** Binary search runs log(min_time × totalTrips) iterations, each checking n buses
- n = number of buses, m = minimum time per trip, k = totalTrips

**Space Complexity:** O(1)
- **Why?** Only using constant extra space for variables

## Edge Cases

1. **Single bus:** Simple case → answer = time[0] × totalTrips
2. **totalTrips = 1:** Minimum time among all buses
3. **All buses same speed:** Uniform distribution
4. **One very fast bus:** Dominates trip completion
5. **Large totalTrips:** Need to handle potential overflow
6. **Very different bus speeds:** Fast buses complete many more trips

## Common Mistakes

1. Setting wrong upper bound (using max(time) instead of min(time))
2. Integer overflow when calculating trips or time bounds
3. Using floating-point division instead of integer division
4. Wrong binary search boundary updates
5. Not considering that multiple buses work simultaneously
6. Off-by-one errors in trip counting

```code```
