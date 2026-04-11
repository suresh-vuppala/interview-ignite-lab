Add two integers without + or - operators.

<br>

---

## Solution 1: Bit Manipulation — XOR for sum without carry, AND + shift for carry

```
while b != 0:
    carry = a & b
    a = a ^ b
    b = carry << 1
```

### Time: O(32) = O(1) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| XOR + AND | O(1) | O(1) | Simulate binary addition |

<br>
<br>

---

```code```
