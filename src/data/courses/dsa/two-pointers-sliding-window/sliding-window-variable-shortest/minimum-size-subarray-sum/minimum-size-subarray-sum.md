Find minimal length subarray with sum ≥ target.

<br>

> Input: target=7, nums=[2,3,1,2,4,3] → Output: 2 ([4,3])

<br>

---

## Solution 1: Brute Force — O(n²)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Checking all O(n²) subarrays. Once sum ≥ target, we don't need to keep extending.
>
> **Insight:** Sliding window — expand until sum ≥ target, then shrink from left to find minimum length. All elements positive → sum increases with expansion.

<br>

---

## Solution 2: Sliding Window — O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | All subarrays |
| Sliding Window | O(n) | O(1) | Expand then shrink |

<br>
<br>
