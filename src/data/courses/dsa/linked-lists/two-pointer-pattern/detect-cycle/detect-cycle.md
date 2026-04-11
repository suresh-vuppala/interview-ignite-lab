Detect if a linked list has a cycle. If yes, find the cycle start node.

<br>

> Input: 3→2→0→-4→(back to 2)
> Output: true, cycle starts at node 2

<br>

---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `-10⁵ ≤ Node.val ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **No cycle:** Fast reaches null
2. **Cycle at head:** Tail points to head
3. **Single node with self-loop:** node.next = node
4. **Single node no loop:** Return false

<br>

---

## Solution 1: Hash Set

**Intuition:** Store visited nodes. If we visit the same node twice → cycle.

### Time Complexity: O(n)
### Space Complexity: O(n) — hash set

<br>

---

## Solution 2: Floyd's Cycle Detection (Optimal)

**Intuition:**
Slow pointer moves 1 step, fast moves 2 steps. If cycle exists, they'll meet inside the cycle.

**Detection:** If fast reaches null → no cycle. If slow == fast → cycle.

**Finding cycle start:** After meeting, reset one pointer to head. Move both at speed 1. They meet at cycle start.

**Why?** If cycle starts at distance `a` from head, and meeting point is `b` into the cycle, then the remaining cycle distance `c - b` equals `a` (modular arithmetic).

### Time Complexity: O(n)
### Space Complexity: O(1) — just two pointers

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(n) | O(n) | Store visited nodes |
| Floyd's | O(n) | O(1) | Two-pointer — no extra space |

**Recommended:** Floyd's — O(1) space.

<br>
<br>

---

```code```
