Find the kth element across two sorted arrays.

<br>

> nums1=[2,3,6,7,9], nums2=[1,4,8,10], k=5 → 6
>
> **Key insight:** Binary search: eliminate k/2 elements from one array each step by comparing elements at position k/2.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: Merge k elements

### Time Complexity: O(k)

> **Drawback:**
> Still linear in k — can be O(N) for large k.

> **Key Insight for Improvement:**
> Compare nums1[k/2] with nums2[k/2]. Discard the smaller half (those elements are all < kth). Reduce k by discarded count. O(log k).

<br>

---

## Solution 2: Binary Elimination (Optimal)

**Intuition:** Binary search: eliminate k/2 elements from one array each step by comparing elements at position k/2.

**Algorithm:**
1. If one array exhausted → return other[k-1]
2. If k==1 → return min(nums1[0], nums2[0])
3. Compare nums1[min(k/2,m)-1] and nums2[min(k/2,n)-1]
4. Discard smaller side's elements, reduce k
5. Recurse

### Time Complexity: O(log k)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
nums1=[2,3,6,7,9] nums2=[1,4,8,10] k=5
Compare nums1[2]=6 vs nums2[2]=8. 6<8 → discard nums1[0..2], k=2
nums1=[7,9] nums2=[1,4,8,10] k=2
Compare 7 vs 4. 4<7 → discard nums2[0..1], k=1→min(7,8)=7... (simplified)
```

### Space Complexity: O(log k) recursion

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Merge k elements | O(k) | Varies | Baseline |
| Binary Elimination | O(log k) | O(log k) recursion | Optimal approach |

**Recommended Solution:** Binary Elimination — O(log k) time.

**Key Insights:**
1. **Eliminate k/2 per step:** Logarithmic reduction
2. **Handle edge cases:** One array shorter than k/2
3. **Generalization:** Median of two arrays is k=(m+n+1)/2

<br><br>

---

```code```
