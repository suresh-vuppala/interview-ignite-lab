Merge k sorted linked lists into one sorted list.

<br>

> Input: lists = [[1,4,5],[1,3,4],[2,6]]
> Output: [1,1,2,3,4,4,5,6]
> **Key insight:** Use a min-heap of size k. Push the head of each list. Extract min, append to result, push the next node from that list. O(N log k) total.

<br>

---

## Constraints
- `0 ≤ k ≤ 10⁴`, total nodes ≤ 10⁴

<br>

---

## Solution 1: Merge Pairs Iteratively — O(N × k)

> **Drawback:** k-1 merge passes. Each pass processes O(N) nodes. Total: O(N×k).

> **Key Insight for Improvement:** Min-heap of size k: always extract the global minimum in O(log k). Total: O(N log k) — much better when k is large.

<br>

---

## Solution 2: Min-Heap (Optimal)

**Algorithm:**
1. Push head of each non-empty list to min-heap
2. While heap not empty: extract min node, append to result, push its next (if exists)

### Time Complexity: O(N log k)
**Why?** N total nodes, each heap operation O(log k). Total: O(N log k).

**Detailed breakdown:** N=10,000, k=100 → 10,000 × 7 ≈ 70,000 heap operations

### Space Complexity: O(k) for heap

> **Drawback:** None.

> **Key Insight for Improvement:** Divide and conquer (merge pairs) also achieves O(N log k): log k levels, each processes N nodes.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Merge all into one | O(N×k) | O(1) | Sequential merge |
| Merge pairs (D&C) | O(N log k) | O(log k) | Halve k each round |
| Min-Heap | O(N log k) | O(k) | Always extract global min |

**Key Insights:**
1. **Heap maintains k candidates:** One from each list
2. **Extract min = O(log k):** Much better than scanning k heads
3. **FAANG hard:** Tests heap + linked list combination

<br><br>

---

```code```
