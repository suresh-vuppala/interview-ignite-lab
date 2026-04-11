Given two integer arrays, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays. Use hash map to count frequencies.

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
3. **One empty array:** Return []
4. **Duplicate elements in both:** Count minimum frequency
5. **Single element arrays:** Check if same
6. **One array subset of other:** Return the smaller array

<br>

---

```code```
