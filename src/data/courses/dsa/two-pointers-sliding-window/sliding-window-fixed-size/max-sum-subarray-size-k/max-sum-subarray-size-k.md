Find maximum sum of any subarray of size k.

<br>

> Input: [2,1,5,1,3,2], k=3 → Output: 9 (subarray [5,1,3])

<br>

---

## Solution 1: Brute Force — O(n×k)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Summing k elements per window is redundant — adjacent windows differ by only 2 elements.
>
> **Insight:** Sliding window: maintain running sum. Slide by subtracting leftmost, adding rightmost.

<br>

---

## Solution 2: Sliding Window — O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n×k) | O(1) | Resum each window |
| Sliding Window | O(n) | O(1) | Running sum |

<br>
<br>
