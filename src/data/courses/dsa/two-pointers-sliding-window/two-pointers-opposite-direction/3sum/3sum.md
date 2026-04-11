Find all unique triplets summing to zero.

<br>

> Input: [-1,0,1,2,-1,-4] → Output: [[-1,-1,2],[-1,0,1]]

<br>

---

## Constraints

- `3 ≤ n ≤ 3000`

<br>

---

## Solution 1: Brute Force — All Triplets

### Time: O(n³) | Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** O(n³) — checking all C(n,3) triplets. Also hard to avoid duplicate triplets without sorting.
>
> **Insight:** Sort the array. Fix one element with outer loop. For remaining two, use two-pointer approach (like Two Sum Sorted). Skip duplicates by checking if current equals previous.

<br>

---

## Solution 2: Sort + Two Pointers (Optimal)

**Intuition:** Sort. Fix nums[i]. Two pointers for pair summing to -nums[i]. Skip duplicates.

### Time: O(n²) | Space: O(1) extra

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n³) | O(1) | All triplets |
| Sort + Two Ptr | O(n²) | O(1) | Fix one, two-pointer for pair |

<br>
<br>
