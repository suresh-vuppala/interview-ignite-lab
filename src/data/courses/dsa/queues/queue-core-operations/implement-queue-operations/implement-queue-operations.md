Implement a queue supporting enqueue, dequeue, front, and isEmpty operations.

<br>

> enqueue(1), enqueue(2), front()→1, dequeue()→1, front()→2
>
> **Key insight:** FIFO: First In, First Out. Use circular array or linked list. Enqueue at rear, dequeue from front.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵ operations apply

<br>

---

## All Possible Edge Cases
1. **Dequeue from empty queue**
2. **Single element enqueue/dequeue**
3. **Alternating enqueue/dequeue**

<br>

---

## Solution 1: Linked List Queue

**Intuition:**
The most straightforward approach. Linked list has pointer overhead per node.

**Algorithm:**
1. Initialize queue with starting state
2. While queue not empty: dequeue, process, enqueue neighbors
3. Track visited states to avoid cycles
4. Return result when target state reached

### Time Complexity: O(1) per op
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linked list has pointer overhead per node. For fixed-size scenarios, circular array is more cache-friendly.

> **Key Insight for Improvement:**
> Circular array: front and rear pointers wrap around using modulo, avoiding element shifting.

<br>

---

## Solution 2: Circular Array Queue (Optimal)

**Intuition:** FIFO: First In, First Out. Use circular array or linked list. Enqueue at rear, dequeue from front.

**Algorithm:**
1. Use array of fixed capacity with front/rear indices
2. enqueue: arr[rear] = val, rear = (rear+1) % capacity
3. dequeue: val = arr[front], front = (front+1) % capacity
4. Track size to distinguish full from empty

### Time Complexity: O(1) per op
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
enqueue(1): rear=0→1, arr=[1,_,_]
enqueue(2): rear=1→2, arr=[1,2,_]
dequeue(): front=0→1, returns 1
front(): returns arr[1] = 2
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linked List Queue | O(1) per op | Varies | Baseline |
| Circular Array Queue | O(1) per op | O(N) | Circular array: front and rear pointers wrap around using mo |

**Recommended Solution:** Circular Array Queue — O(1) per op time, O(N) space.

**Key Insights:**
1. **FIFO principle:** Queue = line at a store — first person served first
2. **Circular avoids shifting:** Modulo wraps pointers instead of moving elements
3. **Applications:** BFS, task scheduling, buffering, printer queue

<br>
<br>

---

```code```
