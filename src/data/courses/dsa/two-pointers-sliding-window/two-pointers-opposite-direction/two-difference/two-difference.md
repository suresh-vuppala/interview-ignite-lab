Find pair with given difference in unsorted array.

<br>

---

## Solution 1: Brute Force — All pairs O(n²)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Checking all pairs is O(n²).
>
> **Insight:** Sort + two pointers. If diff too small → advance right. If diff too large → advance left. Both pointers only move forward.

<br>

---

## Solution 2: Sort + Two Pointers — O(n log n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | All pairs |
| Sort + Two Ptr | O(n log n) | O(1) | Sorted difference check |

<br>
<br>
