Given an array of fruits where each number represents a fruit type, find the maximum number of fruits you can collect with two baskets, where each basket can only hold one type of fruit.

<br>

> Input:
> fruits = [1,2,1,2,3,2,2]

> Output:
> 5

> Explanation:
> Collect fruits [2,1,2,3,2] or [1,2,3,2,2] (5 fruits with 2 types)
> Best is [2,3,2,2] starting at index 4 (4 fruits) or [1,2,1,2] (4 fruits)
> Actually best is [2,3,2,2,2] but that's only in extended array
> Correct: [2,1,2,2] at indices 3-6 gives 4 fruits with types {1,2}
> Wait: [3,2,2] at indices 4-6 gives 3 fruits with types {2,3}
> Best: [1,2,1,2] at indices 0-3 or [2,3,2,2] at indices 3-6 both give length 4
> Actually [2,3,2,2] at indices 3-6 is length 4
> Let me recalculate: [1,2,1,2,3,2,2]
> - [1,2,1,2] (indices 0-3): 4 fruits, types {1,2} ✓
> - [2,1,2,3] (indices 1-4): 4 fruits, types {1,2,3} ✗
> - [1,2,3,2,2] (indices 2-6): 5 fruits, types {1,2,3} ✗
> - [2,3,2,2] (indices 3-6): 4 fruits, types {2,3} ✓
> - [3,2,2] (indices 4-6): 3 fruits, types {2,3} ✓
> 
> Maximum with at most 2 types is 4
> 
> **Key insight:** Find longest subarray with at most 2 distinct elements.

<br>



---

## Constraints

- `1 ≤ fruits.length ≤ 10⁵`
- `0 ≤ fruits[i] < fruits.length`

<br>

---

## All Possible Edge Cases

1. **Only 1 type of fruit:** Return entire array length
2. **Only 2 types total:** Return entire array length
3. **All different types:** Maximum window is 2 (any adjacent pair of distinct types)
4. **Single fruit:** Return 1
5. **Two fruits:** Return 2
6. **Same type at start and end:** [1, 2, 1] → 3
7. **Long run of one type:** [1, 1, 1, 2, 3] → 4 (first four)

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible subarrays. Count distinct fruit types. If types ≤ 2, it's valid.

**Algorithm:**
1. For each starting position i
2. For each ending position j ≥ i
3. Count distinct types in subarray [i, j]
4. If types ≤ 2, update max length

### Time Complexity: O(n²)
**Why?**
- Two nested loops: O(n²) subarrays
- Counting distinct types: O(1) with set (amortized)
- Total: O(n²)

### Space Complexity: O(n)
**Why?**
- Set to track distinct types
- Worst case: all elements distinct

**Problem:** Checking all subarrays is inefficient.

> **Key Insight for Improvement:**
> Use sliding window with frequency map. Maintain window with at most 2 distinct types. Expand right, shrink left when types > 2.

<br>

---

## Solution 2: Sliding Window with HashMap

**Intuition:**
Maintain a window with at most 2 distinct fruit types using a frequency map. When types exceed 2, shrink from left.

**Algorithm:**
1. Use frequency map to track fruit types
2. Expand right, add fruit to map
3. While distinct types > 2:
   - Remove fruit at left from map
   - Move left forward
4. Update max length

### Time Complexity: O(n)
**Why?**
- Right pointer moves n times: O(n)
- Left pointer moves at most n times total: O(n)
- Map operations: O(1) average
- Total: O(n)

**Improvement:**
- Before: O(n²)
- After: O(n)
- Example: n=10000
  - Brute: 100,000,000 operations
  - Sliding: 10,000 operations (10,000× faster!)

### Space Complexity: O(1)
**Why?**
- Map stores at most 3 fruit types (2 valid + 1 being removed)
- Constant space

> **Key Insight for Improvement:**
> We can optimize by maintaining window size instead of always shrinking to valid state.

<br>

---

## Solution 3: Optimized Sliding Window

**Intuition:**
Once we find a valid window of size x with 2 types, we only care about windows ≥ x. Maintain window size and slide it.

**Algorithm:**
1. Track fruit types with frequency map
2. Expand right always
3. If types > 2, move left once (slide window)
4. If types ≤ 2, window grows
5. Final window size is the answer

### Time Complexity: O(n)
**Why?**
- Single pass through array
- Each pointer moves at most n times
- Constant work per iteration

### Space Complexity: O(1)
**Why?**
- Map stores at most 3 types
- Constant space

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(n) | Checks all subarrays |
| Sliding Window | O(n) | O(1) | Shrinks to valid state |
| Optimized Window | O(n) | O(1) | Maintains window size |

> **Recommended Solution:** Sliding Window - O(n) time, O(1) space

<br>
<br>

---

```code```
