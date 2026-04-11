Move all zeros to the end while maintaining relative order of non-zero elements. In-place.

<br>

> Input: [0,1,0,3,12] → Output: [1,3,12,0,0]

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **No zeros:** Unchanged
2. **All zeros:** Unchanged
3. **Zeros at end:** Already correct

<br>

---

## Solution 1: Two-Pass (Copy then Fill)

**Intuition:** Pass 1: Copy all non-zeros to front. Pass 2: Fill remaining with zeros.

### Time Complexity: O(n)
### Space Complexity: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Two passes over the array. Also, the second pass writes zeros even if they were already there.
>
> **Insight:** Use a single-pass swap approach. When we find a non-zero, swap it with the position at the slow pointer. Zeros naturally bubble to the right via swaps.

<br>

---

## Solution 2: Single-Pass Swap (Optimal)

**Intuition:** Slow pointer `j` = next non-zero position. When nums[i] != 0, swap nums[i] and nums[j], advance j.

### Time Complexity: O(n)
### Space Complexity: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two-Pass | O(n) | O(1) | Copy then fill zeros |
| Single-Pass Swap | O(n) | O(1) | Swap in one pass |

<br>
<br>
