Given a sorted array (may contain negatives), return a sorted array of the squares of each number.

<br>

> Input: [-4, -1, 0, 3, 10]
> Output: [0, 1, 9, 16, 100]
>
> **Key insight:** Largest squares are at the two ends (most negative or most positive). Use two pointers from both ends.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `nums is sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **All positive:** Squares already sorted
2. **All negative:** Squares in reverse order
3. **Contains zero:** 0² = 0, stays small
4. **Single element:** Square it

<br>

---

## Solution 1: Square + Sort

**Intuition:**
Square every element, then sort.

### Time Complexity: O(n log n)
### Space Complexity: O(n) or O(1) depending on sort

<br>

---

## Solution 2: Two Pointers from Ends (Optimal)

**Intuition:**
The largest square is at either end (most negative or most positive). Compare absolute values at both ends, place the larger square at the end of the result array, and move that pointer inward.

**Algorithm:**
1. left = 0, right = n-1, pos = n-1
2. While left ≤ right:
   - If |nums[left]| > |nums[right]| → result[pos] = nums[left]², left++
   - Else → result[pos] = nums[right]², right--
   - pos--

### Time Complexity: O(n) — single pass
### Space Complexity: O(n) — result array

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Square + Sort | O(n log n) | O(n) | Brute force |
| Two Pointers | O(n) | O(n) | Largest squares at ends |

<br>
<br>

---

```code```
