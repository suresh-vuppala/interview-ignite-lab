Delete a given node from a doubly linked list in O(1) time.

<br>

> Example: Delete node 3 from 1↔2↔3↔4 → 1↔2↔4
> **Key insight:** With doubly linked list, we have direct access to both predecessor and successor. Rewire: prev.next = target.next, target.next.prev = target.prev. O(1)!

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

## Solution: Direct Pointer Rewiring (Optimal)

### Time Complexity: O(1) given node reference
### Space Complexity: O(1)

> **Drawback:** None — this is the KEY advantage of doubly linked lists over singly.

> **Key Insight for Improvement:** O(1) deletion is why DLL is used in LRU Cache alongside a hash map. Singly LL deletion given a node is O(N) (need predecessor).

<br>

---

**Key Insights:**
1. **O(1) deletion:** The main advantage over singly linked list
2. **Handle head/tail:** Check if target is head or tail, update accordingly
3. **Used in:** LRU Cache, LFU Cache — O(1) eviction

<br><br>

---

```code```
