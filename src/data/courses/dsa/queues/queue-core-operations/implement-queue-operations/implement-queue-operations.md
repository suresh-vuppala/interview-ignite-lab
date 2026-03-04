Implement a queue data structure with basic operations: enqueue (add to rear), dequeue (remove from front), peek (view front), and isEmpty.

<br>

> Input:
> Operations: ["enqueue", 5], ["enqueue", 10], ["dequeue"], ["peek"], ["enqueue", 15], ["dequeue"]

> Output:
> [null, null, 5, 10, null, 10]

> Explanation:
> Queue operations (FIFO - First In First Out):
> - enqueue(5): queue = [5]
> - enqueue(10): queue = [5, 10]
> - dequeue(): remove 5, return 5, queue = [10]
> - peek(): return 10 (front element), queue = [10]
> - enqueue(15): queue = [10, 15]
> - dequeue(): remove 10, return 10, queue = [15]

<br>

---

## Solution #1: Array-Based Queue

Use array with front and rear pointers:
1. **Enqueue**: Add element at rear, increment rear
2. **Dequeue**: Remove element at front, increment front
3. **Peek**: Return element at front
4. **isEmpty**: Check if front > rear

**Issue:** Array space not reused after dequeue (front moves forward).

```code```

<br>

### Time Complexity Analysis (Array-Based)

**All Operations: O(1)**
- Enqueue: Add at rear index, O(1)
- Dequeue: Remove at front index, O(1)
- Peek: Access front index, O(1)
- isEmpty: Compare front and rear, O(1)

**Space Complexity: O(n)**
- Array of size n to hold elements
- Wasted space as front moves forward
- Solution: Use circular queue

<br>
<br>

---

## Solution #2: Linked List-Based Queue

Use linked list with head (front) and tail (rear) pointers:
1. **Enqueue**: Add node at tail, update tail
2. **Dequeue**: Remove node at head, update head
3. **Peek**: Return head value
4. **isEmpty**: Check if head is null

**Advantage:** No wasted space, dynamic size.

```code```

<br>

### Time Complexity Analysis (Linked List)

**All Operations: O(1)**
- Enqueue: Add at tail, O(1) with tail pointer
- Dequeue: Remove at head, O(1)
- Peek: Access head, O(1)
- isEmpty: Check head null, O(1)

**Space Complexity: O(n)**
- n nodes for n elements
- Extra space for pointers (next, head, tail)
- No wasted space unlike array

**Comparison:**
- Array: Fixed size, wasted space, cache-friendly
- Linked List: Dynamic size, no waste, pointer overhead
- Circular Array: Best of both (covered in circular queue)

**Why FIFO?**
- Queue models real-world queues (line at store)
- First come, first served
- Used in BFS, task scheduling, buffering

> **Time Complexity:** O(1) - all operations constant time
> **Space Complexity:** O(n) - storage for n elements

<br>
<br>

---