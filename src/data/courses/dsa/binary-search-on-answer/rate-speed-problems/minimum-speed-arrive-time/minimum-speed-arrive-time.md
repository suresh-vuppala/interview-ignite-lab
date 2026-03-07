# Minimum Speed to Arrive on Time

## Problem Statement

You are given a floating-point number `hour`, representing the amount of time you have to reach the office. To commute to the office, you must take `n` trains in sequential order. You are also given an integer array `dist` of length `n`, where `dist[i]` describes the distance (in kilometers) of the `i-th` train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait an additional 0.5 hours before you can depart on the 2nd train ride at the 2 hour mark.

Return the minimum positive integer speed (in kilometers per hour) that all the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

## Visual Example

```
Input: dist = [1, 3, 2], hour = 6

Visualization at different speeds:

Speed = 1 km/h:
Train 0: 1/1 = 1.0 hours → wait until hour 1
Train 1: 3/1 = 3.0 hours → wait until hour 4
Train 2: 2/1 = 2.0 hours (no wait, last train)
Total: 1 + 3 + 2 = 6.0 hours ✓

Speed = 2 km/h:
Train 0: 1/2 = 0.5 hours → wait until hour 1
Train 1: 3/2 = 1.5 hours → wait until hour 3
Train 2: 2/2 = 1.0 hours (no wait, last train)
Total: 1 + 2 + 1 = 4.0 hours ✓

Answer: 1 (minimum speed that works)
```

## Algorithm Explanation

### Approach: Binary Search on Answer

The key insight is that if we can arrive on time at speed `k`, we can also arrive on time at any speed greater than `k`. This monotonic property enables binary search.

**Important Rules:**
1. For all trains except the last, we must wait until the next integer hour
2. For the last train, we can arrive at any fractional time
3. Time for train i = ⌈dist[i] / speed⌉ (except last train)
4. Time for last train = dist[n-1] / speed (exact, no ceiling)

**Search Space:**
- Minimum speed: 1 km/h
- Maximum speed: 10^7 (constraint-based upper bound)

**Impossibility Check:**
- If hour < n - 1, impossible (need at least 1 hour for first n-1 trains)

### Step-by-Step Process

```
dist = [1, 3, 2], hour = 6

Check impossibility: 6 >= 3 - 1 = 2 ✓

Initial: left = 1, right = 10^7

Iteration 1: mid = 5000000
  Time: ⌈1/5000000⌉ + ⌈3/5000000⌉ + 2/5000000 ≈ 2.0 hours ≤ 6 ✓
  Can arrive! Try slower: right = 4999999

... (binary search continues)

Eventually finds: speed = 1
  Time: ⌈1/1⌉ + ⌈3/1⌉ + 2/1 = 1 + 3 + 2 = 6.0 ≤ 6 ✓

Answer: 1
```

## Complexity Analysis

**Time Complexity:** O(n log m)
- **Why?** Binary search runs log(10^7) ≈ 23 iterations, each checking n trains
- n = number of trains, m = maximum speed bound

**Space Complexity:** O(1)
- **Why?** Only using constant extra space for variables

## Edge Cases

1. **Impossible case:** hour < n - 1 → return -1
2. **Single train:** No waiting needed → speed = ⌈dist[0] / hour⌉
3. **Exact integer hours:** All trains finish at integer times
4. **Very tight deadline:** Requires high speed
5. **Large distances:** Need to handle precision carefully
6. **hour exactly equals n - 1:** Minimum possible time

## Common Mistakes

1. Not handling the last train differently (no ceiling needed)
2. Using integer division instead of floating-point for last train
3. Wrong impossibility check
4. Integer overflow in speed calculations
5. Not using ceiling for non-last trains
6. Setting wrong upper bound for binary search

```code```
