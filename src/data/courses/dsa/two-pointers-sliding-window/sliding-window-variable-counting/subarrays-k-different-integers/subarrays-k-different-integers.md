Given an integer array nums and an integer k, return the number of subarrays with exactly k different integers. Use the trick: exactly(k) = atMost(k) - atMost(k-1).

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 2 × 10⁴`
- `1 ≤ nums[i], k ≤ nums.length`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Count subarrays with exactly 1 distinct element
2. **k = n:** Only full array if all distinct
3. **All same elements:** Every subarray has 1 distinct — answer depends on k
4. **k > distinct count:** Return 0
5. **Array of length 1:** Return 1 if k=1, else 0

<br>

---

```code```
