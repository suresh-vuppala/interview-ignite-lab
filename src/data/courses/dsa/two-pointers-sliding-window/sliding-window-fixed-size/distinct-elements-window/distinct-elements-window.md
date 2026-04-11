Count distinct elements in every window of size k.

<br>

> Input: [1,2,1,3,4,2,3], k=4 → Output: [3,4,4,3]

<br>

---

## Solution 1: Brute Force — Set per window O(n×k)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Building a set from scratch for each window — O(k) per window.
>
> **Insight:** Maintain a frequency map. When sliding: decrement leaving element (remove if 0), increment entering element. Distinct count = map size.

<br>

---

## Solution 2: Sliding Window + Freq Map — O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n×k) | O(k) | Rebuild set per window |
| Freq Map | O(n) | O(k) | Slide: add/remove from map |

<br>
<br>
