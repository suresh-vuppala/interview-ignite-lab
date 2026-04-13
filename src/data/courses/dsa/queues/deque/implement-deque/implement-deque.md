Implement a double-ended queue supporting push/pop from both front and back.

<br>

> pushFront(1), pushBack(2), popFront()→1, popBack()→2
>
> **Key insight:** Circular array with front moving backward and rear moving forward. Both ends are O(1).

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

## Solution 1: Linked List Deque

### Time Complexity: O(1) per op

> **Drawback:**
> Linked list works but has higher constant factor due to pointer overhead and cache misses.

> **Key Insight for Improvement:**
> Circular array: pushFront decrements front (wrapping), pushBack increments rear (wrapping). O(1) with better cache locality.

<br>

---

## Solution 2: Circular Array Deque (Optimal)

**Intuition:** Circular array with front moving backward and rear moving forward. Both ends are O(1).

**Algorithm:**
1. pushFront: front = (front-1+capacity) % capacity, arr[front] = val
2. pushBack: arr[rear] = val, rear = (rear+1) % capacity
3. popFront: front = (front+1) % capacity
4. popBack: rear = (rear-1+capacity) % capacity

### Time Complexity: O(1) per op
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
pushFront(1): front=cap-1, arr=[_,_,1]
pushBack(2): rear=0→1, arr=[2,_,1]
popFront(): front moves right → returns 1
popBack(): rear moves left → returns 2
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linked List Deque | O(1) per op | Varies | Baseline |
| Circular Array Deque | O(1) per op | O(N) | Circular array: pushFront decrements front (wrapping), pushB |

**Recommended Solution:** Circular Array Deque — O(1) per op time, O(N) space.

**Key Insights:**
1. **Bidirectional:** Both ends support O(1) push/pop
2. **Front goes backward:** (front-1+cap)%cap handles negative wrap
3. **Used in:** Sliding window problems, BFS optimizations, undo/redo

<br>
<br>

---

```code```
