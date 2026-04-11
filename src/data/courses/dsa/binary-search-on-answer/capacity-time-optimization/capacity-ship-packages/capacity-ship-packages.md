## Problem Statement

A conveyor belt has packages that must be shipped from one port to another within `days` days.

The `i-th` package on the conveyor belt has a weight of `weights[i]`. Each day, we load the ship with packages in the **order given by weights**. We may not load more weight than the maximum weight capacity of the ship.

Return the **minimum weight capacity** of the ship that will result in all packages being shipped within `days` days.

**Constraints:**
- `1 ≤ days ≤ weights.length ≤ 5 × 10^4`
- `1 ≤ weights[i] ≤ 500`

## Examples

### Example 1:
**Input:**
```
weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
days = 5
```

**Output:**
```
15
```

**Explanation:**
With capacity 15:
- Day 1: [1, 2, 3, 4, 5] = 15
- Day 2: [6, 7] = 13
- Day 3: [8] = 8
- Day 4: [9] = 9
- Day 5: [10] = 10
All packages shipped in 5 days.

### Example 2:
**Input:**
```
weights = [3, 2, 2, 4, 1, 4]
days = 3
```

**Output:**
```
6
```

**Explanation:**
With capacity 6:
- Day 1: [3, 2] = 5
- Day 2: [2, 4] = 6
- Day 3: [1, 4] = 5

### Example 3:
**Input:**
```
weights = [1, 2, 3, 1, 1]
days = 4
```

**Output:**
```
3
```

**Explanation:**
With capacity 3:
- Day 1: [1, 2] = 3
- Day 2: [3] = 3
- Day 3: [1, 1] = 2
- Day 4: [] (not needed)

## Visual Example

For `weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`, `days = 5`:

```
Capacity = 10 (too small):
Day 1: [1,2,3,4] = 10
Day 2: [5] = 5
Day 3: [6] = 6
Day 4: [7] = 7
Day 5: [8] = 8
Day 6: [9] = 9
Day 7: [10] = 10
Needs 7 days ✗

Capacity = 15 (optimal):
Day 1: [1,2,3,4,5] = 15
Day 2: [6,7] = 13
Day 3: [8] = 8
Day 4: [9] = 9
Day 5: [10] = 10
Needs 5 days ✓

Capacity = 20 (works but not minimal):
Day 1: [1,2,3,4,5] = 15
Day 2: [6,7] = 13
Day 3: [8,9] = 17
Day 4: [10] = 10
Needs 4 days ✓ (better than needed)
```

## Binary Search Visualization

```
Search Space: [10, 55]
              ↓
         mid = 32
         
Can ship with capacity 32?
Day 1: [1,2,3,4,5,6,7,8] = 31 ✓
Day 2: [9,10] = 19 ✓
Days needed = 2 ≤ 5 ✓
Yes! Try smaller → right = 31

         mid = 20
         
Can ship with capacity 20?
Day 1: [1,2,3,4,5] = 15 ✓
Day 2: [6,7] = 13 ✓
Day 3: [8,9] = 17 ✓
Day 4: [10] = 10 ✓
Days needed = 4 ≤ 5 ✓
Yes! Try smaller → right = 19

         mid = 14
         
Can ship with capacity 14?
Day 1: [1,2,3,4] = 10 ✓
Day 2: [5,6] = 11 ✓
Day 3: [7] = 7 ✓
Day 4: [8] = 8 ✓
Day 5: [9] = 9 ✓
Day 6: [10] = 10 ✓
Days needed = 6 > 5 ✗
No! Increase → left = 15

Answer = 15
```

## Approach: Binary Search on Answer

### Key Insight

We need to find the **minimum capacity** that allows shipping within `days` days.

**Search Space:** `[max(weights), sum(weights)]`
- Lower bound: Must carry the heaviest package
- Upper bound: Carry all packages in one day

### Algorithm

1. **Define Search Space:**
   ```cpp
   left = max(weights)   // minimum capacity needed
   right = sum(weights)  // maximum capacity (all in 1 day)
   ```

