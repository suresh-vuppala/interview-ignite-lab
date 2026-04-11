Calculate stock span: consecutive days before current day where price was ≤ current price.

<br>

> Input: [100, 80, 60, 70, 60, 75, 85]
> Output: [1, 1, 1, 2, 1, 4, 6]

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `1 ≤ price[i] ≤ 10⁵`

<br>

---

## Solution 1: Brute Force

**Intuition:** For each day, scan backward counting consecutive smaller/equal prices.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Monotonic Stack (Optimal)

**Intuition:**
Stack stores indices of previous higher prices. Span = current index - stack.top() (or current index + 1 if stack empty).

### Time Complexity: O(n)
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Scan backward |
| Monotonic Stack | O(n) | O(n) | Stack tracks previous higher |

<br>
<br>

---

```code```
