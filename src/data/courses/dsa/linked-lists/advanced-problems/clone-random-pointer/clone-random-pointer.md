Clone a linked list with random pointer (same as copy-random-pointer, in advanced section). Deep copy with both next and random pointers preserved.

<br>

> Input: list with random pointers
> Output: deep copy
> **Key insight:** Hash map approach: map each original node to its clone. Two passes: create clones, then set next and random pointers using the map.

<br>

---

## Constraints
- `0 ≤ N ≤ 1000`

<br>

---

## Solution: Hash Map (Simple and Clean)

**Algorithm:** Pass 1: create clone for each node, store in map. Pass 2: for each node, clone.next = map[node.next], clone.random = map[node.random].

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** O(N) extra space for map. Interleave technique gives O(1) space (see copy-random-pointer).

> **Key Insight for Improvement:** Hash map approach is simpler to implement. Interleave approach saves space but is harder to get right.

<br>

---

**Key Insights:**
1. **Two approaches:** Hash map (O(N) space, simple) vs Interleave (O(1) space, complex)
2. **Map original→clone:** Enables O(1) lookup for random pointer assignment
3. **Two passes:** Create all clones first, then wire pointers

<br><br>

---

```code```
