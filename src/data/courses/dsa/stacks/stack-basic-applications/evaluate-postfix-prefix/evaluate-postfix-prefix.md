Evaluate postfix/prefix expression using stack.

<br>

---

## Solution 1: Stack (Standard)

**Algorithm (Postfix):**
1. For each token:
   - Number → push
   - Operator → pop two operands, compute, push result
2. Return stack top

### Time Complexity: O(n)
### Space Complexity: O(n)

This is the standard and only practical approach — already optimal.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(n) | O(n) | Standard stack-based evaluation |

<br>
<br>

---

```code```
