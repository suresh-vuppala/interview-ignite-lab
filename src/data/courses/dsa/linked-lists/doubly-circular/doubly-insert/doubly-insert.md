Insert at head, tail, or after a given node in a doubly linked list.

<br>

> Example: Insert 0 at head of 1↔2↔3 → 0↔1↔2↔3
> **Key insight:** Update BOTH prev and next pointers. For head insert: new.next = head, head.prev = new.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

## All Possible Edge Cases
1. **Insert into empty DLL**
2. **Insert at head / tail**
3. **Verify both prev and next pointers**

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use Pointer Manipulation (Optimal) for O(1) for head, O(N) for tail time.

<br>

---

## Solution 2: Pointer Manipulation (Optimal)

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
