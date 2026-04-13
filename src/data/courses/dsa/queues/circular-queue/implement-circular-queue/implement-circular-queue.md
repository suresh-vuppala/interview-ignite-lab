Implement a circular queue with fixed capacity supporting enQueue, deQueue, Front, Rear, isEmpty, isFull.

<br>

> MyCircularQueue(3), enQueue(1)→true, enQueue(2)→true, enQueue(3)→true, enQueue(4)→false (full)
>
> **Key insight:** Circular array: front/rear wrap using modulo. Track count for full/empty distinction.

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

## Solution 1: Array with shifting

### Time Complexity: O(N) dequeue (shift elements)

> **Drawback:**
> Shifting elements on dequeue is O(N). Wastes time for every removal.

> **Key Insight for Improvement:**
> Circular indexing: rear = (rear+1) % k. No shifting needed. Both enqueue and dequeue are O(1).

<br>

---

## Solution 2: Circular Array (Optimal)

**Intuition:** Circular array: front/rear wrap using modulo. Track count for full/empty distinction.

**Algorithm:**
1. Array of size k, front=0, rear=-1, count=0
2. enQueue: if full return false. rear=(rear+1)%k, arr[rear]=val, count++
3. deQueue: if empty return false. front=(front+1)%k, count--
4. isFull: count==k. isEmpty: count==0

### Time Complexity: O(1) per op
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
capacity=3: enQueue(1)→[1,_,_] rear=0
enQueue(2)→[1,2,_] rear=1
enQueue(3)→[1,2,3] rear=2, count=3=full
deQueue()→[_,2,3] front=1, count=2
```

### Space Complexity: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array with shifting | O(N) dequeue (shift elements) | Varies | Baseline |
| Circular Array | O(1) per op | O(k) | Circular indexing: rear = (rear+1) % k. No shifting needed.  |

**Recommended Solution:** Circular Array — O(1) per op time, O(k) space.

**Key Insights:**
1. **Count vs sentinel:** Using count is cleaner than wasting one slot as sentinel
2. **Modulo wrapping:** (rear+1) % k handles the circular wrap
3. **Fixed memory:** No dynamic allocation — predictable performance

<br>
<br>

---

```code```
