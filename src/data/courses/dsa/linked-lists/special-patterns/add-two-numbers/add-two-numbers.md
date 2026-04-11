Add two numbers represented as reverse-order linked lists.

<br>

---

## Solution 1: Simulate Addition

Traverse both lists simultaneously. Add digits + carry. Create new node for each sum.

### Time: O(max(m, n)) | Space: O(max(m, n))

This is the standard and only practical approach — already optimal.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Simulate Addition | O(max(m,n)) | O(max(m,n)) | Digit-by-digit with carry |

<br>
<br>

---

```code```
