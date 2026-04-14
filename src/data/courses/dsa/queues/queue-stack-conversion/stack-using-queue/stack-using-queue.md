Implement a LIFO stack using a single queue.

<br>

> push(1), push(2), top()→2, pop()→2
>
> **Key insight:** After pushing to queue, rotate all previous elements behind the new one. Front is always the most recent element (LIFO).

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Two queues alternating

**Intuition:**
The most straightforward approach. Using two queues adds unnecessary complexity.

**Algorithm:**
1. Initialize queue with starting state
2. While queue not empty: dequeue, process, enqueue neighbors
3. Track visited states to avoid cycles
4. Return result when target state reached

### Time Complexity: O(N) per push or pop
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Using two queues adds unnecessary complexity. One queue with rotation works.

> **Key Insight for Improvement:**
> Single queue: after push, rotate N-1 elements to back. Front = most recent = stack top.

<br>

---

## Solution 2: Single Queue Rotation (Optimal)

**Intuition:** After pushing to queue, rotate all previous elements behind the new one. Front is always the most recent element (LIFO).

**Algorithm:**
1. push(x): queue.add(x). For i=0 to size-2: queue.add(queue.remove()) — rotate old to back
2. pop(): queue.remove() — front is most recent
3. top(): queue.peek()
4. empty(): queue.isEmpty()

### Time Complexity: Push O(N), Pop O(1)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
push(1): q=[1]
push(2): q=[1,2] → rotate 1 → q=[2,1]
push(3): q=[2,1,3] → rotate 2 → q=[3,2,1]
pop(): returns 3 (front=most recent) ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two queues alternating | O(N) per push or pop | Varies | Baseline |
| Single Queue Rotation | Push O(N), Pop O(1) | O(N) | Single queue: after push, rotate N-1 elements to back. Front |

**Recommended Solution:** Single Queue Rotation — Push O(N), Pop O(1) time, O(N) space.

**Key Insights:**
1. **Rotate after push:** Brings new element to front (LIFO order)
2. **Push is O(N), pop is O(1):** Tradeoff opposite of queue-using-stacks
3. **Single queue suffices:** Rotation handles everything

<br>
<br>

---

```code```
