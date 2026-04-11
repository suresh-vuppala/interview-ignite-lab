Find smallest substring of s containing all characters of t.

<br>

> Input: s="ADOBECODEBANC", t="ABC" → Output: "BANC"

<br>

---

## Constraints

- `1 ≤ s.length, t.length ≤ 10⁵`

<br>

---

## Solution 1: Brute Force — Check all substrings O(n² × m)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Checking all O(n²) substrings × O(m) containment check = O(n²m). Massively redundant — when a valid window is found, we don't need to keep expanding.
>
> **Insight:** Variable-size sliding window. Expand right until all t's characters are included. Then shrink left to minimize. Track required character counts with a frequency map and a "formed" counter.

<br>

---

## Solution 2: Sliding Window + Freq Map (Optimal)

**Intuition:** Expand until valid, shrink to minimize.

### Time: O(n) | Space: O(m)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²m) | O(m) | All substrings |
| Sliding Window | O(n) | O(m) | Expand/shrink with freq tracking |

<br>
<br>
