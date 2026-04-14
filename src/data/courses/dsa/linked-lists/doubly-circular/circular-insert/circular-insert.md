Insert a node into a circular linked list.

<br>

> Example: Insert 4 into circular 1→2→3→(back to 1) → 1→2→3→4→(back to 1)
> **Key insight:** Find the tail (node whose next is head). Insert new node: tail.next = new, new.next = head. For sorted insertion, find correct position.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

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
> Use Find Tail + Insert (Optimal) for O(N) time.

<br>

---

## Solution 2: Find Tail + Insert (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** O(N) to find tail. With tail pointer maintained, insertion is O(1).

> **Key Insight for Improvement:** Circular list: last node points to head instead of null. No null termination — must check node.next == head for end detection.

<br>

---

**Key Insights:**
1. **No null:** Last node points back to head
2. **Empty list:** Single node points to itself
3. **Tail detection:** curr.next == head means curr is the tail

<br><br>

---

```code```
