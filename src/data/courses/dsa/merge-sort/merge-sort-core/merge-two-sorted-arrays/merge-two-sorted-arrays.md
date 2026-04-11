Merge nums2 into nums1 (which has enough space). Both sorted.

<br>

> Input: nums1=[1,2,3,0,0,0], m=3, nums2=[2,5,6], n=3 → Output: [1,2,2,3,5,6]

<br>

---

## Solution 1: Copy + Sort — O((m+n) log(m+n))
## Solution 2: Three Pointers from End (Optimal)

**Intuition:** Fill from the END of nums1. Compare last elements of both, place larger at back.

### Time: O(m+n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Copy + Sort | O((m+n)log) | O(1) | Brute force |
| Three Ptr End | O(m+n) | O(1) | Fill from back avoids overwriting |

<br>
<br>
