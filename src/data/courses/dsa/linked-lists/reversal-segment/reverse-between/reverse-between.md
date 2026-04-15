Reverse nodes from position left to position right (1-indexed) in a linked list.

<br>

> Input: head = [1,2,3,4,5], left=2, right=4
> Output: [1,4,3,2,5]
> **Key insight:** Traverse to position left-1 (the node before the reversal segment). Reverse the segment. Reconnect both ends.

<br>

---

## Constraints
- `1 ≤ left ≤ right ≤ N`

<br>

---

## All Possible Edge Cases
1. **left = right:** no change
2. **left = 1:** reverse from head
3. **right = N:** reverse to tail
4. **left = 1, right = N:** reverse entire list**

<br>

---

## Solution 1: Copy to array, reverse segment, rebuild

**Intuition:**
The most straightforward approach — extra space for array copy.

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
> Extra space for array copy. Pointer manipulation does it in-place.

> **Key Insight for Improvement:**
> Use Find Start + Reverse Segment (Optimal) for O(N) time.

<br>

---

## Solution 2: Find Start + Reverse Segment (Optimal)

**Algorithm:**
1. Use dummy node. Traverse to node at position (left-1) = prev.
2. Reverse (right-left+1) nodes starting from prev.next.
3. Reconnect: prev.next = new segment head, segment tail.next = remainder.

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** None — single pass.

> **Key Insight for Improvement:** Dummy node is essential — handles left=1 (reversing from head) cleanly.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Single pass | O(N) | O(1) |

**Key Insights:**
1. **Dummy node:** Handles left=1 without special cases
2. **Three-step:** Find start, reverse segment, reconnect
3. **Foundation for:** Reverse K-Groups applies this repeatedly

<br><br>

---

```code```
