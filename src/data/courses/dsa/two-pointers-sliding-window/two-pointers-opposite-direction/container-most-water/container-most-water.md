Find two lines forming container holding most water.

<br>

> Input: [1,8,6,2,5,4,8,3,7] → Output: 49

<br>

---

## Constraints

- `2 ≤ n ≤ 10⁵`

<br>

---

## Solution 1: Brute Force — All Pairs

### Time: O(n²) | Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Checking n(n-1)/2 pairs. Most are suboptimal — we're not using any structure to eliminate bad pairs.
>
> **Insight:** Start with widest container (both ends). The SHORTER line limits area. Moving the taller line can only decrease width without improving height. So always move the shorter line inward — it might find a taller line. This greedy approach never skips a potentially better pair.

<br>

---

## Solution 2: Two Pointers — Move Shorter Side (Optimal)

**Intuition:** Start widest. Move shorter side inward — it's the only way area can increase.

### Time: O(n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | All pairs |
| Two Pointers | O(n) | O(1) | Greedy: move shorter side |

<br>
<br>
