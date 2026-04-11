Partition list around value x: all nodes < x come before nodes ≥ x.

<br>

---

## Solution 1: Two Dummy Lists

Create two lists (less and greater-equal). Scan and distribute. Connect less tail → greater-equal head.

### Time: O(n) | Space: O(1) — reuse existing nodes

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Lists | O(n) | O(1) | Distribute and reconnect |

<br>
<br>

---

```code```
