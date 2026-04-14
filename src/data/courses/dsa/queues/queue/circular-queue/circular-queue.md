A **Circular Queue** is a linear data structure that follows FIFO (First In First Out) principle with efficient space utilization. Unlike a simple queue, it connects the end back to the beginning, forming a circle.

**Why Circular Queue?**
- Simple queue wastes space when front moves forward
- Circular queue reuses empty spaces
- Fixed size with optimal space usage

<br>

> Input:
> Operations: ["enqueue", 1], ["enqueue", 2], ["dequeue"], ["enqueue", 3], ["enqueue", 4]
> Queue size: 3

> Output:
> [true, true, 1, true, false]

> Explanation:
> - enqueue(1): queue = [1], front=0, rear=0
> - enqueue(2): queue = [1,2], front=0, rear=1
> - dequeue(): remove 1, queue = [_,2], front=1, rear=1
> - enqueue(3): queue = [_,2,3], front=1, rear=2
> - enqueue(4): queue full (size=3), return false
> 
> **Key insight:** Use modulo to wrap around array indices.

<br>


---

## Constraints

- `At most 10⁴ operations`
- `-10⁹ ≤ val ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Dequeue from empty queue:** Handle gracefully — return -1 or error
2. **Peek on empty queue:** Handle gracefully
3. **Single enqueue then dequeue:** Returns the enqueued value
4. **Queue full (if bounded):** Handle overflow
5. **Multiple enqueues then size check:** Size equals enqueue count minus dequeue count

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use Array with Modulo Arithmetic for O(N) time.

<br>

---

## Solution 2: Array with Modulo Arithmetic

Use array with front and rear pointers:
1. **Enqueue**: `rear = (rear + 1) % size`, add element
2. **Dequeue**: `front = (front + 1) % size`, remove element
3. **isFull**: `(rear + 1) % size == front`
4. **isEmpty**: `front == -1` or `front == rear` (after last dequeue)

**Key insight:** Modulo wraps indices to create circular behavior.



<br>

### Time Complexity Analysis

**All Operations: O(1)**
- Enqueue: Calculate index with modulo, add element → O(1)
- Dequeue: Calculate index with modulo, remove element → O(1)
- Peek: Access front index → O(1)
- isFull/isEmpty: Compare pointers → O(1)

**Why circular is better?**
- Simple queue: Wasted space as front moves
- Circular queue: Reuses space, no waste
- Example: Size 5, after 3 enqueue/dequeue, simple queue has 3 wasted slots

**Space Complexity: O(n)**
- Fixed array of size n
- No wasted space (all slots reusable)
- Two integer pointers (front, rear)

**Applications:**
- CPU scheduling (round-robin)
- Memory management
- Traffic systems
- Buffering (keyboard, printer)

> **Time Complexity:** O(1) for all operations
> **Space Complexity:** O(n) for fixed array

<br>
<br>

---

---

```code```
