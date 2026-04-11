Given a rotated sorted array with unique elements and a target value, return the index of target or -1. Must solve in O(log n) time.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 5000`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `All values are unique`
- `nums was sorted then rotated 1 to n times`
- `Must solve in O(log n)`

<br>

---

## All Possible Edge Cases

1. **Not rotated:** Standard binary search
2. **Target at pivot:** Found at the rotation point
3. **Target not in array:** Return -1
4. **Single element:** Check if it's the target
5. **Two elements:** Check both
6. **Target in left sorted half:** Standard BS on left
7. **Target in right sorted half:** Standard BS on right

<br>

---

```code```
