Find if any subarray of size k has a given sum.

<br>

> Input: [1,2,3,4,5], k=3, target=9 → Output: true (subarray [2,3,4])

<br>

---

## Constraints

- `1 ≤ k ≤ n ≤ 10⁵`

<br>

---

## Solution 1: Brute Force — Sum Each Window

**Intuition:** For each starting position, sum k elements.

### Time: O(n × k)  |  Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** We recalculate the sum from scratch for each window — k additions per window × (n-k+1) windows = O(n×k). Adjacent windows share k-1 elements.
>
> **Insight:** Slide the window: subtract the element leaving, add the element entering. Each transition is O(1) instead of O(k).

<br>

---

## Solution 2: Sliding Window (Optimal)

**Intuition:** Maintain running sum. Slide: sum -= nums[i-k], sum += nums[i].

### Time: O(n)  |  Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n×k) | O(1) | Recompute sum per window |
| Sliding Window | O(n) | O(1) | Add/subtract at edges |

<br>
<br>
