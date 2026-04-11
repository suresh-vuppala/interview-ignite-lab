Detect if a linked list has a cycle.

<br>

---

## Solution 1: Hash Set — Store visited nodes, check for revisit

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Floyd's Cycle Detection (Optimal)

**Intuition:** Slow moves 1, fast moves 2. If cycle exists, they'll meet. If no cycle, fast reaches null.

### Time: O(n) | Space: O(1)

**Finding cycle start:** After detection, reset one pointer to head. Move both at speed 1. They meet at cycle start.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(n) | O(n) | Track visited |
| Floyd's | O(n) | O(1) | Two-pointer cycle detection |

<br>
<br>

---

```code```
