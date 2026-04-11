## Problem Statement

You are given an array `stalls[]` of size `N` representing the positions of `N` stalls along a straight line. You have `C` cows to place in these stalls.

The cows are aggressive and will fight if placed too close. Your task is to assign cows to stalls such that the **minimum distance** between any two cows is **as large as possible**.

Return the **largest minimum distance** possible.

**Constraints:**
- `2 ≤ N ≤ 10^5`
- `2 ≤ C ≤ N`
- `1 ≤ stalls[i] ≤ 10^9`

## Examples

### Example 1:
**Input:**
```
stalls = [1, 2, 4, 8, 9]
C = 3
```

**Output:**
```
3
```

**Explanation:**
Place cows at positions 1, 4, and 8:
- Distance between cow 1 and cow 2: 4 - 1 = 3
- Distance between cow 2 and cow 3: 8 - 4 = 4
- Minimum distance = 3 ✓

### Example 2:
**Input:**
```
stalls = [1, 2, 8, 4, 9]
C = 3
```

**Output:**
```
3
```

**Explanation:**
After sorting: [1, 2, 4, 8, 9]
Place cows at 1, 4, 8 → minimum distance = 3

### Example 3:
**Input:**
```
stalls = [10, 1, 2, 7, 5]
C = 3
```

**Output:**
```
4
```

**Explanation:**
After sorting: [1, 2, 5, 7, 10]
Place cows at 1, 5, 10:
- Distance: 5-1=4, 10-5=5
- Minimum = 4 ✓

## Visual Example

For `stalls = [1, 2, 4, 8, 9]`, `C = 3`:

```
Stalls:  1   2   4       8  9
         |   |   |       |  |
         ─────────────────────

Distance = 1 (too small):
Place at: 1, 2, 4 ✓ (can place 3 cows)
But minimum distance = 1

Distance = 3 (optimal):
Place at: 1, 4, 8 ✓
Distances: 3, 4
Minimum = 3 ✓

Distance = 4 (too large):
Place at: 1, ?, ?
Next valid: 5 (not available)
Next valid: 8 (only 2 cows) ✗
Cannot place 3 cows
```

## Binary Search Visualization

```
Sorted: [1, 2, 4, 8, 9]

Search Space: [1, 8]
              ↓
         mid = 4
         
Can place 3 cows with min distance 4?
Cow 1 at position 1
Cow 2 at position 5+ (not available, try 8)
Cow 2 at position 8 (8-1=7 ≥ 4) ✓
Cow 3 at position 12+ (not available)
Only 2 cows placed ✗
No! Try smaller → right = 3

         mid = 2
         
Can place 3 cows with min distance 2?
Cow 1 at position 1
Cow 2 at position 4 (4-1=3 ≥ 2) ✓
Cow 3 at position 8 (8-4=4 ≥ 2) ✓
Yes! 3 cows placed ✓
Try larger → left = 3

         mid = 3
         
Can place 3 cows with min distance 3?
Cow 1 at position 1
Cow 2 at position 4 (4-1=3 ≥ 3) ✓
Cow 3 at position 8 (8-4=4 ≥ 3) ✓
Yes! 3 cows placed ✓
Try larger → left = 4

Answer = 3
```

## Approach: Binary Search on Answer

### Key Insight

We want to **maximize the minimum distance**. Binary search on the distance value.

**Search Space:** `[1, stalls[n-1] - stalls[0]]`
- Lower bound: 1 (minimum possible distance)
- Upper bound: Distance between first and last stall

**Important:** Sort the stalls first!

### Algorithm

1. **Sort Stalls:**
   ```cpp
   sort(stalls.begin(), stalls.end())
   ```

2. **Binary Search:**
   ```cpp
   left = 1
   right = stalls[n-1] - stalls[0]
   
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canPlaceCows(stalls, C, mid)) {
           answer = mid
           left = mid + 1  // try larger distance
       } else {
           right = mid - 1  // try smaller distance
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canPlaceCows(stalls, C, minDist):
       cows = 1  // place first cow at first stall
       lastPos = stalls[0]
       
       for i = 1 to n-1:
           if (stalls[i] - lastPos >= minDist) {
               cows++
               lastPos = stalls[i]
               if (cows == C) return true
           }
       
       return false
   ```

