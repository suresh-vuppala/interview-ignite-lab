Reverse a singly linked list recursively.

<br>

> Input: head = [1,2,3,4,5]
> Output: [5,4,3,2,1]
> **Key insight:** Recurse to the end. On the way back, each node makes its next node point to itself, then sets its own next to null.

<br>

---

## Constraints
- `0 ≤ N ≤ 5000`

<br>

---

## All Possible Edge Cases
1. **Empty list**
2. **Single node**
3. **Very long list: stack overflow risk**

<br>

---

## Solution 1: Iterative with extra array

**Intuition:**
The most straightforward approach — copy values to array, reverse array, copy back.

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
> Copy values to array, reverse array, copy back. Two extra passes and O(N) space.

> **Key Insight for Improvement:**
> Use Recursive Reversal (Optimal for elegance) for O(N) time.

<br>

---

## Solution 2: Recursive Reversal (Optimal for elegance)

**Algorithm:**
1. Base case: if head is null or single node → return head
2. newHead = reverse(head.next) — recurse to end
3. head.next.next = head — make successor point back to me
4. head.next = null — break forward link
5. Return newHead (last node, propagated back)

### Time Complexity: O(N)
### Space Complexity: O(N) recursion stack

**Example walkthrough:**
```
reverse(1→2→3)
  reverse(2→3)
    reverse(3) → returns 3 (base case)
  3.next = null, but 2.next = 3
  head.next.next = head → 3→2
  head.next = null → 2→null
  return 3→2
head.next.next = head → 2→1
head.next = null → 1→null
return 3→2→1 ✓
```

> **Drawback:** O(N) stack space. Stack overflow risk for very long lists.

> **Key Insight for Improvement:** Iterative version uses O(1) space. But recursive version is more concise and demonstrates recursion mastery.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursive | O(N) | O(N) |
| Iterative | O(N) | O(1) |

**Key Insights:**
1. **head.next.next = head:** The key reversal step — successor now points to me
2. **head.next = null:** Break the old forward link
3. **newHead propagates back:** Last node becomes head, returned unchanged through all calls

<br><br>

---

```code```
