Design a stack that supports push, pop, top, and retrieving the maximum element, all in O(1) time.

<br>

> Input: push(5), push(1), push(5), top(), popMax(), top(), popMax(), top()
> Output: 5, 5, 1, 5, -1 (empty)

> Explanation: Similar to Min Stack but tracking maximum. popMax removes the max element.
> 
> **Key insight:** Same pattern as Min Stack — maintain a parallel max stack tracking current max at each level.

<br>

---

## Constraints
- All ops called on non-empty stack (except push)

<br>

---

## All Possible Edge Cases
1. **Pop max when it's not on top
2. **Multiple elements with same max value
3. **Single element**

<br>

---

## Solution 1: Naive / Brute Force Approach

**Intuition:**
Try the most straightforward method without optimization.

**Algorithm:**
1. Apply the direct/naive approach
2. May involve extra space, multiple passes, or higher time complexity
3. Serves as baseline to understand the problem before optimizing

### Time Complexity: Higher than optimal
**Why?**
Does not exploit key structural properties of the problem.

### Space Complexity: May use extra space

> **Drawback:**
> Less efficient approach exists.

> **Key Insight for Improvement:**
> Use Two Stacks — Main + Max Stack (Optimal for getMax/push/pop) for optimal performance.

<br>

---

## Solution 2: Two Stacks — Main + Max Stack (Optimal for getMax/push/pop)

**Intuition:** Parallel stack where max[i] = max of all elements at level i and below.

**Algorithm:** Same as Min Stack but track max instead of min.

### Time Complexity: O(1) per push/pop/top/getMax

### Space Complexity: O(N)

> **Drawback:** popMax (remove the actual max element) requires O(N) — need to find and remove from middle of stack.

> **Key Insight for Improvement:** For O(1) push/pop/getMax without popMax, two-stack approach is optimal. For popMax, need more complex data structure (doubly-linked list + TreeMap).

<br>

---

## Complexity Progression Summary

| Operation | Time |
|-----------|------|
| push | O(1) |
| pop | O(1) |
| top | O(1) |
| getMax | O(1) |

**Key Insights:**
1. **Mirror of Min Stack:** Track max instead of min at each level
2. **popMax is harder:** Requires finding and removing from middle — different problem class

<br><br>

---

```code```
