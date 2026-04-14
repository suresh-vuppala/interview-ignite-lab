Design a circular queue class with all standard operations.

<br>

> Same as implement-circular-queue with full OOP design
>
> **Key insight:** Same circular array technique. This is the LeetCode 622 version.

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

## Solution 1: Linear array

**Intuition:**
The most straightforward approach. Same shifting problem as basic queue.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(N) dequeue
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Same shifting problem as basic queue.

> **Key Insight for Improvement:**
> Circular array with modulo indexing — O(1) all operations.

<br>

---

## Solution 2: Circular Array OOP (Optimal)

**Intuition:** Same circular array technique. This is the LeetCode 622 version.

**Algorithm:**
Full class with constructor(k), enQueue(val), deQueue(), Front(), Rear(), isEmpty(), isFull()

### Time Complexity: O(1) per op
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Same as circular queue implementation — modulo wrapping
```

### Space Complexity: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear array | O(N) dequeue | Varies | Baseline |
| Circular Array OOP | O(1) per op | O(k) | Circular array with modulo indexing — O(1) all operations. |

**Recommended Solution:** Circular Array OOP — O(1) per op time, O(k) space.

**Key Insights:**
1. **OOP design:** Clean interface with capacity set at construction
2. **Thread safety:** For production, add mutex locks
3. **LeetCode 622:** Exact problem specification

<br>
<br>

---

```code```
