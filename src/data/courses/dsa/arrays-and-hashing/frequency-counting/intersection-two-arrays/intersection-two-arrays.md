Given two integer arrays, return their intersection. Each element in the result should appear as many times as it shows in both arrays.

<br>

> Input:
> nums1 = [1,2,2,1], nums2 = [2,2]

> Output:
> [2,2]

> Explanation:
> 2 appears twice in nums1 and twice in nums2. Intersection includes 2 twice.
> 
> **Key insight:** Build frequency map of smaller array. Iterate larger array, consuming matches.

<br>



---

## Constraints

- `1 ≤ nums1.length, nums2.length ≤ 1000`
- `0 ≤ nums1[i], nums2[i] ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **No intersection:** Disjoint arrays → []
2. **Identical arrays:** Full copy
3. **One element each:** Either match or not

<br>

---

## Solution 1: Sort + Two Pointers

**Intuition:**
Sort both arrays. Use two pointers — when equal, add to result and advance both; otherwise advance the smaller one.

**Algorithm:**
1. Sort both arrays
2. i = 0, j = 0
3. While both in bounds:
   - If equal → add, advance both
   - If nums1[i] < nums2[j] → advance i
   - Else → advance j

### Time Complexity: O(N log N + M log M)
**Why?**
- Sorting: O(N log N) + O(M log M)
- Two-pointer merge: O(N + M)

**Detailed breakdown:**
- N=M=1000 → ~9,966 sort ops + 2,000 merge ops ≈ 12K operations

### Space Complexity: O(1) extra
**Why?**
- Only pointer variables (result array not counted)

> **Drawback:**
> Sorting takes O(N log N + M log M) and modifies the arrays. For already-sorted input this is fine, but otherwise we're doing unnecessary work.

> **Key Insight for Improvement:**
> Build a frequency map of the smaller array in O(min(N,M)). Iterate the larger array, consuming matches from the map. Total: O(N + M) time.

<br>

---

## Solution 2: Hash Map Frequency (Optimal)

**Intuition:**
Count frequencies of the smaller array in a map. Iterate the larger array — for each element, if count > 0, add to result and decrement count.

**Algorithm:**
1. Build frequency map of smaller array
2. For each element in larger array:
   - If freq[element] > 0 → add to result, freq[element]--
3. Return result

### Time Complexity: O(N + M)
**Why?**
- Building map: O(min(N,M))
- Iterating: O(max(N,M))
- Total: O(N + M)

**Detailed breakdown:**
- N=M=1000 → 2,000 operations
- Compared to sort: 12,000 → 2,000 (6× faster!)

### Space Complexity: O(min(N,M))
**Why?**
- Map for the smaller array

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + Two Ptr | O(N log N + M log M) | O(1) | Sorted merge |
| Hash Map | O(N + M) | O(min(N,M)) | Frequency matching |

**Recommended Solution:** Hash Map (Solution 2) — O(N + M) time.

**Key Insights:**
1. **Sort → Map:** Avoid sorting overhead with frequency count
2. **Smaller array first:** Build map from smaller array for less space
3. **Consume matches:** Decrement count to handle duplicate frequencies correctly


<br>
<br>

---

```code```
