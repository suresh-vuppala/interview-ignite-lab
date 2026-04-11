Count sum of prefix scores for each word.

<br>

---

## Solution 1: Trie with Count — During insertion, increment count at each node. Query: sum counts along path.

### Time: O(n × L) | Space: O(n × L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Trie + Count | O(nL) | O(nL) | Count during insertion |

<br>
<br>

---

```code```
