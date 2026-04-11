Find longest subarray with sum ≤ K (positive integers only).

<br>

> Input: [1,2,3,4,5], k=10 → Output: 4 ([1,2,3,4])

<br>

---

## Solution 1: Brute Force — All subarrays O(n²)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Checking all O(n²) subarrays. When sum exceeds k, we reset and start from next position.
>
> **Insight:** Since all elements are positive, sum only increases as we expand. When sum > k, shrink from left. This monotonic property enables a sliding window.

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
| Sliding Window | O(n) | O(1) | Shrink when sum > k |

<br>
<br>
