Reverse a singly linked list.

<br>

> Input: 1→2→3→4→5
> Output: 5→4→3→2→1

<br>

---

## Constraints

- `0 ≤ n ≤ 5000`
- `-5000 ≤ Node.val ≤ 5000`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Return null
2. **Single node:** Return itself
3. **Two nodes:** Simple swap

<br>

---

## Solution 1: Iterative (Three Pointers)

**Intuition:**
Walk through the list, flipping each node's `next` pointer to point backward.

**Algorithm:**
1. prev = null, curr = head
2. While curr != null:
   - next = curr.next (save next)
   - curr.next = prev (reverse link)
   - prev = curr (advance prev)
   - curr = next (advance curr)
3. Return prev (new head)

### Time Complexity: O(n) — single pass
### Space Complexity: O(1) — just pointer variables

<br>

---

## Solution 2: Recursive

**Intuition:**
Recurse to the end. On the way back, flip pointers.

**Algorithm:**
```
reverse(head):
    if head is null or head.next is null: return head
    newHead = reverse(head.next)
    head.next.next = head  // Flip the pointer
    head.next = null       // Break old forward link
    return newHead
```

### Time Complexity: O(n)
### Space Complexity: O(n) — recursion stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Iterative | O(n) | O(1) | Three pointers, single pass |
| Recursive | O(n) | O(n) | Clean but uses stack space |

**Recommended:** Iterative — O(1) space.

<br>
<br>

---

```code```
