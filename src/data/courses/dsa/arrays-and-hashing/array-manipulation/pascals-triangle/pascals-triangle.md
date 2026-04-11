Generate first numRows of Pascal's triangle.

<br>

> Input: 5 → Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

<br>

---

## Solution 1: Row-by-Row Construction (Optimal)

**Intuition:** Each row starts/ends with 1. Interior: row[j] = prev[j-1] + prev[j].

### Time: O(n²) — must generate n² elements
### Space: O(1) extra

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Row-by-Row | O(n²) | O(1) extra | Direct construction — already optimal |

**Note:** Output is O(n²) elements, so O(n²) time is optimal.

<br>
<br>
