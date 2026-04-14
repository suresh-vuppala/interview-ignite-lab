Count the number of distinct elements in every window of size k.

<br>

> Input:
> nums = [1, 2, 1, 3, 4, 2, 3], k = 4

> Output:
> [3, 4, 4, 3]

> Explanation:
> Window [1,2,1,3]=3 distinct. [2,1,3,4]=4 distinct. [1,3,4,2]=4. [3,4,2,3]=3.
> 
> **Key insight:** Maintain a frequency map as the window slides. When leaving element's count drops to 0, remove it. Map size = distinct count.

<br>



---

## Constraints

- `1 ≤ k ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **All same elements:** Distinct count = 1 for every window
2. **All unique elements:** Distinct count = k for every window
3. **k = 1:** Each element's count = 1

<br>

---

## Solution 1: Brute Force — Set per Window

**Intuition:**
The most straightforward approach. Building a set from scratch for each window — O(K) per window.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N × K)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Building a set from scratch for each window — O(K) per window. Adjacent windows share K-1 elements; rebuilding wastes this overlap.

> **Key Insight for Improvement:**
> Maintain a frequency map. On slide: decrement leaving element (delete if count=0), increment entering element. Distinct count = map.size(). O(1) per slide.

<br>

---

## Solution 2: Sliding Window + Frequency Map (Optimal)

**Algorithm:**
1. Build frequency map for first K elements
2. result.add(map.size())
3. For i = K to N-1:
   - freq[nums[i]]++ (entering)
   - freq[nums[i-K]]-- (leaving)
   - If freq[nums[i-K]] == 0 → delete from map
   - result.add(map.size())

### Time Complexity: O(N)
**Why?**
- Each element added/removed from map at most once
- Map operations: O(1) average

**Detailed breakdown:**
- N = 100,000 → 200,000 map operations
- Compared to brute: N×K → N (K× faster!)

**Example walkthrough:**
```
nums = [1,2,1,3,4,2,3], k=4

Window [1,2,1,3]: freq={1:2,2:1,3:1}, size=3 → output 3
Slide: remove 1(freq 2→1), add 4 → freq={1:1,2:1,3:1,4:1}, size=4 → output 4
Slide: remove 2(1→0, delete), add 2 → freq={1:1,3:1,4:1,2:1}, size=4 → output 4
Slide: remove 1(1→0, delete), add 3(1→2) → freq={3:2,4:1,2:1}, size=3 → output 3

Result: [3, 4, 4, 3] ✓
```

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N×K) | O(K) | Rebuild set per window |
| Freq Map | O(N) | O(K) | Slide: add/remove from map |

**Recommended Solution:** Sliding Frequency Map — O(N) time.

**Key Insights:**
1. **Map size = distinct count:** Delete keys when count reaches 0
2. **Same pattern as all fixed-size windows:** Add entering, remove leaving
3. **Key deletion crucial:** Without it, map size would grow incorrectly


<br>
<br>

---

```code```
