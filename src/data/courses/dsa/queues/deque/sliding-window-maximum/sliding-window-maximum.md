Find maximum in each sliding window of size k.

<br>

> Input: [1,3,-1,-3,5,3,6,7], k=3 → Output: [3,3,5,5,6,7]

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁵`, `1 ≤ k ≤ n`

<br>

---

## Solution 1: Brute Force — Scan each window

### Time: O(n×k) | Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Finding max by scanning k elements per window. When the window slides, we discard the max-finding work from the previous window.
>
> **Insight:** Use a monotonic decreasing deque of indices. The front always holds the current max. Remove from back if smaller than incoming (they'll never be max). Remove from front if expired. Each element is pushed/popped at most once → amortized O(1).

<br>

---

## Solution 2: Monotonic Deque (Optimal)

**Intuition:** Decreasing deque. Front = max. Remove expired front, remove smaller back.

### Time: O(n) | Space: O(k)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n×k) | O(1) | Scan each window |
| Monotonic Deque | O(n) | O(k) | Amortized O(1) per element |

<br>
<br>
