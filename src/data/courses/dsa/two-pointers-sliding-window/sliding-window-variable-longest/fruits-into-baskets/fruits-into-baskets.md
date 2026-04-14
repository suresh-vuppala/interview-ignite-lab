Given an array where each element represents a type of fruit tree, find the maximum number of fruits you can collect with exactly 2 baskets. You pick continuously from any starting tree, but each basket can only hold one type.

<br>

> Input:
> fruits = [1, 2, 1, 2, 3]

> Output:
> 4

> Explanation:
> Pick from trees [1, 2, 1, 2] — types {1, 2} using 2 baskets. Length = 4.
> 
> **Key insight:** This is "Longest Substring with at Most K Distinct Characters" where K = 2. Sliding window with a frequency map, shrink when distinct types > 2.

<br>



---

## Constraints

- `1 ≤ fruits.length ≤ 10⁵`
- `0 ≤ fruits[i] < fruits.length`

<br>

---

## All Possible Edge Cases

1. **≤ 2 types total:** Return n (entire array)
2. **All same type:** Return n
3. **Alternating 3 types:** [1,2,3,1,2,3] → max = 2

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Checking all subarrays.

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
> Checking all subarrays. We can use a sliding window since adding elements can only increase distinct count, and removing from left decreases it.

> **Key Insight for Improvement:**
> Sliding window with frequency map. When distinct types > 2, shrink from left (remove from map when count → 0). Map size = distinct types.

<br>

---

## Solution 2: Sliding Window + Frequency Map (Optimal)

**Algorithm:**
1. left = 0, freq = {}, maxLen = 0
2. For right = 0 to n-1:
   - freq[fruits[right]]++
   - While len(freq) > 2: freq[fruits[left]]--, if 0 → delete; left++
   - maxLen = max(maxLen, right - left + 1)

### Time Complexity: O(N)
**Why?**
- Each element added/removed from map at most once
- Total: 2N = O(N)

**Detailed breakdown:**
- N = 100,000 → at most 200,000 operations

**Example walkthrough:**
```
fruits = [1, 2, 1, 2, 3]

right=0: freq={1:1}, types=1 ≤ 2 → len=1
right=1: freq={1:1,2:1}, types=2 ≤ 2 → len=2
right=2: freq={1:2,2:1}, types=2 ≤ 2 → len=3
right=3: freq={1:2,2:2}, types=2 ≤ 2 → len=4 ★
right=4: freq={1:2,2:2,3:1}, types=3 > 2 → shrink:
  remove fruits[0]=1: freq={1:1,2:2,3:1}, types=3 > 2
  remove fruits[1]=2: freq={1:1,2:1,3:1}, types=3 > 2
  remove fruits[2]=1: freq={1:0→del,2:1,3:1}, types=2 ≤ 2

maxLen = 4 ✓
```

### Space Complexity: O(1) — at most 3 entries in map

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(N) | Check all subarrays |
| Sliding Window | O(N) | O(1) | Freq map, shrink when types > 2 |

**Recommended Solution:** Sliding Window (Solution 2) — O(N) time.

**Key Insights:**
1. **Reframing:** "2 baskets" = "at most 2 distinct types"
2. **Same as K-distinct:** Generalize to any K by changing the threshold
3. **Delete keys when count = 0:** Crucial for correct distinct count


<br>
<br>

---

```code```
