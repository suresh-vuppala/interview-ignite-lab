Deep copy a linked list where each node has a random pointer.

<br>

---

## Solution 1: Hash Map — Map old→new, then copy random pointers

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Interweave Nodes (Optimal)

**Algorithm:**
1. Insert cloned nodes between originals: A→A'→B→B'→C→C'
2. Set random: clone.random = original.random.next
3. Separate lists: restore original, extract clones

### Time: O(n) | Space: O(1) extra (excluding result)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Map | O(n) | O(n) | Map old → new |
| Interweave | O(n) | O(1) | Clone nodes in-place between originals |

<br>
<br>

---

```code```
