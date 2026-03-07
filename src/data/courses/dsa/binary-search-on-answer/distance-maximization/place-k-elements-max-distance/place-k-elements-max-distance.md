## Problem Statement

Given an array `arr[]` of size `N` representing positions on a number line, and an integer `k`, select `k` elements from the array such that the **minimum distance** between any two selected elements is **as large as possible**.

Return the **maximum possible minimum distance**.

**Constraints:**
- `2 ≤ N ≤ 10^5`
- `2 ≤ k ≤ N`
- `1 ≤ arr[i] ≤ 10^9`
- All elements are distinct

## Examples

### Example 1:
**Input:**
```
arr[] = [1, 2, 8, 4, 9]
k = 3
```

**Output:**
```
3
```

**Explanation:**
After sorting: [1, 2, 4, 8, 9]
Select elements: 1, 4, 9
- Distance between 1 and 4: 3
- Distance between 4 and 9: 5
- Minimum distance = 3 ✓

### Example 2:
**Input:**
```
arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 4
```

**Output:**
```
3
```

**Explanation:**
Select: 1, 4, 7, 10
- Distances: 3, 3, 3
- Minimum = 3

### Example 3:
**Input:**
```
arr[] = [5, 10, 15, 20, 25]
k = 3
```

**Output:**
```
10
```

**Explanation:**
Select: 5, 15, 25
- Distances: 10, 10
- Minimum = 10

## Visual Example

For `arr[] = [1, 2, 8, 4, 9]`, `k = 3`:

```
After sorting: [1, 2, 4, 8, 9]
               |  |  |  |  |
               ─────────────

Distance = 1:
Select: 1, 2, 4 ✓
Minimum = 1

Distance = 3:
Select: 1, 4, 9 ✓
Distances: 3, 5
Minimum = 3 ✓ (optimal)

Distance = 4:
Select: 1, ?, ?
Next valid: 5+ (not available)
Next valid: 8 (only 2 elements) ✗
Cannot select 3 elements
```

## Binary Search Visualization

```
Sorted: [1, 2, 4, 8, 9]

Search Space: [1, 8]
              ↓
         mid = 4
         
Can select 3 elements with min distance 4?
Element 1: position 1
Element 2: position 5+ (not available, try 8)
Element 2: position 8 (8-1=7 ≥ 4) ✓
Element 3: position 12+ (not available)
Only 2 elements ✗
Try smaller → right = 3

         mid = 2
         
Can select 3 elements with min distance 2?
Element 1: position 1
Element 2: position 4 (4-1=3 ≥ 2) ✓
Element 3: position 8 (8-4=4 ≥ 2) ✓
Yes! 3 elements ✓
Try larger → left = 3

         mid = 3
         
Can select 3 elements with min distance 3?
Element 1: position 1
Element 2: position 4 (4-1=3 ≥ 3) ✓
Element 3: position 9 (9-4=5 ≥ 3) ✓
Yes! 3 elements ✓
Try larger → left = 4

Answer = 3
```

## Approach: Binary Search on Answer

### Key Insight

This is the **general form** of:
- Aggressive Cows (stalls → positions, cows → k elements)
- Magnetic Force Between Two Balls (baskets → positions, balls → k elements)

**Search Space:** `[1, arr[n-1] - arr[0]]`

### Algorithm

1. **Sort Array:**
   ```cpp
   sort(arr, arr + n)
   ```

2. **Binary Search:**
   ```cpp
   left = 1
   right = arr[n-1] - arr[0]
   
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canSelect(arr, k, mid)) {
           answer = mid
           left = mid + 1  // try larger distance
       } else {
           right = mid - 1  // try smaller distance
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canSelect(arr, k, minDist):
       count = 1
       lastPos = arr[0]
       
       for i = 1 to n-1:
           if (arr[i] - lastPos >= minDist) {
               count++
               lastPos = arr[i]
               if (count == k) return true
           }
       
       return false
   ```

### Step-by-Step Walkthrough

For `arr[] = [1, 2, 8, 4, 9]`, `k = 3`:

**After sorting:** `[1, 2, 4, 8, 9]`

