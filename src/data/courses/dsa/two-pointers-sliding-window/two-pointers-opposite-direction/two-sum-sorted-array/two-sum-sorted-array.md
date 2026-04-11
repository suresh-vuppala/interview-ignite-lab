Find two numbers in a sorted array summing to target. Return 1-indexed.

<br>

> Input: [2,7,11,15], target = 9 → Output: [1,2]

<br>

---

## Constraints

- Sorted non-decreasing, exactly one solution

<br>

---

## Solution 1: Brute Force — All Pairs

### Time: O(n²) | Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Checking all pairs ignores the sorted property entirely — O(n²) wasted comparisons.
>
> **Insight:** For each element, binary search for complement in remaining array. Or better: use two pointers from both ends — sum too large → move right left, sum too small → move left right. Converges in O(n).

<br>

---

## Solution 2: Two Pointers (Optimal)

**Intuition:** Left at start, right at end. If sum < target → left++. If sum > target → right--. Sorted order guarantees convergence.

### Time: O(n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | All pairs |
| Two Pointers | O(n) | O(1) | Sorted → converge from ends |

<br>
<br>
