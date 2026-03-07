## Problem Statement

You have to paint `N` boards of lengths `arr[0], arr[1], ..., arr[N-1]`. There are `M` painters available, and each painter takes **1 unit of time** to paint **1 unit of board**.

The task is to find the **minimum time** required to paint all boards under the following constraints:

1. Each painter can only paint **contiguous sections** of boards
2. Each painter paints at the same speed (1 unit time per 1 unit length)
3. A board cannot be painted by multiple painters
4. The objective is to **minimize the maximum time** taken by any painter

Return the minimum possible maximum time.

**Constraints:**
- `1 ≤ N ≤ 10^5`
- `1 ≤ M ≤ N`
- `1 ≤ arr[i] ≤ 10^9`

## Examples

### Example 1:
**Input:**
```
arr[] = [10, 20, 30, 40]
M = 2
```

**Output:**
```
60
```

**Explanation:**
- Painter 1: [10, 20, 30] → time = 60
- Painter 2: [40] → time = 40
- Maximum time = 60

### Example 2:
**Input:**
```
arr[] = [5, 10, 30, 20, 15]
M = 3
```

**Output:**
```
35
```

**Explanation:**
- Painter 1: [5, 10] → time = 15
- Painter 2: [30] → time = 30
- Painter 3: [20, 15] → time = 35
- Maximum time = 35

### Example 3:
**Input:**
```
arr[] = [100, 200, 300, 400]
M = 2
```

**Output:**
```
600
```

**Explanation:**
- Painter 1: [100, 200, 300] → time = 600
- Painter 2: [400] → time = 400
- Maximum time = 600

## Visual Example

For `arr[] = [10, 20, 30, 40]`, `M = 2`:

```
Boards:  [10] [20] [30] [40]
         ─────────────────────

Allocation Options:

Option 1: [10|20|30|40] | []
          Time: 100      Time: 0
          Max = 100 ✗

Option 2: [10|20|30] | [40]
          Time: 60    Time: 40
          Max = 60 ✓ (Optimal)

Option 3: [10|20] | [30|40]
          Time: 30  Time: 70
          Max = 70 ✗

Option 4: [10] | [20|30|40]
          Time: 10  Time: 90
          Max = 90 ✗
```

## Binary Search Visualization

```
Search Space: [40, 100]
              ↓
         mid = 70
         
Can paint with max time 70?
Painter 1: [10, 20, 30] = 60 ✓
Painter 2: [40] = 40 ✓
Yes! Try smaller → right = 69

         mid = 54
         
Can paint with max time 54?
Painter 1: [10, 20] = 30 ✓
Painter 2: [30] = 30 ✓
Painter 3: [40] = 40 (need 3rd painter) ✗
No! Try larger → left = 55

         mid = 62
         
Can paint with max time 62?
Painter 1: [10, 20, 30] = 60 ✓
Painter 2: [40] = 40 ✓
Yes! Try smaller → right = 61

         mid = 58
Not possible → left = 59

         mid = 60
Possible! → right = 59

Answer = 60
```

## Approach: Binary Search on Answer

### Key Insight

This is **identical to the Book Allocation Problem** with different terminology:
- Books → Boards
- Students → Painters
- Pages → Board lengths (time units)

The answer lies in range `[max(arr), sum(arr)]`:
- **Lower bound**: At least one painter must paint the longest board
- **Upper bound**: One painter paints all boards

### Algorithm

1. **Define Search Space:**
   ```cpp
   left = max(arr)   // minimum possible time
   right = sum(arr)  // maximum possible time
   ```

2. **Binary Search:**
   ```cpp
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canPaint(arr, M, mid)) {
           answer = mid
           right = mid - 1  // try to minimize
       } else {
           left = mid + 1   // increase time limit
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canPaint(arr, M, maxTime):
       painters = 1
       currentTime = 0
       
       for each board in arr:
           if (currentTime + board > maxTime) {
               painters++
               currentTime = board
           } else {
               currentTime += board
           }
       
       return painters <= M
   ```

### Step-by-Step Walkthrough

