Find all start indices where an anagram of p occurs in s.

<br>

> Input: s="cbaebabacd", p="abc" → Output: [0,6]

<br>

---

## Constraints

- `1 ≤ s.length, p.length ≤ 3 × 10⁴`

<br>

---

## Solution 1: Brute Force — Check every substring of length |p|

### Time: O(n × m)  |  Space: O(m)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** For each starting position, we rebuild the frequency count from scratch — O(m) per window.
>
> **Insight:** Maintain a frequency count of the current window. As we slide, decrement the leaving char and increment the entering char. Compare with p's frequency — O(1) per slide if we track matches.

<br>

---

## Solution 2: Sliding Window + Frequency Match (Optimal)

**Intuition:** Fixed-size window of |p|. Track how many character frequencies match p's.

### Time: O(n)  |  Space: O(1) — fixed 26-char arrays

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n×m) | O(m) | Rebuild freq per window |
| Sliding Freq | O(n) | O(1) | Slide freq counts, track matches |

<br>
<br>
