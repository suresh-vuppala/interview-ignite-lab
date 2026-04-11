Return intersection of two arrays (each element appears as many times as in both).

<br>

> Input: [1,2,2,1], [2,2] → Output: [2,2]

<br>

---

## Solution 1: Sort + Two Pointers

Sort both, use two pointers to find common elements.

### Time: O(n log n + m log m) | Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Sorting takes O(n log n + m log m) and modifies the arrays. If arrays are already given unsorted, we can do better.
>
> **Insight:** Build a frequency map of the smaller array. Iterate the larger array, consume matches from the map — O(n+m) time.

<br>

---

## Solution 2: Hash Map (Optimal)

Count frequencies, consume matches.

### Time: O(n + m) | Space: O(min(n,m))

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + Two Ptr | O(n log n) | O(1) | Sorted comparison |
| Hash Map | O(n+m) | O(min(n,m)) | Frequency-based matching |

<br>
<br>
