Insert a node into a sorted circular linked list.

<br>

---

## Solution 1: Find Insertion Point

Traverse until finding the right position (prev ≤ val ≤ curr). Handle edge cases: insert at head, insert at tail (max→min boundary).

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Traverse + Insert | O(n) | O(1) | Handle wrap-around boundary |

<br>
<br>

---

```code```
