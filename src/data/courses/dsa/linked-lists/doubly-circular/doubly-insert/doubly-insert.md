Insert at head, tail, or after a given node in a doubly linked list.

<br>

> Example: Insert 0 at head of 1↔2↔3 → 0↔1↔2↔3
> **Key insight:** Update BOTH prev and next pointers. For head insert: new.next = head, head.prev = new.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

## Solution: Pointer Manipulation (Optimal)

### Time Complexity: O(1) for head, O(N) for tail
### Space Complexity: O(1)

> **Drawback:** Must update two pointers per node (prev and next) — more error-prone than singly.

> **Key Insight for Improvement:** Doubly linked list enables O(1) deletion given a node reference — worth the extra pointer maintenance.

<br>

---

**Key Insights:**
1. **Two pointers per link:** new.next = successor, new.prev = predecessor, update both neighbors
2. **O(1) insert at known position:** If you have a reference to the node
3. **Foundation for:** LRU Cache (doubly linked list + hash map)

<br><br>

---

```code```
