Find the middle of a linked list (duplicate of find-middle-node but in two-pointer section). Uses slow/fast pointer.

<br>

> Input: head = [1,2,3,4,5]
> Output: 3
> **Key insight:** Slow/fast pointers. Same as find-middle-node.

<br>

---

## Constraints
- `1 ≤ N ≤ 100`

<br>

---

## All Possible Edge Cases
1. **Odd length:** exact middle
2. **Even length:** second of two middles
3. **Single node**

<br>

---

## Solution 1: Count then traverse

**Intuition:**
The most straightforward approach — two passes: first to count length, second to reach middle.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) two-pass
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Two passes: first to count length, second to reach middle. Slow/fast does it in one pass.

> **Key Insight for Improvement:**
> Use Slow/Fast Pointers (Optimal) for O(N) time.

<br>

---

## Solution 2: Slow/Fast Pointers (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** For "first middle" (in even-length lists): use while fast.next and fast.next.next. For "second middle": use while fast and fast.next.

<br>

---

**Key Insights:**
1. **Two variants:** First middle vs second middle for even-length lists
2. **Condition determines which:** fast && fast.next → second middle, fast.next && fast.next.next → first middle

<br><br>

---

```code```
