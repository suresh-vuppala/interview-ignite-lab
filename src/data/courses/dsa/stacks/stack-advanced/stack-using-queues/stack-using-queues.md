Implement a stack using only queue operations (enqueue and dequeue).

Implement the MyStack class:
- `push(x)`: Push element x onto stack
- `pop()`: Remove and return the top element
- `top()`: Get the top element
- `empty()`: Return whether the stack is empty

<br>

> Input:
> Operations: ["push", 1], ["push", 2], ["top"], ["pop"], ["empty"]

> Output:
> [null, null, 2, 2, false]

> Explanation:
> - push(1): Queue = [1]
> - push(2): Rotate to front, Queue = [2, 1]
> - top(): Returns 2 (last pushed)
> - pop(): Returns 2, Queue = [1]
> - empty(): Returns false
> 
> **Key insight:** Use one queue and rotate elements during push to maintain LIFO order.

<br>


---

## Constraints

- `1 ≤ x ≤ 9`
- `At most 100 calls to push, pop, top, empty`
- `All calls to pop and top are valid`

<br>

---

## All Possible Edge Cases

1. **Single push then pop:** Returns the pushed element
2. **Multiple pushes then pops:** LIFO order verified
3. **Push after pop:** Stack resumes correctly
4. **empty() on empty stack:** Returns true
5. **top() returns without removing:** Subsequent pop still works

<br>

---

## Solution: Single Queue with Rotation

**Approach: Push O(n), Pop O(1)**
1. Use single queue
2. On `push(x)`:
   - Add x to queue
   - Rotate queue (size-1) times to move x to front
3. On `pop()`: Simply dequeue front
4. On `top()`: Return front element
5. On `empty()`: Check if queue is empty

**Key insight:** Queue is FIFO, stack is LIFO - rotate to reverse order.

```code```

<br>

### Time Complexity Analysis

**Push Operation: O(n)**
- Add element to queue: O(1)
- Rotate n-1 elements: O(n)
  - For each element: dequeue + enqueue = O(1)
  - Total: (n-1) × O(1) = O(n)

**Pop/Top/Empty: O(1)**
- Direct front access: O(1)
- No rotation needed

**Why rotation works?**
- Queue: [1, 2, 3] (front to back)
- Push 4: Add to back → [1, 2, 3, 4]
- Rotate 3 times: [2, 3, 4, 1] → [3, 4, 1, 2] → [4, 1, 2, 3]
- Now 4 is at front (LIFO order)

**Space Complexity: O(n)**
- Single queue holding n elements
- No additional data structures

**Alternative approach:**
- Push O(1), Pop O(n): Use two queues
- Trade-off: Which operation to optimize?
- Single queue approach is simpler

> **Time Complexity:** O(n) for push, O(1) for pop/top/empty
> **Space Complexity:** O(n) for queue

<br>
<br>

---
