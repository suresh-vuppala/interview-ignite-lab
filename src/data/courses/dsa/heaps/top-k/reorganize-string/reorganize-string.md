Reorganize string so no two adjacent chars are same.

<br>

---

## Solution 1: Max Heap

Always place most frequent char next. Use max-heap sorted by frequency.

### Time: O(n log 26) = O(n) | Space: O(1)

<br>

---

## Solution 2: Greedy Fill Even/Odd Positions

Count frequencies. Place most frequent at even indices, rest at remaining spots.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Max Heap | O(n) | O(1) | Always pick most frequent |
| Index Fill | O(n) | O(1) | Even positions first |

<br>
<br>

---

```code```
