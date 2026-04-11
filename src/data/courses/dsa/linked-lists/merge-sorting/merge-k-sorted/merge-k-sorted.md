Merge k sorted linked lists.

<br>

---

## Solution 1: Merge One by One — Merge lists[0] with lists[1], result with lists[2], etc.

### Time: O(k × N) where N = total nodes | Space: O(1)

<br>

---

## Solution 2: Divide and Conquer — Pair up lists, merge pairs, repeat

### Time: O(N log k) | Space: O(log k) recursion

<br>

---

## Solution 3: Min-Heap (Optimal)

**Intuition:** Put heads of all k lists in min-heap. Pop smallest, append to result, push its next.

### Time: O(N log k) | Space: O(k) for heap

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sequential | O(kN) | O(1) | Merge one at a time |
| Divide & Conquer | O(N log k) | O(log k) | Merge pairs in tree fashion |
| Min-Heap | O(N log k) | O(k) | Always pick global minimum |

<br>
<br>

---

```code```
