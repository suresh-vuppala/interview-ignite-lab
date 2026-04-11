Given a sorted array, remove duplicates in-place. Return new length.

<br>

> Input: [0,0,1,1,1,2,2,3,3,4] → Output: 5, nums = [0,1,2,3,4,...]
>
> **Key insight:** Slow pointer marks write position, fast pointer scans for new unique values.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 3 × 10⁴`
- `nums is sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **All unique:** Return n
2. **All same:** Return 1
3. **Single element:** Return 1

<br>

---

## Solution 1: Extra Array

**Intuition:** Copy unique elements to new array, then copy back.

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Uses O(n) extra space. Since the array is already sorted, duplicates are adjacent — we can handle this in-place with two pointers.
>
> **Insight:** Use slow pointer `j` as write position. When fast pointer `i` finds a new value (nums[i] != nums[j]), write it to nums[++j]. Single pass, O(1) space.

<br>

---

## Solution 2: Two Pointers — Slow/Fast (Optimal)

**Intuition:** Slow pointer `j` marks last unique. Fast pointer `i` scans. On new value, advance j and copy.

**Algorithm:**
1. j = 0
2. For i = 1 to n-1: if nums[i] != nums[j] → j++, nums[j] = nums[i]
3. Return j + 1

### Time Complexity: O(n) — single pass
### Space Complexity: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Array | O(n) | O(n) | Copy uniques |
| Two Pointers | O(n) | O(1) | In-place with slow/fast |

<br>
<br>
