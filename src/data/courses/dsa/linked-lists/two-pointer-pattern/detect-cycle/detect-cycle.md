Detect if a linked list has a cycle.

<br>

> Input: head = [3,2,0,-4], tail connects to node index 1
> Output: true
> **Key insight:** Floyd's cycle detection: slow moves 1 step, fast moves 2 steps. If they meet → cycle. If fast reaches null → no cycle.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution 1: Hash Set — O(N) time, O(N) space

> **Drawback:** O(N) extra space for the hash set.

> **Key Insight for Improvement:** Floyd's tortoise and hare: slow/fast pointers. If cycle exists, fast will eventually "lap" slow and they'll meet. O(1) space.

<br>

---

## Solution 2: Floyd's Cycle Detection (Optimal)

**Algorithm:** slow = fast = head. While fast and fast.next: slow += 1, fast += 2. If slow == fast → cycle.

### Time Complexity: O(N)
**Why?** Fast pointer traverses at most 2N nodes before meeting slow (if cycle) or reaching null.

**Detailed breakdown:** N = 10,000 → at most 20,000 pointer follows

### Space Complexity: O(1)

**Example walkthrough:**
```
3 → 2 → 0 → -4
    ↑           |
    └───────────┘

slow: 3→2→0→-4→2→0
fast: 3→0→2→-4→0→2
Meet at node 0 → cycle detected ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(N) | O(N) | Track visited nodes |
| Floyd's | O(N) | O(1) | Slow/fast pointers |

**Key Insights:**
1. **Speed difference = 1:** Fast gains 1 node per step → must eventually catch slow in a cycle
2. **No cycle → fast hits null:** Fast reaches end without meeting slow
3. **FAANG classic:** Foundation for cycle start, palindrome, happy number

<br><br>

---

```code```
