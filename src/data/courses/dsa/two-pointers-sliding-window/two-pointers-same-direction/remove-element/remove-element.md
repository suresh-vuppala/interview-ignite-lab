Given an array nums and value val, remove all occurrences of val in-place and return the new length.

<br>

> Input: nums = [3,2,2,3], val = 3
> Output: 2, nums = [2,2,...]

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 100`
- `0 ≤ nums[i] ≤ 50`
- `0 ≤ val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Empty array:** Return 0
2. **All match val:** Return 0
3. **None match val:** Return n
4. **Single element:** Return 0 or 1

<br>

---

## Solution 1: Two Pointers — Fast/Slow

**Intuition:**
Fast pointer scans. When element != val, copy to slow pointer position.

### Time Complexity: O(n)
### Space Complexity: O(1)

<br>

---

## Solution 2: Two Pointers — Swap with End

**Intuition:**
When you find val at position i, swap with the last element and shrink the array. Avoids unnecessary copies when val is rare.

**Algorithm:**
1. i = 0, n = length
2. While i < n:
   - If nums[i] == val → swap with nums[n-1], n--
   - Else i++
3. Return n

### Time Complexity: O(n)
### Space Complexity: O(1)

**Advantage:** Fewer write operations when val is rare (each element moved at most once).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Fast/Slow | O(n) | O(1) | Copy non-val forward |
| Swap with End | O(n) | O(1) | Fewer writes when val is rare |

<br>
<br>

---

```code```
