Given an integer array nums, return true if any value appears at least twice in the array, and false if every element is distinct.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **All unique:** Return false
2. **All same:** Return true
3. **Single element:** Return false
4. **Duplicate at extremes:** First and last are same
5. **Large array, no duplicates:** HashSet approach O(n) time, O(n) space
6. **Two elements, same value:** Return true

<br>

---

```code```
