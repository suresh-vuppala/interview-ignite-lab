Implement a circular queue with fixed capacity supporting enQueue, deQueue, Front, Rear, isEmpty, isFull.

<br>

> MyCircularQueue(3), enQueue(1)→true, enQueue(2)→true, enQueue(3)→true, enQueue(4)→false (full)
>
> **Key insight:** Circular array: front/rear wrap using modulo. Track count for full/empty distinction.

<br>

---

## Constraints
- 1 ≤ K ≤ 1000 (capacity)
- 0 ≤ value ≤ 1000 apply

<br>

---

## All Possible Edge Cases
1. **Enqueue when full:** return false
2. **Dequeue when empty:** return false
3. **Wrap around:** rear goes past capacity

<br>

---

## Solution 1: Array with shifting

**Intuition:**
The most straightforward approach. Shifting elements on dequeue is O(N).

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N) dequeue (shift elements)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

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
