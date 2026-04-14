Insert a node at the head, tail, or a specific position in a singly linked list.

<br>

> Input: list = 1→2→3, insertAtHead(0) → 0→1→2→3, insertAtTail(4) → 0→1→2→3→4, insertAt(2, 99) → 0→1→99→2→3→4
> **Key insight:** Head insertion: new node's next = head, return new node. Tail: traverse to end. Position: traverse to position-1, rewire. Dummy node simplifies edge cases.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

<br>

---

## Solution 1: Rebuild entire list

**Intuition:**
The most straightforward approach — create new list with element inserted.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Create new list with element inserted. Copy all elements. Wasteful when we only need to rewire one pointer.

> **Key Insight for Improvement:**
> Use Pointer Manipulation (Optimal) for O(1) for head, O(N) for tail/position time.

<br>

---

## Solution 2: Pointer Manipulation (Optimal)

**Algorithm:**
- Head: O(1) — new.next = head, head = new
- Tail: O(N) without tail pointer, O(1) with tail pointer
- Position k: O(k) — traverse to k-1, insert after

### Time Complexity: O(1) for head, O(N) for tail/position
**Why?** Must traverse to insertion point in singly linked list.

**Detailed breakdown:** N = 100,000, insert at position 50,000 → 50,000 pointer follows

### Space Complexity: O(1)

> **Drawback:** Tail insertion is O(N) without a tail pointer. Maintaining a tail pointer makes it O(1).

> **Key Insight for Improvement:** Dummy head node simplifies edge cases — no special handling for empty list or head insertion.

<br>

---

## Complexity Progression Summary

| Operation | Without tail ptr | With tail ptr |
|-----------|-----------------|---------------|
| Insert head | O(1) | O(1) |
| Insert tail | O(N) | O(1) |
| Insert at k | O(k) | O(k) |

**Key Insights:**
1. **Dummy node pattern:** Create dummy → operate → return dummy.next
2. **Rewiring:** New node points to successor, predecessor points to new node
3. **Order matters:** Set new.next BEFORE updating prev.next to avoid losing the rest of the list

<br><br>

---

```code```
