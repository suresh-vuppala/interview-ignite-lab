Find the intersection node of two singly linked lists.

<br>

> Input: listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], intersection at node 8
> Output: node with value 8
> **Key insight:** Two pointers starting at each head. When one reaches end, redirect to other list's head. They meet at intersection (or both reach null if no intersection).

<br>

---

## Constraints
- `1 ≤ N, M ≤ 3 × 10⁴`

<br>

---

## Solution 1: Hash Set — O(N+M) time, O(N) space

> **Drawback:** O(N) extra space.

> **Key Insight for Improvement:** Two pointers: pA starts at headA, pB at headB. When pA reaches end → redirect to headB. When pB reaches end → redirect to headA. They'll meet at intersection after traversing N+M nodes each.

<br>

---

## Solution 2: Two Pointers — Length Equalization (Optimal)

### Time Complexity: O(N + M)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** Math: pA travels lenA + lenB, pB travels lenB + lenA. Both travel the same total distance → meet at intersection.

<br>

---

**Key Insights:**
1. **Redirect trick:** Equalizes the distance both pointers travel
2. **No intersection:** Both reach null simultaneously
3. **O(1) space:** No hash set needed

<br><br>

---

```code```
