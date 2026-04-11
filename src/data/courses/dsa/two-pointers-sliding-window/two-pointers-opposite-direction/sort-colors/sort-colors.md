Sort array of 0s, 1s, 2s in-place (Dutch National Flag).

<br>

> Input: [2,0,2,1,1,0] → Output: [0,0,1,1,2,2]

<br>

---

## Constraints

- `1 ≤ n ≤ 300`, nums[i] is 0, 1, or 2

<br>

---

## Solution 1: Counting Sort — Two Pass

**Intuition:** Count 0s, 1s, 2s. Overwrite array.

### Time: O(n) | Space: O(1) — Two passes

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Requires two passes — one to count, one to write. Can we do it in a single pass?
>
> **Insight:** Three pointers: lo (boundary of 0s), mid (current), hi (boundary of 2s). Process unknown region [mid..hi]. Swap 0s to lo, 2s to hi, skip 1s. Single pass.

<br>

---

## Solution 2: Dutch National Flag — Three Pointers (Optimal)

**Intuition:** lo, mid, hi pointers. Mid scans: 0→swap to lo, 1→skip, 2→swap to hi.

### Time: O(n) | Space: O(1) — Single pass

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Counting Sort | O(n) | O(1) | Two passes |
| Dutch Flag | O(n) | O(1) | Single pass, three-way partition |

<br>
<br>
