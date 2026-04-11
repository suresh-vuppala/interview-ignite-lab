Count number of longest increasing subsequences.

<br>

---

## Solution 1: DP — Track both length[i] and count[i]. When extending: if longer → new count. If same length → add count.

### Time: O(n²) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DP length+count | O(n²) | O(n) | Track count alongside length |

<br>
<br>

---

```code```
