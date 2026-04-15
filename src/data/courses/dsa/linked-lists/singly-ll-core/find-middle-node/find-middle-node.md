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

## All Possible Edge Cases
1. **Single node:** it is the middle
2. **Two nodes:** second is middle (or first)
3. **Even vs odd length**

<br>

---

## Solution 1: Count Then Traverse — O(N), Two Passes

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

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
