Given an unsorted integer array, find the smallest missing positive integer. Must solve in O(n) time and O(1) extra space. Use index-as-hash: place each number at its correct index (nums[i] at index nums[i]-1).

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-2³¹ ≤ nums[i] ≤ 2³¹ - 1`
- `Must solve in O(n) time and O(1) extra space`

<br>

---

## All Possible Edge Cases

1. **[1,2,3]:** Return 4 (next after all present)
2. **[3,4,-1,1]:** Return 2 (first gap)
3. **[7,8,9,11,12]:** Return 1 (no 1 present)
4. **All negative:** Return 1
5. **Single element [1]:** Return 2
6. **Single element [2]:** Return 1
7. **Contains 0:** 0 is not positive, return 1 if missing
8. **Duplicates:** [1,1] → return 2
9. **Large gaps:** [1,1000] → return 2

<br>

---

```code```
