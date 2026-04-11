Delete leaf nodes with a given target value. New leaves may also match — repeat until no more matches.

<br>

---

## Solution 1: Postorder DFS (Optimal)

**Intuition:** Process bottom-up (postorder). After deleting children, if current becomes a leaf with target value, delete it too.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Postorder DFS | O(n) | O(h) | Bottom-up handles cascading deletes |

<br>
<br>

---

```code```
