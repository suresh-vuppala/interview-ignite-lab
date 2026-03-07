## Problem Statement

You are given an integer array `bloomDay`, an integer `m` (number of bouquets needed), and an integer `k` (adjacent flowers per bouquet).

You want to make `m` bouquets. To make a bouquet, you need to use `k` **adjacent flowers** from the garden. The garden consists of `n` flowers, the `i-th` flower will bloom on `bloomDay[i]` and can be used in **exactly one** bouquet.

Return the **minimum number of days** you need to wait to make `m` bouquets. If it's impossible, return `-1`.

**Constraints:**
- `bloomDay.length == n`
- `1 ≤ n ≤ 10^5`
- `1 ≤ bloomDay[i] ≤ 10^9`
- `1 ≤ m ≤ 10^6`
- `1 ≤ k ≤ n`

## Examples

### Example 1:
**Input:**
```
bloomDay = [1, 10, 3, 10, 2]
m = 3
k = 1
```

**Output:**
```
3
```

**Explanation:**
- Day 1: [✓, ✗, ✗, ✗, ✗] → 1 bouquet
- Day 2: [✓, ✗, ✗, ✗, ✓] → 2 bouquets
- Day 3: [✓, ✗, ✓, ✗, ✓] → 3 bouquets ✓

### Example 2:
**Input:**
```
bloomDay = [1, 10, 3, 10, 2]
m = 3
k = 2
```

**Output:**
```
-1
```

**Explanation:**
Need 3 bouquets × 2 adjacent flowers = 6 flowers
Only 5 flowers available → Impossible

### Example 3:
**Input:**
```
bloomDay = [7, 7, 7, 7, 12, 7, 7]
m = 2
k = 3
```

**Output:**
```
12
```

**Explanation:**
- Day 7: [✓, ✓, ✓, ✓, ✗, ✓, ✓]
  - Bouquet 1: flowers [0,1,2]
  - Bouquet 2: flowers [5,6] (only 2, need 3) ✗
- Day 12: [✓, ✓, ✓, ✓, ✓, ✓, ✓]
  - Bouquet 1: flowers [0,1,2]
  - Bouquet 2: flowers [3,4,5] ✓

## Visual Example

For `bloomDay = [1, 10, 3, 10, 2]`, `m = 2`, `k = 2`:

```
Day 1:  [✓, ✗, ✗, ✗, ✗]
        No adjacent pairs

Day 2:  [✓, ✗, ✗, ✗, ✓]
        No adjacent pairs

Day 3:  [✓, ✗, ✓, ✗, ✓]
        No adjacent pairs

Day 10: [✓, ✓, ✓, ✓, ✓]
        Adjacent pairs: [0,1], [1,2], [2,3], [3,4]
        Can make 2 bouquets ✓
        
Answer = 10
```

## Binary Search Visualization

```
Search Space: [1, 10]
              ↓
         mid = 5
         
Can make 2 bouquets by day 5?
Bloomed: [✓, ✗, ✓, ✗, ✓]
Adjacent groups: none of size 2
Bouquets = 0 < 2 ✗
No! Need more days → left = 6

         mid = 8
         
Can make 2 bouquets by day 8?
Bloomed: [✓, ✗, ✓, ✗, ✓]
Bouquets = 0 < 2 ✗
No! → left = 9

         mid = 9
Same as day 8 ✗
left = 10

         mid = 10
         
Can make 2 bouquets by day 10?
Bloomed: [✓, ✓, ✓, ✓, ✓]
Adjacent groups: [0-4] (size 5)
Can make 2 bouquets (5/2 = 2) ✓
Yes! → right = 9

Answer = 10
```

## Approach: Binary Search on Answer

### Key Insight

Binary search on the **number of days**. For each day, check if we can make `m` bouquets.

**Search Space:** `[min(bloomDay), max(bloomDay)]`

### Algorithm

