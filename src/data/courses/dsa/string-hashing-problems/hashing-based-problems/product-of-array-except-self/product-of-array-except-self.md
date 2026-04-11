Given an integer array nums, return an array answer such that answer[i] is the product of all elements except nums[i]. Must run in O(n) without using division.

<br>

---

## Constraints

- `2 ≤ nums.length ≤ 10⁵`
- `-30 ≤ nums[i] ≤ 30`
- `Product of any prefix/suffix fits in 32-bit integer`
- `Must solve in O(n) without division`

<br>

---

## All Possible Edge Cases

1. **Contains one zero:** All products are 0 except at the zero's position
2. **Contains multiple zeros:** All products are 0
3. **All ones:** Result is all ones
4. **Two elements:** [a,b] → [b,a]
5. **Negative numbers:** Product signs alternate
6. **Single negative, rest positive:** One negative result

<br>

---

```code```
