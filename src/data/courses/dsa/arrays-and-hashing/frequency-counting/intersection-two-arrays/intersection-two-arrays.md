Given two arrays, return their intersection where each element appears as many times as it shows in both arrays.

<br>

> Input: nums1 = [1,2,2,1], nums2 = [2,2]
> Output: [2,2]

<br>

---

## Constraints

- `1 ≤ nums1.length, nums2.length ≤ 1000`
- `0 ≤ nums1[i], nums2[i] ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **No intersection:** Return []
2. **Identical arrays:** Return same array
3. **One empty:** Return []

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each element in nums1, search nums2 for a match. Mark used elements.

### Time Complexity: O(n × m)
### Space Complexity: O(min(n, m))

<br>

---

## Solution 2: Sort + Two Pointers

**Intuition:**
Sort both arrays. Use two pointers to find common elements.

**Algorithm:**
1. Sort both arrays
2. i = 0, j = 0
3. While both pointers in bounds:
   - If equal → add to result, advance both
   - If nums1[i] < nums2[j] → advance i
   - Else advance j

### Time Complexity: O(n log n + m log m)
### Space Complexity: O(1) extra

<br>

---

## Solution 3: Hash Map (Optimal)

**Intuition:**
Count frequencies in nums1 using hash map. Scan nums2 and consume matches.

**Algorithm:**
1. Build frequency map of nums1
2. For each num in nums2:
   - If freq[num] > 0 → add to result, decrement freq

### Time Complexity: O(n + m)
### Space Complexity: O(min(n, m))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n × m) | O(min(n,m)) | Search for each element |
| Sort + Two Pointers | O(n log n) | O(1) | Sorted comparison |
| Hash Map | O(n + m) | O(min(n,m)) | O(1) frequency lookup |

<br>
<br>

---

```code```
