Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `k is in range [1, number of unique elements]`
- `Answer is unique`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Return the most frequent element
2. **All same elements:** Return that element
3. **All unique:** Any k elements valid
4. **k equals unique count:** Return all unique elements
5. **Negative numbers:** Frequency counting works same way
6. **Single element:** Return it

<br>

---

```code```