2. **Binary Search:**
   ```cpp
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canShip(weights, days, mid)) {
           answer = mid
           right = mid - 1  // try smaller capacity
       } else {
           left = mid + 1   // need larger capacity
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canShip(weights, days, capacity):
       daysNeeded = 1
       currentLoad = 0
       
       for each weight in weights:
           if (currentLoad + weight > capacity) {
               daysNeeded++
               currentLoad = weight
           } else {
               currentLoad += weight
           }
       
       return daysNeeded <= days
   ```

### Step-by-Step Walkthrough

For `weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`, `days = 5`:

**Initial:** `left = 10`, `right = 55`

**Iteration 1:** `mid = 32`
- Day 1: 1+2+3+4+5+6+7+8 = 31 ✓
- Day 2: 9+10 = 19 ✓
- Days needed = 2 ≤ 5 ✓
- Possible! `answer = 32`, `right = 31`

**Iteration 2:** `mid = 20`
- Day 1: 1+2+3+4+5 = 15 ✓
- Day 2: 6+7 = 13 ✓
- Day 3: 8+9 = 17 ✓
- Day 4: 10 ✓
- Days needed = 4 ≤ 5 ✓
- Possible! `answer = 20`, `right = 19`

**Iteration 3:** `mid = 14`
- Day 1: 1+2+3+4 = 10 ✓
- Day 2: 5+6 = 11 ✓
- Day 3: 7 ✓
- Day 4: 8 ✓
- Day 5: 9 ✓
- Day 6: 10 ✓
- Days needed = 6 > 5 ✗
- Not possible! `left = 15`

**Iteration 4:** `mid = 17`
- Days needed = 4 ≤ 5 ✓
- Possible! `answer = 17`, `right = 16`

**Iteration 5:** `mid = 15`
- Day 1: 1+2+3+4+5 = 15 ✓
- Day 2: 6+7 = 13 ✓
- Day 3: 8 ✓
- Day 4: 9 ✓
- Day 5: 10 ✓
- Days needed = 5 ≤ 5 ✓
- Possible! `answer = 15`, `right = 14`

**Final:** `left = 15`, `right = 14` → Answer = **15**


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

### Time Complexity: **O(N × log(sum - max))**

**Why?**
- Binary search: `O(log(sum - max))` iterations
- Each iteration: `O(N)` to check feasibility
- Total: `O(N × log(sum - max))`

**Example:**
- `N = 5 × 10^4`, `sum ≈ 2.5 × 10^7`
- `log(2.5 × 10^7) ≈ 25` iterations
- Total: `5 × 10^4 × 25 ≈ 1.25 × 10^6` operations

### Space Complexity: **O(1)**

**Why?**
- Only constant extra space
- No additional data structures

## Edge Cases

1. **days = 1 (Ship all in one day):**
   ```
   weights = [1, 2, 3, 4]
   days = 1
   Answer = 10 (sum of all weights)
   ```

2. **days = n (One package per day):**
   ```
   weights = [1, 2, 3, 4]
   days = 4
   Answer = 4 (maximum weight)
   ```

3. **All weights equal:**
   ```
   weights = [5, 5, 5, 5]
   days = 2
   Answer = 10 (2 packages per day)
   ```

4. **One very heavy package:**
   ```
   weights = [1, 1, 1, 100]
   days = 2
   Answer = 100 (must carry the heavy one)
   ```

## Common Mistakes

1. **Wrong search space:**
   - ❌ Starting from 0 or 1
   - ✅ Start from `max(weights)`

2. **Allowing non-sequential loading:**
   - ❌ Skipping packages to optimize
   - ✅ Must load in given order

3. **Off-by-one in days count:**
   - ❌ Starting daysNeeded from 0
   - ✅ Start from 1 (first day)

4. **Integer overflow:**
   - ❌ Using `int` for sum
   - ✅ Use `long long` for large sums

## Related Problems

1. **Allocate Minimum Number of Pages** - Same pattern
2. **Painter's Partition Problem** - Same pattern
3. **Split Array Largest Sum** - Same pattern
4. **Koko Eating Bananas** - Rate optimization variant

## Key Takeaways

1. **Pattern:** "Minimize capacity/maximum" → Binary search on answer
2. **Search Space:** `[max(weights), sum(weights)]`
3. **Sequential Constraint:** Must load packages in order
4. **Greedy Check:** Load as much as possible each day
5. **Direction:** Feasible → try smaller; Not feasible → try larger

```code```
