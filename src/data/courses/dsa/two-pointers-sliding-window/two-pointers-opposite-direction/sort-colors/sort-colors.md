Sort an array of 0s, 1s, and 2s in-place (Dutch National Flag problem).

<br>

> Input: [2, 0, 2, 1, 1, 0]
> Output: [0, 0, 1, 1, 2, 2]

<br>

---

## Constraints

- `1 ≤ n ≤ 300`
- `nums[i] is 0, 1, or 2`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** No swaps needed
2. **All same color:** No swaps needed
3. **Reverse sorted:** Maximum swaps
4. **Two colors only:** Missing one value
5. **Single element:** Trivially sorted

<br>

---

## Solution 1: Counting Sort

**Intuition:**
Count 0s, 1s, 2s. Overwrite array.

**Algorithm:**
1. Count occurrences of 0, 1, 2
2. Fill array: c0 zeros, then c1 ones, then c2 twos

### Time Complexity: O(n) — two passes
### Space Complexity: O(1)

<br>

---

## Solution 2: Dutch National Flag — Three Pointers (Optimal)

**Intuition:**
Three regions: [0..lo-1] = 0s, [lo..mid-1] = 1s, [hi+1..n-1] = 2s. Process [mid..hi] as unknown.

**Algorithm:**
1. lo = 0, mid = 0, hi = n-1
2. While mid ≤ hi:
   - If nums[mid] == 0 → swap(lo, mid), lo++, mid++
   - If nums[mid] == 1 → mid++ (already in correct zone)
   - If nums[mid] == 2 → swap(mid, hi), hi-- (don't advance mid — swapped element is unknown)

**Why not advance mid on swap with hi?** The element swapped from hi is unprocessed — it could be 0, 1, or 2.

### Time Complexity: O(n) — single pass
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Counting Sort | O(n) | O(1) | Two passes — count then fill |
| Dutch National Flag | O(n) | O(1) | Single pass, three-way partition |

**Recommended:** Dutch National Flag — single pass, in-place.

<br>
<br>

---

```code```
