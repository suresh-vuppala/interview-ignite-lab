A **Deque (Double-Ended Queue)** is a linear data structure that allows insertion and deletion at both ends (front and rear).

**Operations:**
- `addFront(x)`: Add element at front
- `addRear(x)`: Add element at rear
- `removeFront()`: Remove element from front
- `removeRear()`: Remove element from rear
- `getFront()`: Get front element
- `getRear()`: Get rear element

<br>

> Input:
> Operations: ["addRear", 5], ["addFront", 3], ["addRear", 7], ["removeFront"], ["removeRear"]

> Output:
> [null, null, null, 3, 7]

> Explanation:
> - addRear(5): deque = [5]
> - addFront(3): deque = [3, 5]
> - addRear(7): deque = [3, 5, 7]
> - removeFront(): remove 3, return 3, deque = [5, 7]
> - removeRear(): remove 7, return 7, deque = [5]
> 
> **Key insight:** Deque combines stack and queue operations.

<br>

---

## Solution: Circular Array or Doubly Linked List

**Approach 1: Circular Array**
- Use array with front and rear pointers
- Modulo arithmetic for circular behavior
- O(1) all operations

**Approach 2: Doubly Linked List**
- Each node has prev and next pointers
- Maintain head and tail pointers
- O(1) all operations

**Key insight:** Need bidirectional access for both ends.

```code```

<br>

### Time Complexity Analysis

**All Operations: O(1)**
- addFront: Add at front index/head → O(1)
- addRear: Add at rear index/tail → O(1)
- removeFront: Remove from front → O(1)
- removeRear: Remove from rear → O(1)
- getFront/getRear: Direct access → O(1)

**Why deque is powerful?**
- Can act as stack (use one end only)
- Can act as queue (use both ends FIFO)
- More flexible than stack or queue

**Space Complexity: O(n)**
- Array: Fixed size n
- Linked List: n nodes + pointers

**Applications:**
- Sliding window problems
- Browser history (forward/back)
- Undo/redo operations
- Task scheduling

**Comparison:**
- Stack: One end only (LIFO)
- Queue: Two ends, but restricted (FIFO)
- Deque: Two ends, fully flexible

> **Time Complexity:** O(1) for all operations
> **Space Complexity:** O(n) for storage

<br>
<br>

---
