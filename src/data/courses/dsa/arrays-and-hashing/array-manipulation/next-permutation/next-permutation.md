Rearrange numbers into the lexicographically next greater permutation. If no next permutation exists (largest), rearrange to smallest. Must modify in-place with O(1) extra memory.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 100`
- `0 ≤ nums[i] ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Already largest permutation:** [3,2,1] → [1,2,3] (wrap to smallest)
2. **Already smallest:** [1,2,3] → [1,3,2]
3. **Single element:** [1] → [1]
4. **Two elements:** [1,2] → [2,1] and vice versa
5. **Duplicates:** [1,1,5] → [1,5,1]
6. **All same elements:** [2,2,2] → [2,2,2] (no change)
7. **Long descending suffix:** [1,5,4,3,2] → [2,1,3,4,5]

<br>

---

```code```