1. **Check Possibility:**
   ```cpp
   if (m * k > n) return -1;  // impossible
   ```

2. **Binary Search:**
   ```cpp
   left = min(bloomDay)
   right = max(bloomDay)
   
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canMakeBouquets(bloomDay, m, k, mid)) {
           answer = mid
           right = mid - 1  // try fewer days
       } else {
           left = mid + 1   // need more days
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canMakeBouquets(bloomDay, m, k, day):
       bouquets = 0
       flowers = 0
       
       for each bloom in bloomDay:
           if (bloom <= day) {
               flowers++
               if (flowers == k) {
                   bouquets++
                   flowers = 0
               }
           } else {
               flowers = 0  // reset, not adjacent
           }
       
       return bouquets >= m
   ```

### Step-by-Step Walkthrough

For `bloomDay = [7, 7, 7, 7, 12, 7, 7]`, `m = 2`, `k = 3`:

**Check:** `2 × 3 = 6 ≤ 7` ✓ (possible)

**Initial:** `left = 7`, `right = 12`

**Iteration 1:** `mid = 9`
- Bloomed by day 9: [✓, ✓, ✓, ✓, ✗, ✓, ✓]
- Count adjacent groups of size 3:
  - Group 1: flowers [0,1,2] → 1 bouquet
  - Flower 4 not bloomed → reset
  - Group 2: flowers [5,6] → only 2 flowers
- Bouquets = 1 < 2 ✗
- `left = 10`

**Iteration 2:** `mid = 11`
- Same as day 9 ✗
- `left = 12`

**Iteration 3:** `mid = 12`
- Bloomed by day 12: [✓, ✓, ✓, ✓, ✓, ✓, ✓]
- Group 1: [0,1,2] → 1 bouquet
- Group 2: [3,4,5] → 1 bouquet
- Bouquets = 2 ≥ 2 ✓
- `answer = 12`, `right = 11`

**Final:** Answer = **12**

## Complexity Analysis

### Time Complexity: **O(N × log(max - min))**

**Why?**
- Binary search: `O(log(max - min))` iterations
- Each iteration: `O(N)` to count bouquets
- Total: `O(N × log(max - min))`

### Space Complexity: **O(1)**

## Edge Cases

1. **Impossible case:**
   ```
   bloomDay = [1, 2, 3]
   m = 2, k = 2
   Need 4 flowers, only 3 available → -1
   ```

2. **k = 1 (Single flower bouquets):**
   ```
   bloomDay = [1, 10, 3, 10, 2]
   m = 3, k = 1
   Answer = 3 (any 3 flowers)
   ```

3. **All bloom same day:**
   ```
   bloomDay = [5, 5, 5, 5]
   m = 2, k = 2
   Answer = 5
   ```

4. **Need all flowers:**
   ```
   bloomDay = [1, 2, 3, 4]
   m = 2, k = 2
   Answer = 4 (need all to bloom)
   ```

## Common Mistakes

1. **Not resetting flower count:**
   - ❌ Counting non-adjacent flowers
   - ✅ Reset count when flower not bloomed

2. **Wrong impossibility check:**
   - ❌ Not checking `m * k > n`
   - ✅ Check before binary search

3. **Off-by-one in bouquet count:**
   - ❌ Counting incomplete groups
   - ✅ Only count when `flowers == k`

## Related Problems

1. **Koko Eating Bananas** - Rate optimization
2. **Capacity To Ship Packages** - Capacity optimization
3. **Minimum Speed to Arrive on Time** - Speed optimization

## Key Takeaways

1. **Pattern:** "Minimize days/time" → Binary search on answer
2. **Adjacency Constraint:** Must use consecutive bloomed flowers
3. **Reset Logic:** Reset count when encountering unbloomed flower
4. **Impossibility Check:** `m * k > n` → return -1
5. **Search Space:** `[min(bloomDay), max(bloomDay)]`

```code```