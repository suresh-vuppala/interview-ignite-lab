Given an integer array, move all zeros to the end while maintaining the relative order of non-zero elements. Must be done in-place.

<br>

> Input: [0, 1, 0, 3, 12]
> Output: [1, 3, 12, 0, 0]

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-2³¹ ≤ nums[i] ≤ 2³¹ - 1`

<br>

---

## All Possible Edge Cases

1. **No zeros:** Array unchanged
2. **All zeros:** Array unchanged
3. **Single element:** Unchanged
4. **Zeros at beginning:** All shift left
5. **Zeros at end:** Already correct

<br>

---

## Solution 1: Extra Array

**Intuition:**
Copy non-zeros to new array, fill rest with zeros.

### Time Complexity: O(n)
### Space Complexity: O(n)

<br>

---

## Solution 2: Two-Pass

**Intuition:**
Pass 1: Write all non-zero elements to the front. Pass 2: Fill remaining positions with zeros.

### Time Complexity: O(n)
### Space Complexity: O(1)

<br>

---

## Solution 3: Two Pointers — Swap (Optimal)

**Intuition:**
Slow pointer `j` marks next position for non-zero. Fast pointer `i` scans. When `nums[i] != 0`, swap `nums[i]` and `nums[j]`, advance both.

**Algorithm:**
1. j = 0 (write position)
2. For each i:
   - If nums[i] != 0 → swap(nums[i], nums[j]), j++

**Why this preserves order:** Non-zeros are placed in the order they appear. Zeros bubble to the right via swaps.

### Time Complexity: O(n) — single pass
### Space Complexity: O(1) — in-place

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Array | O(n) | O(n) | Copy non-zeros |
| Two-Pass | O(n) | O(1) | Write non-zeros, fill zeros |
| Swap | O(n) | O(1) | Single pass with swap |

<br>
<br>

---

```code```
