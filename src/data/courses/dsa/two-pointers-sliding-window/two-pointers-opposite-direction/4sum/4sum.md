Find all unique quadruplets summing to target.

<br>

> Input: [1,0,-1,0,-2,2], target=0 → Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

<br>

---

## Constraints

- `1 ≤ n ≤ 200`, `-10⁹ ≤ nums[i], target ≤ 10⁹`

<br>

---

## Solution 1: Brute Force — O(n⁴)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** O(n⁴) — checking all 4-element combinations.
>
> **Insight:** Extend 3Sum: fix TWO elements with nested loops, then use two-pointer for the pair. This reduces one order of magnitude: O(n⁴) → O(n³).

<br>

---

## Solution 2: Sort + Two Loops + Two Pointers (Optimal)

### Time: O(n³) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n⁴) | O(1) | All quadruplets |
| Sort + Two Ptr | O(n³) | O(1) | Fix two, two-pointer for pair |

<br>
<br>
