Return all elements of m×n matrix in spiral order.

<br>

> Input: [[1,2,3],[4,5,6],[7,8,9]] → Output: [1,2,3,6,9,8,7,4,5]

<br>

---

## Constraints

- `1 ≤ m, n ≤ 10`

<br>

---

## Solution 1: Simulation with Visited

**Intuition:** Move in spiral direction. Mark visited. Turn when hitting boundary or visited.

### Time: O(m×n) | Space: O(m×n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** O(m×n) extra space for the visited matrix. Also, direction-changing logic with visited checks is error-prone.
>
> **Insight:** Instead of tracking visited cells, maintain 4 boundary variables (top, bottom, left, right). After traversing one direction, shrink the corresponding boundary. No extra space needed.

<br>

---

## Solution 2: Shrinking Boundaries (Optimal)

**Intuition:** Four boundaries. Traverse right→down→left→up, shrinking after each.

### Time: O(m×n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Visited Matrix | O(m×n) | O(m×n) | Direction + visited tracking |
| Boundaries | O(m×n) | O(1) | Four boundary variables |

<br>
<br>
