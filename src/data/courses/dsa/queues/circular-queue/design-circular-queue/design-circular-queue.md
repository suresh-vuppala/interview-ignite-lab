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

### Time Complexity: O(N) dequeue

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
