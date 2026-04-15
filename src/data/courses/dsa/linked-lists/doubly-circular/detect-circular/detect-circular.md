Detect if a linked list is circular (last node points back to head, not just any cycle).

<br>

> Example: 1→2→3→(back to 1) → true. 1→2→3→null → false.
> **Key insight:** Traverse from head.next. If we return to head → circular. If we hit null → not circular. Different from cycle detection (which detects any cycle, not just full circular).

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

## All Possible Edge Cases
1. **Not circular (has null next)**
2. **Single node pointing to itself**
3. **Empty list**

<br>

---

## Solution 1: Hash Set of visited nodes

**Intuition:**
The most straightforward approach — o(n) space for hash set.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> O(N) space for hash set. Simple traversal checking curr==head is O(1) space.

> **Key Insight for Improvement:**
> Use Traverse and Check (Optimal) for O(N) time.

<br>

---

## Solution 2: Traverse and Check (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** Different from Floyd's cycle detection: we specifically check if any node points back to HEAD (not just any visited node). Simpler traversal suffices.

<br>

---

**Key Insights:**
1. **Circular ≠ cycle:** Circular means tail→head. Cycle means any node→any previous node.
2. **Simple check:** Start from head.next, traverse until null or head found
3. **Floyd's not needed:** We know exactly what we're looking for (head)

<br><br>

---

```code```