**Initial:** `left = 1`, `right = 8`

**Iteration 1:** `mid = 4`
- Element 1 at 1
- Check 2: 2-1=1 < 4 ✗
- Check 4: 4-1=3 < 4 ✗
- Check 8: 8-1=7 ≥ 4 ✓ → Element 2 at 8
- Check 9: 9-8=1 < 4 ✗
- Selected 2 < 3 ✗
- `right = 3`

**Iteration 2:** `mid = 2`
- Element 1 at 1
- Check 2: 2-1=1 < 2 ✗
- Check 4: 4-1=3 ≥ 2 ✓ → Element 2 at 4
- Check 8: 8-4=4 ≥ 2 ✓ → Element 3 at 8
- Selected 3 ✓
- `answer = 2`, `left = 3`

**Iteration 3:** `mid = 3`
- Element 1 at 1
- Check 2: 2-1=1 < 3 ✗
- Check 4: 4-1=3 ≥ 3 ✓ → Element 2 at 4
- Check 8: 8-4=4 ≥ 3 ✓ → Element 3 at 8
- Wait, let me recalculate...
- Actually, we can also select 9: 9-4=5 ≥ 3 ✓
- Selected 3 ✓
- `answer = 3`, `left = 4`

**Final:** `left = 4`, `right = 3` → Answer = **3**

## Complexity Analysis

### Time Complexity: **O(N log N + N log(max - min))**

**Why?**
- Sorting: `O(N log N)`
- Binary search: `O(log(max - min))`
- Each check: `O(N)`

### Space Complexity: **O(1)** or **O(log N)**

**Why?**
- Sorting space

## Edge Cases

1. **k = 2 (Select two elements):**
   ```
   arr[] = [1, 2, 8, 4, 9]
   k = 2
   Answer = 8 (select 1 and 9)
   ```

2. **k = n (Select all elements):**
   ```
   arr[] = [1, 2, 3, 4]
   k = 4
   Answer = 1 (minimum gap)
   ```

3. **Equally spaced:**
   ```
   arr[] = [0, 10, 20, 30, 40]
   k = 3
   Answer = 20 (select 0, 20, 40)
   ```

4. **Large gap:**
   ```
   arr[] = [1, 2, 1000000000]
   k = 2
   Answer = 999999999
   ```

## Problem Variants

### 1. Aggressive Cows
- **Context:** Placing cows in stalls
- **Same as:** This problem with different naming

### 2. Magnetic Force Between Two Balls
- **Context:** Placing balls in baskets
- **Same as:** This problem with different naming

### 3. Maximize Distance to Closest Person
- **Context:** Seating arrangement
- **Similar pattern:** Maximize minimum distance

## Common Mistakes

1. **Not sorting array:**
   - ❌ Using elements in given order
   - ✅ Sort first!

2. **Wrong search direction:**
   - ❌ Using `right = mid` when feasible
   - ✅ Use `left = mid + 1` to maximize

3. **Greedy selection error:**
   - ❌ Trying to optimize selection
   - ✅ Select greedily at first valid position

4. **Off-by-one in count:**
   - ❌ Starting count from 0
   - ✅ Start from 1 (first element selected)

## Related Problems

1. **Aggressive Cows** - Special case
2. **Magnetic Force Between Two Balls** - Special case
3. **Minimize Max Distance to Gas Station** - Inverse problem
4. **Maximize Distance to Closest Person** - Similar pattern

## Key Takeaways

1. **General Form:** This is the abstract version of Aggressive Cows and Magnetic Force
2. **Pattern:** "Maximize the minimum" → Binary search on answer
3. **Sort First:** Essential for greedy selection
4. **Greedy Selection:** Select at first valid position
5. **Universal Algorithm:** Same approach works for all variants

## Mathematical Insight

**Why does greedy selection work?**

If we can select `k` elements with minimum distance `d`, then:
- Selecting greedily (first valid position) maximizes remaining space
- This gives the best chance for placing remaining elements
- Any other selection strategy would only reduce available space

**Proof by contradiction:**
- Suppose optimal selection skips a valid position
- This reduces the remaining space
- Contradicts the goal of maximizing minimum distance

```code```