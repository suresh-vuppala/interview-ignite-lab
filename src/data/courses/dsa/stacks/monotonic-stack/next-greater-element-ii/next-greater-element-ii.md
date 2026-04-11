Circular version of Next Greater Element.

<br>

> Input: [1, 2, 1]
> Output: [2, -1, 2]

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## Solution 1: Brute Force — Check 2n elements for each

### Time Complexity: O(n²)

<br>

---

## Solution 2: Monotonic Stack + Double Array (Optimal)

**Intuition:**
Iterate 2n times (simulate circular by using i % n). Same monotonic stack approach.

### Time Complexity: O(n)
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Scan 2n for each element |
| Stack + Circular | O(n) | O(n) | Double traversal with i%n |

<br>
<br>

---

```code```
