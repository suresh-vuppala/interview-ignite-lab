Find the median of two sorted arrays in O(log(min(m,n))).

<br>

> nums1=[1,3], nums2=[2] → 2.0
>
> **Key insight:** Binary search on partition of smaller array. Ensure: maxLeft1 ≤ minRight2 AND maxLeft2 ≤ minRight1.

<br>

---

## Constraints
- 0 ≤ M, N ≤ 1000
- 1 ≤ M + N ≤ 2000
- -10⁶ ≤ values ≤ 10⁶

<br>

---

## All Possible Edge Cases
1. **One array empty:** median of the other
2. **Arrays of different lengths**
3. **All elements in one < all in other**
4. **Even vs odd total length**

<br>

---

## Solution 1: Merge and find middle

**Intuition:**
The most straightforward approach. Merging wastes time — we only need the middle element(s).

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(m+n)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Merging wastes time — we only need the middle element(s).

> **Key Insight for Improvement:**
> Binary search on smaller array's partition point. Partition divides both arrays into left/right halves. Adjust until cross-conditions satisfied.

<br>

---

## Solution 2: Binary Search on Partition (Optimal)

**Intuition:** Binary search on partition of smaller array. Ensure: maxLeft1 ≤ minRight2 AND maxLeft2 ≤ minRight1.

**Algorithm:**
1. Ensure nums1 is smaller. Binary search on partition of nums1.
2. partition1 ∈ [0,m], partition2 = (m+n+1)/2 - partition1
3. Check: maxLeft1 ≤ minRight2 AND maxLeft2 ≤ minRight1
4. If yes → median from max(lefts) and min(rights)
5. If maxLeft1 > minRight2 → move left. Else → move right.

### Time Complexity: O(log(min(m,n)))
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
nums1=[1,3], nums2=[2]: partition nums1 at 1 → left=[1], right=[3]
partition nums2 at 1 → left=[2], right=[]
maxLeft=max(1,2)=2, minRight=3 → median=2.0 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Merge and find middle | O(m+n) | Varies | Baseline |
| Binary Search on Partition | O(log(min(m,n))) | O(1) | Optimal approach |

**Recommended Solution:** Binary Search on Partition — O(log(min(m,n))) time.

**Key Insights:**
1. **Binary search on smaller array:** Ensures O(log(min(m,n)))
2. **Partition = left half boundary:** Both arrays split so left has (m+n+1)/2 elements
3. **FAANG hard:** One of the hardest binary search problems

<br><br>

---

```code```
