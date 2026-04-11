Merge two sorted linked lists into one sorted list.

<br>

---

## Solution 1: Iterative with Dummy Node

Compare heads of both lists. Append smaller to result. Advance that pointer.

### Time: O(n + m) | Space: O(1) — reuse existing nodes

<br>

---

## Solution 2: Recursive

Base cases: if one is null, return the other. Compare heads, recurse on rest.

### Time: O(n + m) | Space: O(n + m) recursion stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Iterative | O(n+m) | O(1) | Dummy node simplifies edge cases |
| Recursive | O(n+m) | O(n+m) | Clean but uses stack space |

<br>
<br>

---

```code```
