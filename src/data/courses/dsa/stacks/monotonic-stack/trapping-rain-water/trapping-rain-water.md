Compute water trapped between elevation bars after raining.

<br>

> Input: [0,1,0,2,1,0,1,3,2,1,2,1] → Output: 6
>
> **Key formula:** water[i] = min(maxLeft, maxRight) - height[i]

<br>

---

## Constraints

- `1 ≤ n ≤ 2 × 10⁴`, `0 ≤ height[i] ≤ 10⁵`

<br>

---

## Solution 1: Brute Force — Per-Position Scan

**Intuition:** For each position, find max left and max right. Water = min(maxL, maxR) - h[i].

### Time: O(n²) | Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** For each position, we scan left AND right to find max heights — O(n) per position × n positions = O(n²). We're recomputing the same maxLeft/maxRight values repeatedly.
>
> **Insight:** Precompute leftMax[i] and rightMax[i] arrays in O(n) each. Then water[i] = min(leftMax[i], rightMax[i]) - height[i] in one pass.

<br>

---

## Solution 2: Prefix Max Arrays

### Time: O(n) | Space: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Uses O(n) space for two prefix arrays. Can we eliminate them?
>
> **Insight:** Two pointers from both ends. Track maxLeft and maxRight. Process from the SHORTER side — when height[left] < height[right], water at left depends only on maxLeft (since maxRight ≥ height[right] > height[left]). No arrays needed.

<br>

---

## Solution 3: Two Pointers (Optimal)

**Intuition:** Process from shorter side. Water level determined by the shorter max.

### Time: O(n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Scan left/right per position |
| Prefix Max | O(n) | O(n) | Precompute max arrays |
| Two Pointers | O(n) | O(1) | Process from shorter side |

<br>
<br>
