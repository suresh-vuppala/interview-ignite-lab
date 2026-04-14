Implement a FIFO queue using only two LIFO stacks.

<br>

> enqueue(1), enqueue(2), dequeue()→1, peek()→2
>
> **Key insight:** Two stacks: push stack and pop stack. Push to stack1. For pop: if stack2 empty, pour all from stack1 to stack2. Pop from stack2 — LIFO+LIFO=FIFO!

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

## Solution 1: Pour on every dequeue

**Intuition:**
The most straightforward approach. Pouring from stack1 to stack2 on every dequeue is wasteful if stack2 still has elements.

**Algorithm:**
1. Initialize queue with starting state
2. While queue not empty: dequeue, process, enqueue neighbors
3. Track visited states to avoid cycles
4. Return result when target state reached

### Time Complexity: O(N) per dequeue
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Pouring from stack1 to stack2 on every dequeue is wasteful if stack2 still has elements.

> **Key Insight for Improvement:**
> Lazy pour: only pour when stack2 is empty. Each element moves at most once from stack1→stack2. Amortized O(1) per operation.

<br>

---

## Solution 2: Two Stacks — Lazy Pour (Optimal)

**Intuition:** Two stacks: push stack and pop stack. Push to stack1. For pop: if stack2 empty, pour all from stack1 to stack2. Pop from stack2 — LIFO+LIFO=FIFO!

**Algorithm:**
1. enqueue(x): push to stack1 — O(1)
2. dequeue(): if stack2 empty → pour all stack1 into stack2. Pop from stack2.
3. peek(): same as dequeue but don't pop
4. empty(): both stacks empty

### Time Complexity: O(1) amortized
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
enqueue(1): s1=[1], s2=[]
enqueue(2): s1=[1,2], s2=[]
dequeue(): s2 empty → pour → s1=[], s2=[2,1]. Pop s2→returns 1
peek(): s2=[2] → returns 2
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Pour on every dequeue | O(N) per dequeue | Varies | Baseline |
| Two Stacks — Lazy Pour | O(1) amortized | O(N) | Lazy pour: only pour when stack2 is empty. Each element move |

**Recommended Solution:** Two Stacks — Lazy Pour — O(1) amortized time, O(N) space.

**Key Insights:**
1. **Amortized O(1):** Each element transferred stack1→stack2 exactly once
2. **LIFO + LIFO = FIFO:** Reversing twice = original order
3. **Lazy transfer:** Only pour when pop stack is empty

<br>
<br>

---

```code```
