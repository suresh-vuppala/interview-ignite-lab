Find the nth node from the end of a linked list (don't remove — just return it).

<br>

> Input: head = [1,2,3,4,5], n=2
> Output: node with value 4
> **Key insight:** Same n-gap two-pointer technique. Fast leads by n. When fast reaches null, slow is at the nth from end.

<br>

---

## Constraints
- `1 ≤ n ≤ N`

<br>

---

## Solution: Two Pointers with N-Gap (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** Same technique as remove-nth-from-end but without deletion.

<br>

---

**Key Insights:**
1. **Gap = n:** Fast is n steps ahead → when fast hits null, slow is at position N-n+1 = nth from end
2. **No dummy needed:** Since we're just finding, not deleting

<br><br>

---

```code```
