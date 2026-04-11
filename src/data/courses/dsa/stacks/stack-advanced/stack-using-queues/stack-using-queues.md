Implement a LIFO stack using only two queues. Support push, pop, top, and empty.

<br>

> Input: push(1), push(2), top(), pop(), empty()
> Output: 2, 2, false

> Explanation: Stack behavior using queues. Push 1, push 2. Top=2, pop=2. Stack has [1].
> 
> **Key insight:** After pushing to queue, rotate all previous elements behind the new one. This makes the front = most recent element (LIFO order).

<br>

---

## Constraints
- 1 ≤ x ≤ 9
- At most 100 calls

<br>

---

## Solution 1: Push O(N), Pop O(1)

**Intuition:** On push, add to queue then rotate N-1 elements to the back. Front is always the most recent.

**Algorithm:**
- push(x): queue.add(x). For i=0 to size-2: queue.add(queue.remove()) — rotate old to back
- pop(): queue.remove() — front is most recent
- top(): queue.peek()
- empty(): queue.isEmpty()

### Time Complexity: Push O(N), Pop O(1), Top O(1)

**Detailed breakdown:** Push rotates N-1 elements each time. Total for N pushes: 0+1+2+...+(N-1) = O(N²). But pop/top are always O(1).

### Space Complexity: O(N)

> **Drawback:** Push is O(N) due to rotation. If pushes are frequent, this is slow.

> **Key Insight for Improvement:** Alternative: make push O(1) and pop O(N). But push-heavy workloads favor O(N) push.

<br>

---

## Complexity Progression Summary

| Operation | Time |
|-----------|------|
| push | O(N) |
| pop | O(1) |
| top | O(1) |
| empty | O(1) |

**Key Insights:**
1. **Rotate after push:** Makes front = most recent (LIFO)
2. **Single queue suffices:** Don't actually need two queues with this approach
3. **Tradeoff:** O(N) push / O(1) pop, or O(1) push / O(N) pop

<br><br>

---

```code```