### Step-by-Step Walkthrough

For `stalls = [1, 2, 4, 8, 9]`, `C = 3`:

**After sorting:** `[1, 2, 4, 8, 9]`

**Initial:** `left = 1`, `right = 8`

**Iteration 1:** `mid = 4`
- Cow 1 at 1
- Check 2: 2-1=1 < 4 ✗
- Check 4: 4-1=3 < 4 ✗
- Check 8: 8-1=7 ≥ 4 ✓ → Cow 2 at 8
- Check 9: 9-8=1 < 4 ✗
- Placed 2 cows < 3 ✗
- `right = 3`

**Iteration 2:** `mid = 2`
- Cow 1 at 1
- Check 2: 2-1=1 < 2 ✗
- Check 4: 4-1=3 ≥ 2 ✓ → Cow 2 at 4
- Check 8: 8-4=4 ≥ 2 ✓ → Cow 3 at 8
- Placed 3 cows ✓
- `answer = 2`, `left = 3`

**Iteration 3:** `mid = 3`
- Cow 1 at 1
- Check 2: 2-1=1 < 3 ✗
- Check 4: 4-1=3 ≥ 3 ✓ → Cow 2 at 4
- Check 8: 8-4=4 ≥ 3 ✓ → Cow 3 at 8
- Placed 3 cows ✓
- `answer = 3`, `left = 4`

**Final:** `left = 4`, `right = 3` → Answer = **3**


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `Input array elements ≥ 1`
- `Answer is monotonic — if X works, X+1 also works (or vice versa)`

<br>

---

## All Possible Edge Cases

1. **Minimum possible answer:** Binary search low boundary
2. **Maximum possible answer:** Binary search high boundary
3. **Single element array:** Answer is trivially that element
4. **All elements same:** Answer may be the element or a function of it
5. **Large range:** Binary search on answer space O(log(range))

<br>

## Complexity Analysis

### Time Complexity: **O(N log N + N log(max - min))**

**Why?**
- Sorting: `O(N log N)`
- Binary search: `O(log(max - min))` iterations
- Each iteration: `O(N)` to check placement
- Total: `O(N log N + N log(max - min))`

### Space Complexity: **O(1)** or **O(log N)**

**Why?**
- `O(1)` if sorting in-place
- `O(log N)` for sorting recursion stack

## Edge Cases

1. **C = 2 (Two cows):**
   ```
   stalls = [1, 2, 8, 4, 9]
   C = 2
   Answer = 8 (place at 1 and 9)
   ```

2. **C = N (All stalls used):**
   ```
   stalls = [1, 2, 3, 4]
   C = 4
   Answer = 1 (minimum gap between consecutive stalls)
   ```

3. **Equally spaced stalls:**
   ```
   stalls = [1, 3, 5, 7, 9]
   C = 3
   Answer = 4 (place at 1, 5, 9)
   ```

4. **Large gaps:**
   ```
   stalls = [1, 1000, 1001]
   C = 2
   Answer = 999 (place at 1 and 1000)
   ```

## Common Mistakes

1. **Not sorting stalls:**
   - ❌ Using stalls in given order
   - ✅ Sort first!

2. **Wrong search direction:**
   - ❌ Using `right = mid` when feasible
   - ✅ Use `left = mid + 1` to maximize

3. **Greedy placement error:**
   - ❌ Trying to optimize placement
   - ✅ Place greedily at first valid position

4. **Off-by-one in cow count:**
   - ❌ Starting cows from 0
   - ✅ Start from 1 (first cow at first stall)

## Related Problems

1. **Magnetic Force Between Two Balls** - Identical problem
2. **Place k Elements Such That Minimum Distance is Maximum** - General form
3. **Minimize Max Distance to Gas Station** - Distance optimization variant

## Key Takeaways

1. **Pattern:** "Maximize the minimum" → Binary search on answer
2. **Sort First:** Always sort positions before binary search
3. **Greedy Placement:** Place cow at first valid position
4. **Search Direction:** Feasible → try larger; Not feasible → try smaller
5. **Classic Problem:** One of the most famous binary search on answer problems

```code```
