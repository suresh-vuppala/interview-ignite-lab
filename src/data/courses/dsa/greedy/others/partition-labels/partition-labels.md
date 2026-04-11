Partition string so each letter appears in at most one part. Maximize parts.

<br>

---

## Solution 1: Last Occurrence + Greedy

Track last occurrence of each char. Extend partition until index == max last occurrence in partition.

### Time: O(n) | Space: O(1) — 26-char array

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Last Occurrence | O(n) | O(1) | Greedy partition boundary |

<br>
<br>

---

```code```
