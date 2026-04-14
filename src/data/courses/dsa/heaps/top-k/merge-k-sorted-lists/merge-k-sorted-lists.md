Merge K sorted linked lists into one sorted list.

<br>

> lists=[[1,4,5],[1,3,4],[2,6]] → [1,1,2,3,4,4,5,6]
>
> **Key insight:** Min-heap of size K. Push head of each list. Extract min, push its next. Heap always has one element per list.

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

## Solution 1: Merge pairs sequentially

**Intuition:**
The most straightforward approach. Merging all into one list sequentially does K-1 passes, each touching up to N elements.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N×K)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Merging all into one list sequentially does K-1 passes, each touching up to N elements.

> **Key Insight for Improvement:**
> Min-heap of K heads: always extract the global minimum in O(log K). Total: N extractions × O(log K) = O(N log K).

<br>

---

## Solution 2: Min-Heap Merge (Optimal)

**Intuition:** Min-heap of size K. Push head of each list. Extract min, push its next. Heap always has one element per list.

**Algorithm:**
1. Push head of each non-empty list into min-heap
2. While heap not empty:
   - Pop min node → append to result
   - If node.next exists → push to heap
3. Return result

### Time Complexity: O(N log K)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Heap: [(1,list0),(1,list1),(2,list2)]
Pop 1(list0)→push 4. Heap: [(1,list1),(2,list2),(4,list0)]
Pop 1(list1)→push 3. Result: [1,1,...] continues...
```

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Merge pairs sequentially | O(N×K) | Varies | Baseline |
| Min-Heap Merge | O(N log K) | O(K) | Min-heap of K heads: always extract the global minimum in O( |

**Recommended Solution:** Min-Heap Merge — O(N log K) time, O(K) space.

**Key Insights:**
1. **Heap maintains K candidates:** One from each list, always extract global min
2. **O(N log K) vs O(NK):** log K factor from heap vs K from sequential merge
3. **FAANG hard:** Combines heap + linked list — frequently asked

<br>
<br>

---

```code```
