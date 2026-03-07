## Problem Statement

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has `n` empty baskets, the `i-th` basket is at `position[i]`.

Morty has `m` balls and needs to distribute the balls into the baskets such that the **minimum magnetic force** between any two balls is **maximum**.

Rick stated that magnetic force between two balls at positions `x` and `y` is `|x - y|`.

Return the **maximum minimum magnetic force** between any two balls.

**Constraints:**
- `2 ≤ position.length ≤ 10^5`
- `1 ≤ position[i] ≤ 10^9`
- All integers in `position` are **distinct**
- `2 ≤ m ≤ position.length`

## Examples

### Example 1:
**Input:**
```
position = [1, 2, 3, 4, 7]
m = 3
```

**Output:**
```
3
```

**Explanation:**
Distribute 3 balls at positions 1, 4, and 7:
- Force between ball 1 and ball 2: |4 - 1| = 3
- Force between ball 2 and ball 3: |7 - 4| = 3
- Minimum force = 3 ✓

### Example 2:
**Input:**
```
position = [5, 4, 3, 2, 1, 1000000000]
m = 2
```

**Output:**
```
999999999
```

**Explanation:**
Place balls at positions 1 and 1000000000:
- Force = 999999999 (maximum possible)

### Example 3:
**Input:**
```
position = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
m = 4
```

**Output:**
```
3
```

**Explanation:**
Place balls at 1, 4, 7, 10:
- Forces: 3, 3, 3
- Minimum = 3

## Visual Example

For `position = [1, 2, 3, 4, 7]`, `m = 3`:

```
Baskets: 1  2  3  4     7
         |  |  |  |     |
         ─────────────────

Force = 1:
Place at: 1, 2, 3 ✓
Minimum force = 1

Force = 2:
Place at: 1, 3, 7 ✓
Forces: 2, 4
Minimum = 2 ✓

Force = 3:
Place at: 1, 4, 7 ✓
Forces: 3, 3
Minimum = 3 ✓ (optimal)

Force = 4:
Place at: 1, ?, ?
Next valid: 5+ (not available)
Next valid: 7 (only 2 balls) ✗
Cannot place 3 balls
```

## Approach: Binary Search on Answer

### Key Insight

This is **identical to the Aggressive Cows problem**:
- Baskets → Stalls
- Balls → Cows
- Magnetic force → Distance

**Search Space:** `[1, position[n-1] - position[0]]`

### Algorithm

1. **Sort Positions:**
   ```cpp
   sort(position.begin(), position.end())
   ```

2. **Binary Search:**
   ```cpp
   left = 1
   right = position[n-1] - position[0]
   
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canPlaceBalls(position, m, mid)) {
           answer = mid
           left = mid + 1  // try larger force
       } else {
           right = mid - 1  // try smaller force
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canPlaceBalls(position, m, minForce):
       balls = 1
       lastPos = position[0]
       
       for i = 1 to n-1:
           if (position[i] - lastPos >= minForce) {
               balls++
               lastPos = position[i]
               if (balls == m) return true
           }
       
       return false
   ```

### Step-by-Step Walkthrough

For `position = [1, 2, 3, 4, 7]`, `m = 3`:

**After sorting:** `[1, 2, 3, 4, 7]`

**Initial:** `left = 1`, `right = 6`

**Iteration 1:** `mid = 3`
- Ball 1 at 1
- Check 2: 2-1=1 < 3 ✗
- Check 3: 3-1=2 < 3 ✗
- Check 4: 4-1=3 ≥ 3 ✓ → Ball 2 at 4
- Check 7: 7-4=3 ≥ 3 ✓ → Ball 3 at 7
- Placed 3 balls ✓
- `answer = 3`, `left = 4`

**Iteration 2:** `mid = 5`
- Ball 1 at 1
- Check 2-7: all < 5 from position 1
- Check 7: 7-1=6 ≥ 5 ✓ → Ball 2 at 7
- Only 2 balls ✗
- `right = 4`

**Iteration 3:** `mid = 4`
- Ball 1 at 1
- Check 2-4: all < 4
- Check 7: 7-1=6 ≥ 4 ✓ → Ball 2 at 7
- Only 2 balls ✗
- `right = 3`

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

1. **m = 2 (Two balls):**
   ```
   position = [1, 2, 8, 4, 9]
   m = 2
   Answer = 8 (place at 1 and 9)
   ```

2. **m = n (All baskets used):**
   ```
   position = [1, 2, 3, 4]
   m = 4
   Answer = 1
   ```

3. **Large gap:**
   ```
   position = [1, 1000000000]
   m = 2
   Answer = 999999999
   ```

4. **Consecutive positions:**
   ```
   position = [1, 2, 3, 4, 5]
   m = 3
   Answer = 2 (place at 1, 3, 5)
   ```

## Comparison with Aggressive Cows

| Aspect | Aggressive Cows | Magnetic Force |
|--------|----------------|----------------|
| Items | Stalls | Baskets |
| Objects | Cows | Balls |
| Measure | Distance | Magnetic Force |
| Goal | Maximize min distance | Maximize min force |
| Algorithm | **Identical** | **Identical** |

## Common Mistakes

1. **Not sorting positions:**
   - ❌ Using positions in given order
   - ✅ Sort first!

2. **Wrong search direction:**
   - ❌ Decreasing when feasible
   - ✅ Increase to maximize

3. **Greedy placement:**
   - ❌ Trying to optimize placement
   - ✅ Place at first valid position

## Related Problems

1. **Aggressive Cows** - Identical problem
2. **Place k Elements Such That Minimum Distance is Maximum** - General form
3. **Maximize Distance to Closest Person** - Similar pattern

## Key Takeaways

1. **Identical to Aggressive Cows:** Same algorithm, different story
2. **Pattern:** "Maximize the minimum" → Binary search on answer
3. **Sort First:** Essential for greedy placement
4. **Greedy Works:** Place at first valid position
5. **Classic Pattern:** One of the most common binary search on answer problems

```code```