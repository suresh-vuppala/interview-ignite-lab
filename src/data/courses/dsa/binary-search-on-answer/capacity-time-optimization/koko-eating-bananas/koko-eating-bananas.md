## Problem Statement

Koko loves to eat bananas. There are `n` piles of bananas, the `i-th` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them and will not eat any more bananas during that hour.

Return the **minimum integer** `k` such that she can eat all the bananas within `h` hours.

**Constraints:**
- `1 ≤ piles.length ≤ 10^4`
- `piles.length ≤ h ≤ 10^9`
- `1 ≤ piles[i] ≤ 10^9`

## Examples

### Example 1:
**Input:**
```
piles = [3, 6, 7, 11]
h = 8
```

**Output:**
```
4
```

**Explanation:**
With speed k = 4:
- Pile 1 (3 bananas): 1 hour
- Pile 2 (6 bananas): 2 hours
- Pile 3 (7 bananas): 2 hours
- Pile 4 (11 bananas): 3 hours
Total: 8 hours ✓

### Example 2:
**Input:**
```
piles = [30, 11, 23, 4, 20]
h = 5
```

**Output:**
```
30
```

**Explanation:**
With speed k = 30, Koko eats each pile in 1 hour.
Total: 5 hours ✓

### Example 3:
**Input:**
```
piles = [30, 11, 23, 4, 20]
h = 6
```

**Output:**
```
23
```

**Explanation:**
With speed k = 23:
- Pile 1 (30): 2 hours
- Pile 2 (11): 1 hour
- Pile 3 (23): 1 hour
- Pile 4 (4): 1 hour
- Pile 5 (20): 1 hour
Total: 6 hours ✓

## Visual Example

For `piles = [3, 6, 7, 11]`, `h = 8`:

```
Speed k = 1:
Pile 3: 3 hours
Pile 6: 6 hours
Pile 7: 7 hours
Pile 11: 11 hours
Total: 27 hours ✗ (too slow)

Speed k = 4:
Pile 3: ⌈3/4⌉ = 1 hour
Pile 6: ⌈6/4⌉ = 2 hours
Pile 7: ⌈7/4⌉ = 2 hours
Pile 11: ⌈11/4⌉ = 3 hours
Total: 8 hours ✓ (optimal)

Speed k = 11:
Each pile: 1 hour
Total: 4 hours ✓ (faster but not minimal)
```

## Binary Search Visualization

```
Search Space: [1, 11]
              ↓
         mid = 6
         
Can eat all with speed 6?
Pile 3: ⌈3/6⌉ = 1 hour
Pile 6: ⌈6/6⌉ = 1 hour
Pile 7: ⌈7/6⌉ = 2 hours
Pile 11: ⌈11/6⌉ = 2 hours
Total: 6 hours ≤ 8 ✓
Yes! Try slower → right = 5

         mid = 3
         
Can eat all with speed 3?
Pile 3: ⌈3/3⌉ = 1 hour
Pile 6: ⌈6/3⌉ = 2 hours
Pile 7: ⌈7/3⌉ = 3 hours
Pile 11: ⌈11/3⌉ = 4 hours
Total: 10 hours > 8 ✗
No! Try faster → left = 4

         mid = 4
         
Can eat all with speed 4?
Total: 8 hours ≤ 8 ✓
Yes! Try slower → right = 3

Answer = 4
```

## Approach: Binary Search on Answer

### Key Insight

We need to find the **minimum eating speed** that allows finishing within `h` hours.

**Search Space:** `[1, max(piles)]`
- Lower bound: 1 banana per hour (minimum possible)
- Upper bound: max(piles) (eat largest pile in 1 hour)

### Algorithm

1. **Define Search Space:**
   ```cpp
   left = 1
   right = max(piles)
   ```

