Given an array with n objects colored red (0), white (1), or blue (2), sort them in-place so that objects of the same color are adjacent. This is the Dutch National Flag problem.

<br>

---

## Constraints

- `n == nums.length`
- `1 ≤ n ≤ 300`
- `nums[i] is 0, 1, or 2`
- `Must solve in-place with one pass (follow-up)`

<br>

---

## All Possible Edge Cases

1. **All same color:** [0,0,0] or [1,1,1] — already sorted
2. **Already sorted:** [0,0,1,1,2,2] — no swaps needed
3. **Reverse sorted:** [2,2,1,1,0,0]
4. **Two colors only:** [0,2,0,2] — missing one color
5. **Single element:** [1] — trivially sorted
6. **Only 0s and 2s:** [2,0,2,0] — no 1s present

<br>

---

```code```
