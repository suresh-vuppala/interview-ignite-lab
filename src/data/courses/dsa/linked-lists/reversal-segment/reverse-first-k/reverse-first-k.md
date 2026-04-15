Reverse the first k nodes of a linked list.

<br>

> Input: head = [1,2,3,4,5], k=3
> Output: [3,2,1,4,5]
> **Key insight:** Reverse the first k nodes (same as full reversal but stop after k steps). Connect the reversed portion to the remaining list.

<br>

---

## Constraints
- `1 ≤ k ≤ N`

<br>

---

## All Possible Edge Cases
1. **K = 0:** no change
2. **K = 1:** no change
3. **K = N:** reverse entire list
4. **K > N:** reverse whatever exists**

<br>

---

## Solution 1: Copy to array, reverse, rebuild

**Intuition:**
The most straightforward approach — array copy approach wastes o(n) space.

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
> Array copy approach wastes O(N) space. Direct pointer manipulation is O(1) space.

> **Key Insight for Improvement:**
> Use Iterative Reverse First K (Optimal) for O(k) time.

<br>

---

## Solution 2: Iterative Reverse First K (Optimal)

**Algorithm:** Reverse k nodes using prev/curr/next. After k steps: original head.next = curr (connects to remainder). Return prev (new head).

### Time Complexity: O(k)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** The original head becomes the "tail" of the reversed segment. It must point to the (k+1)-th node.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Iterative | O(k) | O(1) |

**Key Insights:**
1. **Save original head:** It becomes the junction point after reversal
2. **Connect tail to remainder:** originalHead.next = current (node after reversed part)
3. **Foundation for:** Reverse Between, Reverse K-Groups

<br><br>

---

```code```
