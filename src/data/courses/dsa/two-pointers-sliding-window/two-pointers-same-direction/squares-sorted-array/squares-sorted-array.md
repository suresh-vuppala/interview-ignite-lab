Given sorted array (may contain negatives), return sorted array of squares.

<br>

> Input: [-4,-1,0,3,10] → Output: [0,1,9,16,100]

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁴`, nums is sorted non-decreasing

<br>

---

## Solution 1: Square + Sort

### Time: O(n log n) | Space: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Sorting after squaring is O(n log n). We're ignoring the original sorted order.
>
> **Insight:** Largest squares are at the two ENDS (most negative or most positive). Compare absolute values from both ends, place larger square at the end of result array. Single pass = O(n).

<br>

---

## Solution 2: Two Pointers from Ends (Optimal)

**Intuition:** Left and right pointers. Compare |nums[left]| vs |nums[right]|. Place larger square at result[pos--].

### Time: O(n) | Space: O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Square + Sort | O(n log n) | O(n) | Ignore original order |
| Two Pointers | O(n) | O(n) | Largest squares at ends |

<br>
<br>
