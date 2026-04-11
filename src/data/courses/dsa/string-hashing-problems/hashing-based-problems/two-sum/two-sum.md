Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. Use a hash map for O(n) solution.

<br>

---

## Constraints

- `2 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `-10⁹ ≤ target ≤ 10⁹`
- `Exactly one solution exists`
- `Cannot use the same element twice`

<br>

---

## All Possible Edge Cases

1. **Two elements only:** Must be the answer pair
2. **Negative numbers:** [-3, 4, 3, 90] target=0 → [0,2]
3. **Target is 0:** Need a + b = 0
4. **Duplicate values:** [3,3] target=6 → [0,1] — same value, different indices
5. **Large values:** Watch for integer overflow in sum
6. **First and last elements:** Answer at array extremes

<br>

---

```code```