For `arr[] = [10, 20, 30, 40]`, `M = 2`:

**Initial Setup:**
- `left = 40` (longest board)
- `right = 100` (sum of all boards)

**Iteration 1:** `mid = 70`
- Painter 1: 10 + 20 + 30 = 60 ✓
- Painter 2: 40 ✓
- Painters needed = 2 ≤ 2 ✓
- Possible! `answer = 70`, `right = 69`

**Iteration 2:** `mid = 54`
- Painter 1: 10 + 20 = 30 ✓
- Painter 2: 30 ✓
- Painter 3: 40 (need 3rd painter)
- Painters needed = 3 > 2 ✗
- Not possible! `left = 55`

**Iteration 3:** `mid = 62`
- Painter 1: 10 + 20 + 30 = 60 ✓
- Painter 2: 40 ✓
- Painters needed = 2 ≤ 2 ✓
- Possible! `answer = 62`, `right = 61`

**Iteration 4:** `mid = 58`
- Not possible (needs 3 painters)
- `left = 59`

**Iteration 5:** `mid = 60`
- Painter 1: 10 + 20 + 30 = 60 ✓
- Painter 2: 40 ✓
- Possible! `answer = 60`, `right = 59`

**Final:** `left = 60`, `right = 59` → Answer = **60**

## Complexity Analysis

### Time Complexity: **O(N × log(sum - max))**

**Why?**
- Binary search: `O(log(sum - max))` iterations
- Each iteration: `O(N)` for feasibility check
- Total: `O(N × log(sum - max))`

**Example Calculation:**
- `N = 10^5`, `sum = 10^14`
- `log(10^14) ≈ 47` iterations
- Total: `10^5 × 47 ≈ 5 × 10^6` operations

### Space Complexity: **O(1)**

**Why?**
- Only constant extra space for variables
- No additional data structures

## Edge Cases

1. **M = N (Each painter paints one board):**
   ```
   arr[] = [10, 20, 30]
   M = 3
   Answer = 30 (longest board)
   ```

2. **M = 1 (One painter paints all):**
   ```
   arr[] = [10, 20, 30]
   M = 1
   Answer = 60 (sum of all boards)
   ```

3. **All boards same length:**
   ```
   arr[] = [25, 25, 25, 25]
   M = 2
   Answer = 50 (each painter gets 2 boards)
   ```

4. **One very long board:**
   ```
   arr[] = [5, 5, 5, 100]
   M = 2
   Answer = 100 (one painter must paint the long board)
   ```

## Common Mistakes

1. **Confusing time with number of boards:**
   - ❌ Thinking answer is number of boards per painter
   - ✅ Answer is maximum time (sum of board lengths)

2. **Wrong search space:**
   - ❌ Starting from 0 or 1
   - ✅ Start from `max(arr)`

3. **Non-contiguous allocation:**
   - ❌ Allowing painters to paint non-consecutive boards
   - ✅ Each painter must paint contiguous boards

4. **Integer overflow:**
   - ❌ Using `int` for sum calculation
   - ✅ Use `long long` for large board lengths

## Comparison with Book Allocation

| Aspect | Book Allocation | Painter's Partition |
|--------|----------------|---------------------|
| Items | Books | Boards |
| Agents | Students | Painters |
| Measure | Pages | Time (board length) |
| Goal | Minimize max pages | Minimize max time |
| Algorithm | **Identical** | **Identical** |

## Related Problems

1. **Allocate Minimum Number of Pages** - Identical problem
2. **Split Array Largest Sum** - Same pattern
3. **Capacity To Ship Packages** - Similar optimization
4. **Minimize Max Distance to Gas Station** - Distance variant

## Key Takeaways

1. **Pattern:** "Minimize the maximum" → Binary search on answer
2. **Search Space:** `[max(arr), sum(arr)]`
3. **Greedy Check:** Allocate contiguously until limit exceeded
4. **Direction:** Feasible → try smaller; Not feasible → try larger
5. **Identical to Book Allocation:** Same algorithm, different context

```code```