2. **Binary Search:**
   ```cpp
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canEatAll(piles, h, mid)) {
           answer = mid
           right = mid - 1  // try slower speed
       } else {
           left = mid + 1   // need faster speed
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canEatAll(piles, h, speed):
       hours = 0
       
       for each pile in piles:
           hours += (pile + speed - 1) / speed  // ceiling division
       
       return hours <= h
   ```

### Ceiling Division Formula

To calculate hours needed for a pile:
- **Hours = ⌈pile / speed⌉**
- **Implementation:** `(pile + speed - 1) / speed`

**Why?**
- Pile = 7, speed = 4: ⌈7/4⌉ = 2
- Formula: (7 + 4 - 1) / 4 = 10 / 4 = 2 ✓

### Step-by-Step Walkthrough

For `piles = [3, 6, 7, 11]`, `h = 8`:

**Initial:** `left = 1`, `right = 11`

**Iteration 1:** `mid = 6`
- Hours: ⌈3/6⌉ + ⌈6/6⌉ + ⌈7/6⌉ + ⌈11/6⌉ = 1+1+2+2 = 6
- 6 ≤ 8 ✓
- Possible! `answer = 6`, `right = 5`

**Iteration 2:** `mid = 3`
- Hours: ⌈3/3⌉ + ⌈6/3⌉ + ⌈7/3⌉ + ⌈11/3⌉ = 1+2+3+4 = 10
- 10 > 8 ✗
- Not possible! `left = 4`

**Iteration 3:** `mid = 4`
- Hours: ⌈3/4⌉ + ⌈6/4⌉ + ⌈7/4⌉ + ⌈11/4⌉ = 1+2+2+3 = 8
- 8 ≤ 8 ✓
- Possible! `answer = 4`, `right = 3`

**Final:** `left = 4`, `right = 3` → Answer = **4**


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

### Time Complexity: **O(N × log(max(piles)))**

**Why?**
- Binary search: `O(log(max(piles)))` iterations
- Each iteration: `O(N)` to calculate total hours
- Total: `O(N × log(max(piles)))`

**Example:**
- `N = 10^4`, `max(piles) = 10^9`
- `log(10^9) ≈ 30` iterations
- Total: `10^4 × 30 = 3 × 10^5` operations

### Space Complexity: **O(1)**

**Why?**
- Only constant extra space
- No additional data structures

## Edge Cases

1. **h = n (One hour per pile):**
   ```
   piles = [3, 6, 7, 11]
   h = 4
   Answer = 11 (must eat fastest pile in 1 hour)
   ```

2. **All piles equal:**
   ```
   piles = [5, 5, 5, 5]
   h = 8
   Answer = 3 (⌈5/3⌉ = 2 hours per pile, total 8)
   ```

3. **Plenty of time:**
   ```
   piles = [10, 20, 30]
   h = 100
   Answer = 1 (can eat slowly)
   ```

4. **Single pile:**
   ```
   piles = [1000000000]
   h = 2
   Answer = 500000000
   ```

## Common Mistakes

1. **Wrong ceiling division:**
   - ❌ Using `pile / speed` (floor division)
   - ✅ Using `(pile + speed - 1) / speed` (ceiling)

2. **Wrong search space:**
   - ❌ Starting from 0
   - ✅ Starting from 1

3. **Integer overflow:**
   - ❌ Using `int` for hours calculation
   - ✅ Use `long long` for large piles

4. **Not handling h < n:**
   - The problem guarantees `piles.length ≤ h`

## Related Problems

1. **Capacity To Ship Packages** - Similar capacity optimization
2. **Minimum Speed to Arrive on Time** - Speed optimization variant
3. **Minimum Time to Complete Trips** - Time optimization
4. **Split Array Largest Sum** - Minimize maximum pattern

## Key Takeaways

1. **Pattern:** "Minimize speed/rate" → Binary search on answer
2. **Search Space:** `[1, max(piles)]`
3. **Ceiling Division:** Use `(pile + speed - 1) / speed`
4. **One Pile Per Hour:** Koko can only eat from one pile per hour
5. **Direction:** Feasible → try slower; Not feasible → try faster

```code```
