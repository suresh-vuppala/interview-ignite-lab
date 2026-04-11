Find first negative number in every window of size k.

<br>

> Input: [-8,2,3,-6,10], k=2 → Output: [-8,-6,-6,0]

<br>

---

## Solution 1: Brute Force — Scan each window for first negative O(n×k)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Scanning k elements per window to find the first negative. Negatives at the start of the window persist across multiple windows.
>
> **Insight:** Use a deque to track negative number indices. As the window slides, remove expired indices from front, add new negatives to back. Front of deque = first negative in current window.

<br>

---

## Solution 2: Deque Tracking (Optimal) — O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n×k) | O(1) | Scan each window |
| Deque | O(n) | O(k) | Track negative indices |

<br>
<br>
