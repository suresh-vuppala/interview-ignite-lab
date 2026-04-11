Find the intersection node of two linked lists.

<br>

---

## Solution 1: Hash Set — Store nodes of list A, check list B

### Time: O(n + m) | Space: O(n)

<br>

---

## Solution 2: Two Pointers (Optimal)

**Intuition:** Pointer A traverses A then B. Pointer B traverses B then A. They meet at intersection (or both reach null).

**Why?** Both travel distance (a + b) where a and b are the non-shared lengths.

### Time: O(n + m) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(n+m) | O(n) | Store and lookup |
| Two Pointers | O(n+m) | O(1) | Equalize path lengths |

<br>
<br>

---

```code```
