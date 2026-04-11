Find distance (number of edges) between two nodes.

<br>

---

## Solution 1: LCA + Depths

**Intuition:** Distance = depth(p) + depth(q) - 2 × depth(LCA(p,q))

1. Find LCA
2. Find depth of p from LCA
3. Find depth of q from LCA
4. Distance = depthP + depthQ

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| LCA + Depths | O(n) | O(h) | Reduce to LCA problem |

<br>
<br>

---

```code```
