Reverse a singly linked list iteratively.

<br>

> Input: head = [1,2,3,4,5]
> Output: [5,4,3,2,1]
> **Key insight:** Three pointers: prev, curr, next. For each node: save next, point curr to prev, advance prev and curr. At end, prev is new head.

<br>

---

## Constraints
- `0 ≤ N ≤ 5000`

<br>

---

## All Possible Edge Cases
1. **Empty list:** return null
2. **Single node:** same
3. **Already reversed (decreasing)**

<br>

---

## Solution 1: Create new reversed list

**Intuition:**
The most straightforward approach — build a new list by prepending each node.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Build a new list by prepending each node. Uses O(N) extra space unnecessarily.

> **Key Insight for Improvement:**
> Use Three-Pointer Iteration (Optimal) for O(N) time.

<br>

---

## Solution 2: Three-Pointer Iteration (Optimal)

**Algorithm:**
1. prev = null, curr = head
2. While curr: next = curr.next, curr.next = prev, prev = curr, curr = next
3. Return prev (new head)

### Time Complexity: O(N)
**Why?** Single pass through the list.

**Detailed breakdown:** N = 5000 → 5000 iterations

### Space Complexity: O(1)

**Example walkthrough:**
```
1 → 2 → 3 → null

prev=null, curr=1: next=2, 1→null, prev=1, curr=2
prev=1, curr=2: next=3, 2→1, prev=2, curr=3
prev=2, curr=3: next=null, 3→2, prev=3, curr=null

Result: 3 → 2 → 1 ✓
```

> **Drawback:** None — O(N) time, O(1) space is optimal.

> **Key Insight for Improvement:** Recursive version uses O(N) stack space but is more elegant. Iterative is preferred for interviews (no stack overflow risk).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Iterative | O(N) | O(1) | Three pointers |
| Recursive | O(N) | O(N) | Elegant but uses stack |

**Key Insights:**
1. **Three pointers:** prev, curr, next — the holy trinity of list reversal
2. **Save next before overwriting:** curr.next = prev destroys the forward link
3. **FAANG top-3:** Most frequently asked linked list problem

<br><br>

---

```code```
