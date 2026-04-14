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

## Solution 1: Count then traverse

**Intuition:**
The most straightforward approach — count length first, then traverse to n-length+1.

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
> Count length first, then traverse to N-length+1. Two-pointer gap technique does one pass.

> **Key Insight for Improvement:**
> Use Two Pointers with N-Gap (Optimal) for O(N) time.

<br>

---

## Solution 2: Two Pointers with N-Gap (Optimal)

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
