Find the middle node of a singly linked list. If two middle nodes, return the second one.

<br>

> Input: head = [1,2,3,4,5]
> Output: node with value 3
> **Key insight:** Slow/fast pointer technique. Slow moves 1 step, fast moves 2 steps. When fast reaches end, slow is at middle.

<br>

---

## Constraints
- `1 ≤ N ≤ 100`

<br>

---

## Solution 1: Count Then Traverse — O(N), Two Passes

> **Drawback:** Two passes: first to count, second to reach middle.

> **Key Insight for Improvement:** Slow/fast pointers achieve this in ONE pass. When fast reaches null or the last node, slow is at the middle.

<br>

---

## Solution 2: Slow/Fast Pointers (Optimal)

**Algorithm:** slow = fast = head. While fast and fast.next: slow = slow.next, fast = fast.next.next. Return slow.

### Time Complexity: O(N)
**Why?** Fast pointer traverses N nodes. Slow traverses N/2. Total: 3N/2 = O(N). But only ONE pass.

**Detailed breakdown:** N = 100 → 150 pointer follows

### Space Complexity: O(1)

**Example walkthrough:**
```
1 → 2 → 3 → 4 → 5

slow=1, fast=1
slow=2, fast=3
slow=3, fast=5 (fast.next=null → stop)

Middle = 3 ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Passes |
|----------|------|-------|--------|
| Count + traverse | O(N) | O(1) | 2 |
| Slow/Fast | O(N) | O(1) | 1 |

**Key Insights:**
1. **Slow/fast = tortoise/hare:** Fundamental linked list technique
2. **Fast moves 2×:** When fast finishes, slow is halfway
3. **Foundation for:** Cycle detection, palindrome check, merge sort on lists

<br><br>

---

```code```
