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

## Solution: Slow/Fast Pointers (Optimal)

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
